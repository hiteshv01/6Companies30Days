// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
   int count = 1; // globally declare ker do best 
   
   
   void dfs(int i, int j, vector<vector<int>> &grid)
   {
       int n = grid.size();
       int m = grid[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m)  return;
        
        if(grid[i][j] != 1) return;
        
        count++;
       
               grid[i][j]=0;
       
                dfs(i+1,j,grid);
                dfs(i,j+1,grid);
                dfs(i-1,j,grid);
                dfs(i,j-1,grid);
                dfs(i+1,j+1,grid);
                dfs(i+1,j-1,grid);
                dfs(i-1,j+1,grid);
                dfs(i-1,j-1,grid);
}
   
   int findMaxArea(vector<vector<int>>& grid)
   {
       int r = grid.size();
       int c = grid[0].size();
       int Max = 0;
       for(int i = 0; i < r ; ++i){
           for(int j = 0; j < c; ++j){
               count=0;
               if(grid[i][j] == 1){
                   dfs(i,j,grid);
                   Max = max(count, Max);
               }
           }
       }
       return Max;
   }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends