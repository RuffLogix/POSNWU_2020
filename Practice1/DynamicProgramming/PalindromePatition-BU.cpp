//Bottom Up Version.
#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];

int solve(string s,int n){
    memset(dp,0x3f3f3f3f,sizeof(dp));

    for(int i=0 ; i<n ; i++)dp[i][i] = 0;

    for(int k=1 ; k<n ; k++){
        for(int i=0 ; i<n-k ; i++){
            bool isPalindrome = true;

            for(int j=i ; j<i+k ; j++){
                if(s[j]!=s[i+k-(j-i)]){isPalindrome = false;break;}
            }

            if(isPalindrome){dp[i][i+k] = 0;continue;}

            for(int j=i ; j<i+k ; j++){
                dp[i][i+k] = min(dp[i][i+k] , 1 + dp[i][j] + dp[j+1][i+k]);
            }
        }
    }

    return dp[0][n-1];
}

int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);

    string s[] = {"geek" , "aaaa" , "abcde" , "abbac" , "ababbbabbababa" , "abcedfghijklmnopqrstuvwxyz"};
    int N=6,n;

    for(int i=0 ; i<N ; i++){
        n = s[i].length();
        cout << solve(s[i],n) << "\n";
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
