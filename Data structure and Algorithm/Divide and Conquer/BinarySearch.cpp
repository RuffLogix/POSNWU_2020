#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    int arr[] = {1,2,3,4,5,6,7};
    int x=5;
    int n = sizeof(arr)/sizeof(arr[0]);

    int l=0,r=n-1;

    while(l<=r){
        if(l==r){
            cout << l << " ";
            break;
        }else{
            int m = (l+r)/2;
            if(arr[m]>=x){
                r=m;
            }else{
                l=m+1;
            }
        }
    }

    return 0;
}
