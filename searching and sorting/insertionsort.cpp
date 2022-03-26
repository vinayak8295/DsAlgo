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

    for(int i=1;i<ar.size();i++){
          int key = ar[i];
          int j = i-1;

          while(j>=0 and ar[j]>key){
              ar[j+1] = ar[j];
              j = j-1;
          }      
          ar[j+1] = key;
        }
    
    for (auto x:ar)
    {
        cout<<x<<" ";
    }
    
    return 0;

}

/*
it is stable and its in place
O(N^2)
Insertion sort is used when number of elements is small. 
It can also be useful when input array is almost sorted, only few elements are misplaced
in complete big array.
*/