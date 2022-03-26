#include <bits/stdc++.h>

using namespace std;

vector < int > bfs(int n, vector < int > adj[]) {
  vector < int > ans;
  vector < int > vis(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      queue < int > q;
      q.push(i);
      vis[i] = 1;
      while (!q.empty()) {
        auto temp = q.front();
        q.pop();
        ans.push_back(temp);
        for (auto x: adj[temp]) {
          if (!vis[x]) {
            q.push(x);
            vis[x] = 1;
          }
        }

      }
    }
  }

  return ans;
}
void dfs_utility(int node,vector<int> &vis, vector<int> adj[], vector<int> &ans){
    ans.push_back(node);
	vis[node] = 1;
	for (auto x :adj[node])
	{
		if(!vis[x]){
			dfs_utility(x,vis,adj,ans);
		}
	}
	
}
vector<int> dfs(int n, vector < int > adj[]){
	vector<int> ans;
    vector<int> vis(n+1,0);
	for (int i = 1; i <=n ; i++)
	{
	    if(!vis[i]){
			dfs_utility(i,vis,adj,ans);
		}
	}
	return ans;

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

  vector < int > ans;
  // bfs of a graph
//   ans = bfs(n, adj); 

  ans = dfs(n, adj);
  // print
  for (auto x: ans) {
    cout << x << " ";
  }
  return 0;
}