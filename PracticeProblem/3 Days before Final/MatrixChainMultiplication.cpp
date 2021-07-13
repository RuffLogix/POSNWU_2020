#include <bits/stdc++.h>

using namespace std;

int dp[101][101];

int solve(int l,int r,int arr[]){
    if(l == r)return 0;

    if(dp[l][r]!=0)return dp[l][r];

    dp[l][r] = 0x3f3f3f3f;
    for(int i=l ; i<r ; i++){
        dp[l][r] = min(dp[l][r] , solve(l,i,arr) + solve(i+1,r,arr) + arr[l-1]*arr[r]*arr[i]);
    }

    return dp[l][r];
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int arr[] = {10 , 30 , 5 , 60};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << solve(1,n-1,arr);

    return 0;
}