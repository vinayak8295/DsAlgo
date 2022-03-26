#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m; 
	// n is number of vertex and m is number of edges
	// declare the adjacent matrix 
	int adj[n+1][n+1]; 
	  for(int i = 0 ;i<n+1;i++){
        for (int j = 0; j < m+1; j++)
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
    // for(int i = 1 ;i<n+1;i++){
    //     for (int j = 1; j < m+1; j++)
    //     {
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
        
    // }
	return 0;
}
