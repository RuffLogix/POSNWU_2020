#include <bits/stdc++.h>

using namespace std;

int inDegree[] = {0,2,2,2,1,2,0};
int V=7,E=9;

void solve(vector<int> adj[]){
    queue<int> q;
    for(int i=0 ; i<V ; i++)if(inDegree[i]==0)q.push(i);

    vector<int> ans;
    while(!q.empty()){
        int u = q.front() ; q.pop();
        ans.push_back(u);
        for(auto x : adj[u]){
            if(--inDegree[x]==0){
                q.push(x);
            }
        }
    }

    if(ans.size()!=V)cout << ";-;";
    else{
        for(auto x : ans){
            cout << x << " ";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    vector<int> adj[V];

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[5].push_back(3);
    adj[5].push_back(4);
    adj[1].push_back(5);
    adj[6].push_back(1);
    adj[6].push_back(5);

    solve(adj);

    return 0; 
}