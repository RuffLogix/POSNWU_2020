#include <bits/stdc++.h>

using namespace std;

unsigned long long int sum=0;

void solve(bool visited[],int x,int n){
    if(x>1 && visited[x-1] && visited[x-2]){sum+=1<<(n-x);return;}
    
    if(x==n)return;
    visited[x] = false;
    solve(visited,x+1,n);
    visited[x] = true;
    solve(visited,x+1,n);
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin >> n;

    bool visited[n];
    solve(visited,0,n);

    cout << sum;
    return 0;
}