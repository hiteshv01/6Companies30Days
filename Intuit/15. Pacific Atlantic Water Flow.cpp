class Solution {
public:
    // ?? leetcode 417
    
    void solve(vector<vector<int>>& matrix , int i , int j , int prev ,
               vector<vector<int>>& ocean)
    {
       if(i<0 || i>= matrix.size() || j<0 || j>=matrix[0].size())
       {
           return  ;
       }   
        if(ocean[i][j] == 1) // no need for dfs
            return  ;
        if(matrix[i][j] < prev) // no need for dfs 
            return  ;
        
        ocean[i][j]=1 ;
        
        solve(matrix,i+1,j,matrix[i][j],ocean) ;
        solve(matrix,i-1,j,matrix[i][j],ocean) ;
        solve(matrix,i,j+1,matrix[i][j],ocean) ;
        solve(matrix,i,j-1,matrix[i][j],ocean) ;
              
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans  ;
        int n = matrix.size() , m = matrix[0].size();
        if(n<1) return ans ;
        
        
        vector<vector<int>> pacific(n, vector<int> (m,0)) ;
        vector<vector<int>> atlantic(n , vector<int>(m,0)) ;
        
        for(int col =0 ; col< m ; col++)
        {
            solve(matrix,0,col,INT_MIN , pacific) ;
            solve(matrix,n-1 , col, INT_MIN , atlantic) ;
        }
        
           
        for(int row =0 ; row< n; row++)
        {
            solve(matrix,row,0,INT_MIN ,pacific) ;
            solve(matrix,row, m -1, INT_MIN ,atlantic) ;
        }
        
        
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<m ;j++)
            {
               if(pacific[i][j]==1 && atlantic[i][j]==1) {
                   vector<int> v(2) ;
                   v[0]=i ;
                   v[1]=j ;
                   ans.push_back(v) ;
               } 
            }
        }
        
        return ans ;
    }
};