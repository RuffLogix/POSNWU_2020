#include <bits/stdc++.h>

using namespace std;

int k,cnt=0;

void solve(int arr[],int n,int r,int x,int last){
    if(cnt>k)return;
    if(x==r){
        cnt++;
        if(cnt==k){
            for(int i=0 ; i<r ; i++)cout << arr[i] << " ";
            cout << "\n";
        }
    }else{
        for(int i=last+1 ; i<=n ; i++){
            arr[x]=i;
            solve(arr,n,r,x+1,i);
        }
    }
}

int main(){
    int n,r; cin >> n >> r >> k;

    vector<bool> visited(n+1,false);
    int arr[r];

    solve(arr,n,r,0,0);

    return 0;
}
