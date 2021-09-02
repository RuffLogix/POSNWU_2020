#include <bits/stdc++.h>

using namespace std;

vector<int> adj[26];
bool visited[26][26];
int n;
bool isAns = false;

void solve(int u,int cnt , string s){
    if(isAns)return;
    if(cnt==n){
        cout << s;
        isAns=true;
    }
    for(auto v : adj[u]){
        if(!visited[u][v] && !visited[v][u]){
            visited[u][v] = visited[v][u] = true;
            solve(v,cnt+1,s+" "+char(v+'A'));
            visited[u][v] = visited[v][u] = false;
        }
    }
}


int main(){
    cin >> n;

    for(int i=0 ; i<n ; i++){
        string s; cin >> s;
        adj[s[0]-'A'].push_back(s[1]-'A');
        adj[s[1]-'A'].push_back(s[0]-'A');
    }

    for(int i=0 ; i<26 ; i++){
        string s="";
        s+=char('A'+i);
        //cout << s << " ";
        solve(i,0,s);
        if(isAns)return 0;
    }

    return 0;
}