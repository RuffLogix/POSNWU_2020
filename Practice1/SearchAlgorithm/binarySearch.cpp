//O(logn)

#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 1;

    int l=0 , r=n-1;
    while(l<=r){
        if(l==r && x==arr[l]){
            cout << l;
            return 0;
        }else{
            int mid = (l+r)/2;

            if(arr[mid] >= x){
                r = mid;
            }else{
                l = mid+1;
            }
        }
    }
    
    cout << "-1";

    return 0;
}