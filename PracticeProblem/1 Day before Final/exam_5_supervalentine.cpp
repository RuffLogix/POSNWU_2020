#include <bits/stdc++.h>

using namespace std;
#define Edge pair<int,pair<int,int>>

int f(int p[],int k){
    if(p[k]==k || p[k]==-1)return k;
    return p[k] = f(p,p[k]);
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int V,E; cin >> V >> E;

    Edge adj[E];
    for(int i=0 ; i<E ; i++){
        int a,b,w ; cin >> a >> b >> w;
        adj[i] = {w-1,{a-1,b-1}};
    }

    sort(adj,adj+E,[](Edge a,Edge b){
        return a.first > b.first;
    });

    int parent[V];
    memset(parent,-1,sizeof(parent));
    int i=0,e=0;
    long long int sum=0;
    while(i<V-1 && e<E){
        int a = f(parent,adj[e].second.first);
        int b = f(parent,adj[e].second.second);

        if(a!=b){
            parent[a] = b;
            sum+=adj[e].first;
            i++;
        }
        e++;
    }

    cout << sum;

    return 0;
}