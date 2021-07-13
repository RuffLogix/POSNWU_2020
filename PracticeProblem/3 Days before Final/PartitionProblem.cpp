#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int S[] = {3, 1, 1, 2, 2, 1};
    int n = sizeof(S)/sizeof(S[0]);
    int sum=0;
    for(int i=0 ; i<n ; i++){
        sum+=S[i];
    }

    if(sum%2==1){
        cout << "We can't partition S";
    }else{
        bool arr[n][sum/2+1];
        memset(arr,false,sizeof(arr));

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<=sum/2 ; j++){
                if(j==0) arr[i][j] = true;
                else if(S[i]<=j) arr[i][j] = arr[i-1][j-S[i]];
                else {
                    arr[i][j] = arr[i-1][j];
                }
            }
        }

        if(arr[n-1][sum/2])cout << "We can partition S";
        else cout << "We can't partition S";
    }

    return 0;
}
