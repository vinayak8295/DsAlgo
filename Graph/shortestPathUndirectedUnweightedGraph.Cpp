#include <bits/stdc++.h>

using namespace std;


void dfs(vector<int> adj[],int n , int src){
    int ans[n];
    for (int i = 0; i < n; i++)
    {
        ans[i] = INT_MAX;

    }

    queue<int> q;
    q.push(src);
    ans[src] = 0;
    while (!q.empty())
    {
         auto node = q.front();
         q.pop();

         for(auto it : adj[node]){
             if(ans[node]+1 < ans[it]){
                 ans[it] = ans[node]+1;
                 q.push(it);
             }
         }
         
    }

    for (int i = 0; i < n; i++)
    {
        cout<<ans[i]<<" ";
    }
    
    
    
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
   
   dfs(adj,n,0);
  return 0;
}
