#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);

    string a="ABCAAABC",b="ABCAACBC";
    int n=a.length(),m=b.length();

    int LCS[n+1][m+1];
    memset(LCS,0,sizeof(LCS));

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            if(a[i]!=b[j]){
                LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
            }else{
                LCS[i][j] = LCS[i-1][j-1]+1;
            }
        }
    }

    cout << LCS[n][m];
}