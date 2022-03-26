//https://www.interviewbit.com/problems/painters-partition-problem/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int isValid(vector < int > arr, int B, int n, int m, ll mid) {
   int student = 1;
   ll sum = 0;

   for (int i = 0; i < n; i++) {
      sum += arr[i];
      if (sum > mid) {
         student++;
         sum = arr[i];
      }

      if (student > m)
         return false;
   }

   return student <= m;
}

int paint(int m, int B, vector < int > & arr) {
   int n = arr.size();

   int maxi = -1;
   ll sum = 0;
   for (int i = 0; i < n; i++) {
      maxi = max(maxi, arr[i]);
      sum += arr[i];
   }
   ll low = maxi, high = sum * B;
   while (low < high) {
      ll mid = low + (high - low) / 2;

      if (isValid(arr, B, n, m, mid)) {
         high = mid;
      } else {
         low = mid + 1;
      }
   }

   return (high * B) % 10000003;
}
int main()
{
    int m=10;//numeber of painters
    int B=1;//time to paint a block
    vector<int> C;//array
    C.push_back(1);
    C.push_back(8);
    C.push_back(11);
    C.push_back(3);
    cout<<paint(m, B, C);
    return 0;
}
