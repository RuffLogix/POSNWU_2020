#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s = "ATACTCGGA";
    int arr[s.size()+1][s.size()+1];

    for(int i=0 ; i<=s.size() ; i++){
        for(int j=0 ; j<=s.size() ; j++){
            if(i==0 || j==0)arr[i][j] = 0;
            else if(s[i-1]==s[j-1] && i!=j)arr[i][j] = arr[i-1][j-1] + 1;
            else{
                arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
            }
        }
    }

    cout << arr[s.size()][s.size()];

    return 0;
}