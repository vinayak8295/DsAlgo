#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m; 
	// n is number of vertex and m is number of edges
	// declare the adjacent matrix 
	int adj[n+1][n+1]; 
	  for(int i = 0 ;i<n;i++){
        for (int j = 0; j < n; j++)
        {
            adj[i][j]=0;
        }
        
        
    }
	// take edges as input 
	for(int i = 0;i<m;i++) {
	    int u, v; 
	    cin >> u >> v;
	    adj[u][v] = 1; 
	    adj[v][u] = 1; 
	}
    //print
    for(int i = 0 ;i<n;i++){
        for (int j = 0; j < n; j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
        
    }
    // matrix to list
    vector<int> edges[n];
    for (int i = 0; i < n; i++)
    {
         
        for (int j = 0; j < n ; j++)
        {
            if (adj[i][j] == 1)
            {
                edges[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for ( auto x : edges[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    
	return 0;
}
