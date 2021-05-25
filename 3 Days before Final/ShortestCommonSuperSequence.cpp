#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s1="ABCBDAB" , s2="BDCABA";
    int arr[s1.size()+1][s2.size()+1];

    for(int i=0 ; i<=s1.size() ; i++){
        for(int j=0 ; j<=s2.size() ; j++){
            if(i==0) arr[i][j] = j;
            else if(j==0) arr[i][j] = i;
            else if(s1[i-1]==s2[j-1]) arr[i][j] = arr[i-1][j-1] + 1;
            else arr[i][j] = min(arr[i-1][j],arr[i][j-1]) + 1 ;
        }
    }

    cout << arr[s1.size()][s2.size()];

    return 0;
}