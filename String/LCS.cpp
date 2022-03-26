#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solver(vector<vector<int>> &dp , int i , int j, string a ,string b)
{
    if(i==a.length() || j == b.length())
    return 0;

    if(dp[i][j]>=0)
    return dp[i][j];

    if(a[i]==b[j]){
        return dp[i][j] = 1 + solver(dp,i+1,j+1,a,b);
    }else{
        return dp[i][j] =  max(solver(dp,i+1,j,a,b),solver(dp,i,j+1,a,b));
    }

}

int main()
{
    string a = "abcde";
    string b = "ace";
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<solver(dp,0,0,a,b)<<endl;
    return 0;

}