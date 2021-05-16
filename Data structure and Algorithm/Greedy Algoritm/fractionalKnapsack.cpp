#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    pair<float,float> arr[3] = {{60,10},{100,20},{120,30}};
    int n = sizeof(arr)/sizeof(arr[0]);
    int W=50;
    float sum=0;

    sort(arr,arr+n,[](pair<float,float> a,pair<float,float> b){
        return a.first/a.second > b.first/b.second;
    });

    for(int i=0  ; i<n ; i++){
        if(W<=0)break;
        if(W>=arr[i].second){
            W-=arr[i].second;
            sum+=arr[i].first;
        }else{
            sum+=arr[i].first/arr[i].second*W;
            W-=0;
        }
    }

    printf("%.2f",sum);


    return 0;
}