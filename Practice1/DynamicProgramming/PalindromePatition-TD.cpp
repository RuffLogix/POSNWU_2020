//Top Down Version.
#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int solve(string s,int l,int r){
    if(l==r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    int isPalindrome = true;

    for(int i=l ; i<=r ; i++){
        if(s[i]!=s[r-(i-l)]){
            isPalindrome = false;
            break;
        }
    }

    if(isPalindrome)return dp[l][r] = 0;

    int mn = 0x3f3f3f3f;
    for(int i=l ; i<r ; i++){
        mn = min(mn , 1 + solve(s,l,i) + solve(s,i+1,r));
    }

    return dp[l][r] = mn;
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    string s[] = {"geek" , "aaaa" , "abcde" , "abbac" , "ababbbabbababa" , "abcedfghijklmnopqrstuvwxyz"};
    int N=6,n;

    for(int i=0 ; i<N ; i++){
        n = s[i].length();
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(s[i],0,n-1));
    }

    return 0;
}

/*
2
0
4
1
3
25
*/
