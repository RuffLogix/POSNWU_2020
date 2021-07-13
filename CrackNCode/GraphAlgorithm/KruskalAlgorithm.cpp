#include <bits/stdc++.h>

using namespace std;

int f(vector<int> p,int k){
    if(p[k]==k || p[k]==0)return k;
    return p[k] = f(p,p[k]);
}

int kruskal(pair<int,pair<int,int>> adj[], int V,int E){
    vector<int> parent(V,0);
    
    sort(adj,adj+E);

    int i=0,j=0;
    int ans=0;
    while(i<V-1 && j<E){
        int a = f(parent , adj[j].second.first);
        int b = f(parent , adj[j].second.second);

        if(a!=b){
            parent[a] = b;
            ans += adj[j].first;
            i++;
        }

        j++;
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int V,E; scanf("%d %d",&V,&E);
    pair<int,pair<int,int>> adj[E];

    for(int i=0 ; i<E-1 ; i++){
        int u,v,w; scanf("%d %d %d ",&u,&v,&w);
        adj[i] = {w,{u,v}};
    }

    printf("%d",kruskal(adj,V+1,E));

    return 0;
}

/*
7 7
1 2 4
2 3 6
3 1 3
4 5 1
5 6 2
6 7 3 
7 5 4
*/