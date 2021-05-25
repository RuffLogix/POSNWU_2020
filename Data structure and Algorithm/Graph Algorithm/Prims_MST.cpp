#include <bits/stdc++.h>

using namespace std;

void AddEdge(vector<pair<int,int>> adj[],int a,int b,int w){
    adj[a].push_back({b,w});
    adj[b].push_back({a,w});
}

int getKey(vector<bool> mstSet,vector<int> Key,int V){
    int idx=-1,mn=0x3f3f3f3f;
    for(int i=0 ; i<V ; i++){
        if(!mstSet[i] && mn>Key[i]){
            mn = Key[i];
            idx=i;
        }
    }
    return idx;
}

void prims(vector<pair<int,int>> adj[],int V){
    vector<bool> mstSet(V,false);
    vector<int> key(V,0x3f3f3f3f);

    int src=0,ans=0;
    key[src] = 0;

    for(int i=0 ; i<V ; i++){
        int s = getKey(mstSet,key,V);
        ans+=key[s];
        mstSet[s] = true;
        for(auto x : adj[s]){
            if(key[x.first] > x.second){
                key[x.first] = x.second;
            }
        }
    }

    cout << ans;
}

int main(){

    int V=9;
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

    prims(adj,V);

    return 0;
}
