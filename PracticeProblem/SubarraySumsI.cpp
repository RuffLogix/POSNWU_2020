#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,k ; cin >> n >> k;
    int arr[n];
    for(int i=0 ; i<n ; i++)cin >> arr[i];

    int dp[n+1][k+1];
    sort(arr,arr+n);
    memset(dp,0,sizeof(dp));
    for(int i=1 ; i<=n ; i++){
        for(int j=0 ; j<=k ; j++){
            if(j==0 || i==0) dp[i][j] = 0;
            else if(arr[i-1]==j)dp[i][j] = dp[i-1][j]+1;
            else if(arr[i-1]<j){
                dp[i][j] = dp[i-1][j-arr[i-1]]+dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
            cout << dp[i][j] << " ";
        } 
        cout << "\n";
    }

    cout << dp[n][k];

    return 0;
}