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
    string a = "123";
    string b = "456";
    int n = a.size();
    int m = b.size();
    vector<int> dp(n+m,0);
    int remainder = 0;
    int carry = 0;

    for(int i = n-1;i>=0;i--){
        for (int j = m-1; j>=0; j--)
        {
             int mult = (a[i]-'0')*(b[j]-'0');
             int sum = mult + dp[i+j+1];
             carry = sum/10;
             dp[i+j] += carry;
             dp[i+j+1] = sum%10;
        }
        

    }
     string s="";
        for(int i=0;i<dp.size();i++)
            s+=(dp[i]+'0');
        if(s[0]=='0'){
            cout<<s.substr(1, m+n);
        return 0;
        }
        cout<<s;

        return 0;

}