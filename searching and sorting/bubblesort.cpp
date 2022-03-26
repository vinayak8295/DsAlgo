#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    vector<int> ar;
    ar.push_back(6);
    ar.push_back(8);
    ar.push_back(1);
    ar.push_back(9);
    ar.push_back(10);
    ar.push_back(0);

    for(int i=0;i<ar.size()-1;i++){
        for(int j=0;j<ar.size()-i-1;j++){
                if(ar[j]>ar[j+1]){
                     swap(ar[j],ar[j+1]);
                }
        }
    }
    for (auto x:ar)
    {
        cout<<x<<" ";
    }
    
    return 0;

}

/*
bubble sort is inplace and it is stable
O(N^2) worst and avg
O(N) best
*/