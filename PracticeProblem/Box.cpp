#include <bits/stdc++.h>

using namespace std;

class Node{
    public : 
        int mx_X,mx_Y,mn_X,mn_Y;
        Node(int mx_X,int mx_Y,int mn_X,int mn_Y){
            this->mx_X = mx_X;
            this->mx_Y = mx_Y;
            this->mn_X = mn_X;
            this->mn_Y = mn_Y;
        }
};

int M,N;
queue<Node> q;
string s[35];
bool visited[35][35];

bool is_valid(int a,int b){
    if(s[a+1][b]=='.' && s[a][b]=='.' && s[a][b+1]=='.' && s[a+1][b+1]=='.')return true;
    return false;
}

bool valid(int a,int b,int c,int d){
    if(a<0 || a>=M || c<0 || c>=M || b<0 || b>=N || d<0 || d>=N)return false;
    return true;
}

bool solve(){
    int xx[] = {1,-1,0,0};
    int yy[] = {0,0,-1,1};

    while(!q.empty()){
        int Nmx_X=q.front().mx_X , Nmn_X=q.front().mn_X , Nmx_Y=q.front().mx_Y , Nmn_Y=q.front().mn_Y; q.pop();
        if(Nmx_X == M-1)return true;

        for(int i=0 ; i<4 ; i++){
            if(valid(Nmx_X+xx[i],Nmx_Y+yy[i],Nmn_X+xx[i],Nmn_Y+yy[i]) && is_valid(Nmn_X+xx[i],Nmn_Y+yy[i]) && !visited[Nmn_X+xx[i]][Nmn_Y+yy[i]]){
                visited[Nmn_X+xx[i]][Nmn_Y+yy[i]] = true;
                q.push(Node(Nmx_X+xx[i],Nmx_Y+yy[i],Nmn_X+xx[i],Nmn_Y+yy[i]));
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin >> M >> N;

    for(int i=0 ; i<M ; i++){
        cin >> s[i];
    }

    for(int i=0 ; i<N-1 ; i++){
        if(s[0][i]=='.' && s[1][i]=='.' && s[0][i+1]=='.' && s[1][i+1]=='.'){
            visited[0][i] = true;
            q.push(Node(1,i+1,0,i));
        }
    }

    if(solve()){
        cout << "yes\n";
    }else{
        cout << "no\n";
    }
    return 0;
}
/*
7 14
##..##...#.#..
##..##...#.#..
##.####..#.#..
#...#....#####
..........###.
####...######.
...#..##..###.
*/