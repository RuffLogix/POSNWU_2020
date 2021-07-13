#include <bits/stdc++.h>

using namespace std;

int x,y;
int arr[2001][2001];

bool is_valid(int a,int b){
    if(a<0 || b<0 || a>=x || b>=y)return false;
    return true;
}

void solve(int a,int b){
    queue<pair<int,int>> q;
    q.push({a,b});

    int xx[] = {0,0,-1,1};
    int yy[] = {1,-1,0,0};
    char dir[] = {'R','L','U','D'};
    string ans = "";
    int ans_int = -1;
    while(!q.empty()){
        int a = q.front().first ; b = q.front().second; q.pop();

        for(int i=0 ; i<4 ; i++){
            if(is_valid(a+xx[i],b+yy[i])){
                if(arr[a+xx[i]][b+yy[i]]==arr[a][b]+1){
                    ans_int = arr[a+xx[i]][b+yy[i]];
                    q.push({a+xx[i],b+yy[i]});
                    ans+=dir[i];
                    break;
                }
            }
        }
    }

    cout << ans_int << "\n";
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin >> x >> y;

    pair<int,int> one;
    for(int i=0 ; i<x ; i++){
        for(int j=0 ; j<y ; j++){
            cin >> arr[i][j];
            if(arr[i][j]==1)one = {i,j};
        }
    }

    solve(one.first,one.second);

    return 0;
}