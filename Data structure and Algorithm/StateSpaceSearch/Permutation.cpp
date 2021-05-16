#include <bits/stdc++.h>

using namespace std;

int k,cnt=0;

void solve(int arr[],vector<bool> visited,int n,int r,int x){
    if(cnt>k)return;
    if(x==r){
        cnt++;
        if(cnt==k){
            for(int i=0 ; i<r ; i++)cout << arr[i] << " ";
            cout << "\n";
        }
    }else{
        for(int i=1 ; i<=n ; i++){
            if(!visited[i]){ //visited[i] = false;
                arr[x]=i;
                visited[i]=true;
                solve(arr,visited,n,r,x+1);
                visited[i]=false;
            }
        }
    }
}

int main(){
    int n,r; cin >> n >> r >> k;

    vector<bool> visited(n+1,false);
    int arr[r];

    solve(arr,visited,n,r,0);

    return 0;
}
