#include <bits/stdc++.h>

using namespace std;

void BFS(int V,vector<int> adj[],int src){
    bool visited[V];
    memset(visited,false,sizeof(visited));
    queue<int> q;

    visited[src] = true;

    for(q.push(src); !q.empty() ; q.pop()){
        int u = q.front() ; 
        cout << u+1 << " ";
        for(auto v : adj[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int V,E,src; cin >> V >> E >> src; --src;
    vector<int> adj[V];
    for(int i=0 ; i<E ; i++){
        int u,v; cin >> u >> v; --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    BFS(V,adj,src);

    return 0;
}
/*
12 11 1
1 2
1 3
1 4
2 5
2 6
4 7
4 8
5 9
5 10
7 11
7 12
*/