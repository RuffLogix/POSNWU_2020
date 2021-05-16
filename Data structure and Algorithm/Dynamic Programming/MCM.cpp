#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int MCM(int arr[],int i,int j){
    if(i>=j)return 0;

    if(dp[i][j]!=-1)return dp[i][j];

    int mn=1e9;
    for(int k=i ; k<j ; k++){
        int tmp = MCM(arr,i,k)+MCM(arr,k+1,j)+arr[i-1]*arr[j]*arr[k];
        mn = min(mn,tmp);
    }

    return dp[i][j] = mn;
}

int main(){
    int arr[] = {40, 20, 30, 10, 30};
    memset(dp,-1,sizeof(dp));
    int n = sizeof(arr)/sizeof(arr[0]);

    MCM(arr,1,n-1);
    cout << dp[1][n-1];
    return 0;
}