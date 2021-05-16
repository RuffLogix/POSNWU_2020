#include <bits/stdc++.h>

using namespace std;

void solve(int nr,int dr){
    if(nr==0 || dr==0)return;
    if(nr%dr==0){
        printf("%d ",nr/dr);
        return;
    }
    if(dr%nr==0){
        printf("1/%d ",dr/nr);
        return;
    }

    if(nr>dr){
        printf("%d + ",nr/dr);
        solve(nr%dr,dr);
        return;
    }

    int n=dr/nr+1;
    if(dr>nr){
        printf("1/%d + ",n);
        solve(nr*n-dr,dr*n);
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    int nr=112312,dr=3001;
    solve(nr,dr);

    return 0;
}