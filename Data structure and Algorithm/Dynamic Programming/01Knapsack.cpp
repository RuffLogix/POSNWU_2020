#include <bits/stdc++.h>

using namespace std;

int main(){
    int value[] = {8,6,11,5};
    int weight[] = {10,15,8,5};
    int n = sizeof(value)/sizeof(value[0]);
    int W=20;

    int dp[n+1][W+1];
    memset(dp,0,sizeof(dp));

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=W ; j++){
            if(j-weight[i-1]>=0)dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i-1]]+value[i-1]);
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout << dp[n][W];
    return 0;
}