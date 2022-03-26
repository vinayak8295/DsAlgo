#include <bits/stdc++.h>

using namespace std;

void toposort(vector<int> adj[], int n,stack<int> &s,int i,vector<int> &vis) {
    vis[i]=1;
    for(auto it : adj[i]){
         if(!vis[it]){
            toposort(adj, n,s,it,vis);
         }
    }
    s.push(i);
}



int main() {

  int n, m;
  cin >> n >> m;
  // declare the adjacent list 
  vector < int > adj[n + 1];

  // take edges as input 
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }
  vector<int> vis(n,0);
  stack<int> s;
  for (int i = 0; i < n; i++)
  {
    if(!vis[i]){
         toposort(adj, n,s,i,vis);
    }
  }
  
    while(!s.empty()) {
	        cout<<s.top()<<" "; 
	        s.pop(); 
	    }

  
   
   
  return 0;
}
