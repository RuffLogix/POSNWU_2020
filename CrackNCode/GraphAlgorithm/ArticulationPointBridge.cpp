#include <bits/stdc++.h>

using namespace std;

bool visited[500001],ArticulationPoint[500001];
int bfs_num[500001],bfs_low[500001],parent[500001];
int root , cnt=0 , child=0;


void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void findArticulationPointandBridge(vector<int> adj[],int u){
    bfs_num[u] = bfs_low[u] = cnt++;
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]){
            parent[v] = u;
            if(u==root)child++;

            findArticulationPointandBridge(adj,v);

            if(bfs_low[v] >= bfs_num[u])ArticulationPoint[u] = true;

            bfs_low[u] = min(bfs_low[u] , bfs_low[v]);
        }else if(parent[u] != v){
            bfs_low[u] = min(bfs_low[u], bfs_num[v]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int V , U; cin >> V >> U;
    vector<int> adj[V+1];


    for(int i=0 ; i<V ; i++){
        int u,v; cin >> u >> v;
        addEdge(adj,u,v);
    }

    for(auto u : adj[U]){
        if(!visited[u]){
            root = u, child = 0;
            findArticulationPointandBridge(adj,u);
            ArticulationPoint[u] = (child > 1);
        }
    }

    int ans = 0 , mx = 0;
    for(auto u : adj[U]){
        if(ArticulationPoint[u]){
            ++ans;
            cout << u << " ";
        }
    }

    return 0;
}
