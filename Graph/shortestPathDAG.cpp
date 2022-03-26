#include <bits/stdc++.h>

using namespace std;

void toposort(vector < pair<int,int> > adj[], int n,stack<int> &s,int i,vector<int> &vis) {
    vis[i]=1;
    for(auto it : adj[i]){
         if(!vis[it.first]){
            toposort(adj, n,s,it.first,vis);
         }
    }
    s.push(i);
}

vector<int> shortest_path(vector < pair<int,int> > adj[], stack<int> &s , int n ,int src ){
    vector<int> ans(n,INT_MAX);
    ans[src] = 0;
    while (!s.empty())
    {
         auto node = s.top();
         s.pop();

         for (auto it : adj[node])
         {     
               if(ans[node] + it.second < ans[it.first] ){
                    ans[it.first] = ans[node]+it.second;
               }else
               if(ans[node] == INT_MAX)
                 break;
         }
         

    }
    

    return ans;
}


int main() {

  int n, m;
  cin >> n >> m;
  // declare the adjacent list 
  vector < pair<int,int> > adj[n + 1];

  // take edges as input 
  for (int i = 0; i < m; i++) {
    int u, v,wt;
    cin >> u >> v >>wt;
    adj[u].push_back({v,wt});
  }
  vector<int> vis(n,0);
  stack<int> s;

  for (int i = 0; i < n; i++)
  {
    if(!vis[i]){
         toposort(adj, n,s,i,vis);
    }
  }
  vector<int> ans = shortest_path(adj,s,n,0);

  for (int i = 0; i < n; i++)
  {
    cout<<ans[i]<<" ";
  }
  
   
   
  return 0;
}
