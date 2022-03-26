#include <bits/stdc++.h>

using namespace std;

bool bipartiteDfs(int src, vector<int> adj[], vector<int> &color) {
        for(auto it : adj[src]) {
            if(color[it] == -1) {
                color[it] = 1 - color[src];
               if(!bipartiteDfs(it, adj, color)){
                   return false;
               } 
            } else if(color[it] == color[src]) {
                return false; 
            }
        }
    
    return true; 
}

bool bipar(vector<int> adj[], int n) {
    vector<int> color(n+1,-1);
    for(int i = 1;i<n+1;i++) {
        if(color[i] == -1) {
            color[i] = 1;
            if(!bipartiteDfs(i, adj, color)) {
                return false;
            }
        }
    }
    return true; 
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
    adj[v].push_back(u);
  }

 bool ans  = bipar(adj, n);
   cout<<ans<<endl;
  return 0;
}
