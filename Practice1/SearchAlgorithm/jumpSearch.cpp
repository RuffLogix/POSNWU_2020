//O(sqrt(n))

#include <iostream>
#include <cmatH>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 0;
    int m = sqrt(n); //Jump Steps

    int idx = m;
    while(idx<n){
        if(arr[idx]>=x){
            for(int i=idx-m ; i<=idx ; i++){
                if(arr[i]==x){
                    cout << i;
                    return 0;
                }
            }
        }
        idx+=m;
    }

    for(int i=idx-m ; i<n ; i++){
        if(arr[i]==x){
            cout << i;
            return 0;
        }
    }

    cout << -1;

    return 0;
}