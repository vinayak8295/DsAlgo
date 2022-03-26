#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int sortedpermu(string str){
    int n = str.length();
    long long fact[26];
    int arr[256]={};
    fact[0]=1;
    fact[1]=1;
    for (int i = 2; i < 26 ; i++)
    {
        fact[i]=i*fact[i-1];
    }
    for (int i = 0; i < n; i++)
    {
        arr[str[i]]++;
    }
    int smallerCharac;
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        smallerCharac=0;
        for (int j = 0; j < 256; j++)
        {
            if(j==str[i]){
              break;
            }
            if(arr[j]){
                smallerCharac++;
            }
        }
        arr[str[i]]=0;
        ans+=smallerCharac*fact[n-i-1];
        
    }
    return ans+1;
}

int main(){
      cout<<sortedpermu("bca")<<endl;
    return 0;



}