#include <bits/stdc++.h>

using namespace std;

int tree[10001];

void build(int arr[],int l,int r,int node){
    if(l==r){
        tree[node] = arr[r];
    }else{
        int m = (l+r)/2;

        build(arr,l,m,node*2);
        build(arr,m+1,r,node*2+1);

        tree[node] = tree[node*2]+tree[node*2+1];
    }
}

void update(int idx,int x,int l,int r,int node){
    if(l==r){
        tree[node] = x;
    }else{
        int m = (l+r)/2;

        if(l<=idx and idx<=r)update(idx,x,l,m,node*2);
        else update(idx,x,m+1,r,node*2+1);

        tree[node] = tree[node*2]+tree[node*2+1];
    }
}

int query(int a,int b,int l,int r,int node){
    if(a<l or r<b){ 
        return 0;
    }
    if(a<=l and r<=b){
        return tree[node];
    }

    int m = (l+r)/2;
    return query(a,b,l,m,node*2)+query(a,b,m+1,r,node*2+1);
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);

    int arr[] = {1,2,3,4,5,6};

    build(arr,0,5,1); //Build : O(n)

    cout << tree[1] << "\n";

    update(0,10,0,5,1); //Update : O(logn)

    cout << tree[1] << "\n";

    cout << query(0,2,0,5,1); //Query : O(logn)
}