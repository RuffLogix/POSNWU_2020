#include <bits/stdc++.h>

using namespace std;

void AddEdge(vector<pair<int,int>> adj[],int a,int b,int w){
    adj[a].push_back({b,w});
}

void dijkstra(vector<pair<int,int>> adj[],int V,int src){
    vector<bool> visited(V,false);
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;
    vector<int> dist(V,0x3f3f3f3f);

    dist[src] = 0;
    q.push({0,src});
    visited[src] = true;

    while(!q.empty()){
        pair<int,int> qt = q.top(); q.pop();
        visited[qt.second] = true;
        for(auto x : adj[qt.second]){
            int u = qt.second , v = x.first , w = x.second;
            if(!visited[x.first]){
                if(dist[v]>dist[u]+w){
                    dist[v] = dist[u]+w;
                    q.push({dist[v],v});
                }
            }
        }
    }

    for(int i=0 ; i<V ; i++){
        if(i!=src)cout << src << " -> " << i << " : " << dist[i] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int V=5;
    int E=7;
    vector<pair<int,int>> adj[V];

    AddEdge(adj,0,2,1);
    AddEdge(adj,1,0,9);
    AddEdge(adj,1,2,2);
    AddEdge(adj,4,1,6);
    AddEdge(adj,4,2,15);
    AddEdge(adj,4,3,3);
    AddEdge(adj,2,3,1);

    dijkstra(adj,V,4);
    return 0;
}