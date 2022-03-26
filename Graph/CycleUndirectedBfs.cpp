#include <bits/stdc++.h>

using namespace std;

bool check_cycle(int n,vector < int > adj[],vector <int> &vis,int i){

           queue<pair<int,int>>q;
           vis[i] = 1;
           q.push({i,-1});
           while (!q.empty())
           {
                int node = q.front().first;
                 int par = q.front().second;
                 q.pop();
                for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if (par != it)
                    return 1;
            }
            
           }
           return 0;
           

}

bool cycle(int n,vector < int > adj[] ){
    vector<int> vis(n+1,0);

    for (int i = 1; i < n+1; i++)
    {
         if(!vis[i]){
             if(check_cycle(n,adj,vis,i)){
                 return 1;
             }
             
         }
    }
    return 0;

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

 bool ans  = cycle(n, adj);
   cout<<ans<<endl;
  return 0;
}