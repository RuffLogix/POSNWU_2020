#include <bits/stdc++.h>

using namespace std;

int X,Y;
string s[2001];
bool visited[2001][2001];

bool isValid(int x,int y){
    if(x<0 || y<0 || y>=Y || x>=X)return false;
    if(visited[x][y] || s[x][y]=='0')return false;
    return true;
}

void solve(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});

    visited[x][y] = true;

    int dir_x[] = {1,1,-1,-1,1,-1,0,0};
    int dir_y[] = {1,-1,1,-1,0,0,-1,1};

    while(!q.empty()){
        x = q.front().first , y = q.front().second; q.pop();
        for(int i=0 ; i<8 ; i++){
            if(isValid(x+dir_x[i],y+dir_y[i])){
                visited[x+dir_x[i]][y+dir_y[i]] = true;
                q.push({x+dir_x[i],y+dir_y[i]});
            }
        }
    }
}

int main(){
    cin >> X >> Y;

    for(int i=0 ; i<X ; i++){
        cin >> s[i];
    }

    int ans=0;
    for(int i=0 ; i<X ; i++){
        for(int j=0 ; j<Y ; j++){
            if(s[i][j]=='1' && !visited[i][j]){
                ans++;
                solve(i,j);
            }
        }
    }

    cout << ans;

    return 0;
}
/*
4 4 
0010 
1010 
0100 
1111

4 5 
10011 
00001 
01100 
10011
*/