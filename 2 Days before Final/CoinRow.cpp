#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin >> n;
    
    int arr[n];
    for(int i=0 ; i<n ; i++) cin >> arr[i];
    int dp[n+1];
    memset(dp,0,sizeof(dp));

    for(int i=3 ; i<=n ; i++){
        dp[i] = max(dp[i-1],dp[i-3]+arr[i-1]);
    }

    cout << dp[n];
    return 0;
}