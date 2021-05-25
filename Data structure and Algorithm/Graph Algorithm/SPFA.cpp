#include <bits/stdc++.h>

using namespace std;

void AddEdge(vector<pair<int,int>> adj[],int a,int b,int w){
    adj[a].push_back({b,w});
    adj[b].push_back({a,w});
}

void SPFA(vector<pair<int,int>> adj[],int V,int src){
    vector<int> dist(V,0x3f3f3f3f);
    vector<int> cnt(V,0);
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;
    dist[src] = 0;
    q.push({0,src});

    bool negative_weight = false;
    while(!q.empty()){
        int w = q.top().first , u = q.top().second; q.pop();
        if(++cnt[u] > V-1){
            negative_weight = true;
            break;
        }

        for(auto x : adj[u]){
            if(dist[x.first] > dist[u]+x.second){
                dist[x.first] = dist[u]+x.second;
                q.push({dist[x.first],x.first});
            }
        }
    }
    
    if(negative_weight){
        cout << "Found Negative Weight Cycle.";
        return;
    }else {
        for(auto x : dist){
            cout << x << " ";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int V=9 , E=14;
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

    SPFA(adj,V,0);

    return 0;
}