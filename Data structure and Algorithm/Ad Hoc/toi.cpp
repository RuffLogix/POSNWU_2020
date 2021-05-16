#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
vector<vector<int>> puzzle = {
    {15,2,1,12},
    {8,5,6,11},
    {4,9,10,7},
    {3,14,13,0}
};
int getCost(vector<vector<int>> v){
    int cost=0;
    for(int i=0 ; i<4 ; ++i){
        for(int j=0 ; j<4 ; ++j){
            if(v[i][j]-1==(i*4)+j){
                ++cost;
            }
        }
    }
    return cost;
}
void printPuzzle(vector<vector<int>> puzzle){
    //system("cls");
    //Sleep(100);
    for(int i=0 ; i<4 ; i++){
        for(int j=0 ; j<4 ; j++){
            cout << setw(3) << puzzle[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    priority_queue<pair<int,pair<vector<vector<int>>,pair<int,int>>>> q;
    q.push({getCost(puzzle),{puzzle,{3,3}}});
    while(!q.empty()){
        //printPuzzle(q.top().second.first);
        cout << "Q size : "<<  q.size() << "\n";
        for(int i=0 ; i<4 ; ++i){
            vector<vector<int>> tmp = q.top().second.first;
            pair<int,int> pos = q.top().second.second;
            if(i==0 && pos.first+1>=0 && pos.first+1<4){
                swap(tmp[pos.first][pos.second],tmp[pos.first+1][pos.second]);
                q.push({getCost(tmp),{tmp,{pos.first+1,pos.second}}});
                cout << "Cost : " << getCost(tmp) << '\n';
            }else if(i==2 && pos.first-1>=0 && pos.first-1<4){
                swap(tmp[pos.first][pos.second],tmp[pos.first-1][pos.second]);
                q.push({getCost(tmp),{tmp,{pos.first-1,pos.second}}});
                cout << "Cost : " << getCost(tmp) << '\n';
            }else if(i==1 && pos.second+1>=0 && pos.second+1<4){
                swap(tmp[pos.first][pos.second],tmp[pos.first][pos.second+1]);
                q.push({getCost(tmp),{tmp,{pos.first,pos.second+1}}});
                cout << "Cost : " << getCost(tmp) << '\n';
            }else if(i==3 && pos.second-1>=0 && pos.second-1<4){
                swap(tmp[pos.first][pos.second],tmp[pos.first][pos.second-1]);
                q.push({getCost(tmp),{tmp,{pos.first,pos.second-1}}});
                cout << "Cost : " << getCost(tmp) << '\n';
            }
        }
        q.pop();
    }
    return 0;
}
