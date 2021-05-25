#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int m,n ; cin >> m >> n;

    int dp[m+1][n+1];
    memset(dp,0,sizeof(dp));
    int mx=0;
    for(int i=1 ; i<=m ; i++){
        for(int j=1 ; j<=n ; j++){
            int x ; cin >> x;
            if(x==1){
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
            }
            mx = max(mx,dp[i][j]);
        }
    }

    cout << mx;
    
    return 0;
}
/*
8 6
0 0 1 0 1 1
0 1 1 1 0 0
0 0 1 1 1 1
1 1 0 1 1 1
1 1 1 1 1 1
1 1 0 1 1 1
1 0 1 1 1 1
1 1 1 0 1 1
*/