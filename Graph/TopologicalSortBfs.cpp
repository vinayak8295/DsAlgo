#include <bits/stdc++.h>

using namespace std;

vector<int> toposort(vector<int> adj[], int n) {
      queue<int> q;
      vector<int> indegree(n,0);
      for(int i = 0;i<n;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
     for(int i = 0;i<n;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
     vector<int> topo;
     while (!q.empty())
     {
          auto node = q.front();
          q.pop();
          topo.push_back(node);
            for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }

     }
     return topo;
     
       
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


 vector<int> ans =  toposort(adj,n);
 for(auto x: ans){
     cout<<x<<" ";
 }
   
   
  return 0;
}
