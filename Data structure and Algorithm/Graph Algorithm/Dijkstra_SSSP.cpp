#include <bits/stdc++.h>

using namespace std;

void AddEdge(vector<pair<int,int>> adj[],int a,int b,int w){
    adj[a].push_back({b,w});
    adj[b].push_back({a,w});
}

void dijkstra(vector<pair<int,int>> adj[],int V,int src){
    vector<bool> visited(V,false);
    vector<int> dist(V,1e9);

    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;

    dist[src] = 0;
    q.push({dist[src],src});

    while(not q.empty()){
        int u = q.top().second;
        q.pop();

        for(auto x : adj[u]){
            if(!visited[x.first]){
                if(dist[x.first] > dist[u]+x.second){
                    dist[x.first] = dist[u]+x.second;
                    q.push({x.second,x.first});
                }
            }
        }
    }

    for(int i=0 ; i<V ; i++){
        if(src!=i)cout << src << " -> " << i << " : " << dist[i] << "\n";
    }

}

int main(){

    int V=9;
    int E=14;
    vector<pair<int,int>> adj[V];

    AddEdge(adj,0,1,4);
    AddEdge(adj,0,7,8);
    AddEdge(adj,1,7,11);
    AddEdge(adj,1,2,8);
    AddEdge(adj,7,8,7);
    AddEdge(adj,7,6,1);
    AddEdge(adj,8,6,6);
    AddEdge(adj,2,8,2);
    AddEdge(adj,2,3,7);
    AddEdge(adj,2,5,4);
    AddEdge(adj,6,5,2);
    AddEdge(adj,3,5,14);
    AddEdge(adj,3,4,9);
    AddEdge(adj,5,4,10);

    dijkstra(adj,V,0); //src = 0;
}

