#include <bits/stdc++.h>

using namespace std;

void AddEdge(pair<int,pair<int,int>> adj[],int a,int b,int w,int i){
    adj[i] = {w,{a,b}};
}

void bellman(pair<int,pair<int,int>> adj[],int V,int E,int src){
    vector<int> dist(V,1e9);
    dist[src] = 0;

    int count = 0;
    bool is_change = false;
    bool is_negative = false;
    do{
        is_change = false;
        count++;
        for(int i=0 ; i<E ; i++){
            int u=adj[i].second.first , v=adj[i].second.second , w=adj[i].first;
            if(dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                is_change = true;
            }
        }

        if(count>V-1 and is_change){
            is_negative = true;
            break;
        }
    }while(is_change);

    for(int i=0 ; i<V ; i++){
        if(i!=src)cout << src << " -> " << i << " : " << dist[i] << '\n';
    }
}

int main(){
    
    int V=9,E=14;
    pair<int,pair<int,int>> adj[E];

    AddEdge(adj,0,1,4,0);
    AddEdge(adj,0,7,8,1);
    AddEdge(adj,1,7,11,2);
    AddEdge(adj,1,2,8,3);
    AddEdge(adj,7,8,7,4);
    AddEdge(adj,7,6,1,5);
    AddEdge(adj,8,6,6,6);
    AddEdge(adj,2,8,2,7);
    AddEdge(adj,2,3,7,8);
    AddEdge(adj,2,5,4,9);
    AddEdge(adj,6,5,2,10);
    AddEdge(adj,3,5,14,11);
    AddEdge(adj,3,4,9,12);
    AddEdge(adj,5,4,10,13);

    bellman(adj,V,E,0); //src = 0
}

