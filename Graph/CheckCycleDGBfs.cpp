#include <bits/stdc++.h>

using namespace std;

bool toposort(vector<int> adj[], int n) {
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
     if(topo.size() == n){
         return 0;
     }
     else
     return 1;
     
       
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


bool ans =  toposort(adj,n);
  cout<<ans;
   
   
  return 0;
}
