#include <bits/stdc++.h>

using namespace std;

bool is_valid = false;

void solve(int x,int n,int arr[],int all_sum,int sum){
    if(sum==all_sum)is_valid=true;

    if(is_valid || x==n || sum>>all_sum)return ;

    solve(x+1,n,arr,all_sum,sum+arr[x]);
    solve(x+1,n,arr,all_sum,sum);

}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin >> T;
    
    while(T--){
        is_valid = false;
        int n; cin >> n;
        int arr[n] , sum=0; 
        for(int i=0 ; i<n ; i++){cin >> arr[i];sum+=arr[i];}

        if((sum & 1)){
            cout << "NO\n";
        }else{
            solve(0,n,arr,sum/2,0);
            if(is_valid){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
        
    }

    return 0;
}