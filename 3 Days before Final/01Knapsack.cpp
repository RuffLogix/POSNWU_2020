#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int value[] = { 350,400,450,20,70,8,5,5 };
    int weight[] = { 25,35,45,5,25,3,2,2 };
    int W = 104;

    int n = sizeof(weight)/sizeof(weight[0]);

    int arr[n+1][W+1];

    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=W ; j++){
            if(i==0 || j==0) arr[i][j] = 0;
            else if(weight[i-1]-j<=0) arr[i][j] = max(arr[i-1][j-weight[i-1]]+value[i-1] , arr[i-1][j]);
            else arr[i][j] = arr[i-1][j];
        }
    }

    cout << arr[n][W];

    return 0;
}