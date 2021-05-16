#include <bits/stdc++.h>

using namespace std;

void AddEdge(pair<int,pair<int,int>> adj[],int a,int b,int w,int i){
    adj[i] = {w,{a,b}};
}

int f(int parent[],int key){
    if(parent[key]==-1 or parent[key]==key)return key;
    return parent[key] = f(parent,parent[key]);
}

void u(int parent[],int a,int b){
    a = f(parent,a);
    b = f(parent,b);

    if(a!=b){
        parent[a] = b;
    }
}

void kruskal(pair<int,pair<int,int>> adj[],int V,int E){
    int parent[V];
    memset(parent,-1,sizeof(parent));

    sort(adj,adj+E);

    int i=0,e=0;
    int dist_sum = 0;
    while(i<E and e<V-1){
        int a = f(parent,adj[i].second.first); //Find Algorithm;
        int b = f(parent,adj[i].second.second); //Find Algorithm;
        
        if(a!=b){
            u(parent,a,b);
            dist_sum += adj[i].first;
            e++;
        }

        i++;
    }

    cout << dist_sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int V = 9;
    int E = 14;
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

    kruskal(adj,V,E);
    return 0;
}


