#include <bits/stdc++.h>

using namespace std;

int V,E,s,t;

int solve(vector<pair<int,int>> adj[]){
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q;

    q.push({0,s});

    int cnt=0;
    while(!q.empty()){
        int u = q.top().second , W = q.top().first ; q.pop();

        if(u==t){
            if(++cnt==2){
                return W;
            }
        }

        for(auto x : adj[u]){
            int w = x.second , v = x.first;
            q.push({W+w,v});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    cin >> V >> E >> s >> t; 

    vector<pair<int,int>> adj[V+1];

    for(int i=0 ; i<E ; i++){
        int a,b,w; cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    cout << solve(adj);
    

    return 0;
}
/*
3 3
1 3
1 2 1
1 2 2 
2 3 1 
*/