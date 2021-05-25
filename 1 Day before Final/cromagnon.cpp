#include <bits/stdc++.h>

using namespace std;

int arr[21][21];
int n_arr[101];
int n,N; 

int solve(int x,int y){
    
    for(int k=x ; k<y ; k++){
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                if(arr[i][j])       
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cin >> arr[i][j];
        }
    }

    cin >> N;
    for(int i=0 ; i<N ; i++)cin >> n_arr[i];

    solve(0,N-1);

    return 0;
}