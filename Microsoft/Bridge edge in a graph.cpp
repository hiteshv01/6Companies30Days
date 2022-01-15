// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	

	void dfs(int root , vector<int> & vis , vector<int> adj[] , int c , int d){
	    vis[root] = 1 ;
	    
	    
	    for(auto e : adj[root])
	    {
	        if((root == c and e==d) or (root==d and e==c))
	        {
	            continue ;
	        }
	        
	        if(!vis[e])
	        {
	            dfs(e,vis,adj,c,d) ;
	        }
	    }
	}
	
	
	
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int>vis  (V,0) ;
        
        dfs(c,vis,adj,c,d) ;
        if(!vis[d]) 
        return 1 ;
       else  
        return  0 ;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends