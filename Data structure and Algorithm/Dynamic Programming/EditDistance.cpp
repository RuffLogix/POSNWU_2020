#include <bits/stdc++.h>

int main(){
    using namespace std;
    ios_base::sync_with_stdio(false),cin.tie(nullptr);

    string a="pqqrst",b="qqttps";
    int n=a.length(),m=b.length();

    int arr[n+1][m+1];
    arr[0][0] = 0;

    //set col
    for(int i=1 ; i<=n ; i++)arr[i][0] = i;
    //set row
    for(int i=1 ; i<=m ; i++)arr[0][i] = i;

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(a[i-1]==b[j-1])arr[i][j] = arr[i-1][j-1];
            else arr[i][j] = min(arr[i-1][j],min(arr[i][j-1],arr[i-1][j-1]))+1;
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}