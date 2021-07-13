#include <bits/stdc++.h>

using namespace std;

int sq[2001][2001],tri[2001][2001],arr[2001][2001],rsq[2001][2001],rtri[2001][2001];

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int m,n,k; cin >> m >> n >> k;

    int mx=-0x3f3f3f3f;
    for(int i=1 ; i<=m ; i++){
        for(int j=1 ; j<=n ; j++){
            cin >> arr[i][j];
            sq[i][j] = sq[i-1][j] + sq[i][j-1] - sq[i-1][j-1]+arr[i][j];
            tri[i][j] = sq[i][j] - sq[i-1][j] + tri[i-1][j-1];
        }
    }

    for(int i=1 ; i<=m ; i++){
        for(int j=n ; j>=1 ; j--){
            rsq[i][j] = arr[i][j] - rsq[i-1][j+1] + rsq[i-1][j] + rsq[i][j+1];
            rtri[i][j] = rsq[i][j] - rsq[i-1][j] + rtri[i-1][j+1];
        }
    }


    for(int i=k ; i<=m ; i++) {
        for(int j=k ; j<=n ; j++){
            mx = max(mx , tri[i][j]-sq[i][j-k]-tri[i-k][j-k]+sq[i-k][j-k]);
            mx = max(mx , rtri[i][j-k+1]-rsq[i][j+1]-rtri[i-k][j+1]+rsq[i-k][j+1]);
        }
    }

    cout << mx;

    return 0;
}