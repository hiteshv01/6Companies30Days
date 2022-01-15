// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > mat, int r, int c) 
    {
      // SDE sheet ka sawaal h 
      int top =0 , left =0 ;
      int bottom = r-1 ;
      int right = c-1 ;
      vector<int> vec ;
      
      // 4 cond 
      while(top <= bottom  && left <=right) 
      {
          
          // first 
          for(int i=left ; i<=right ; i++) {
              vec.push_back(mat[top][i]) ;
          }
              top ++ ;
          
          // second 
          for(int i=top ; i<= bottom ; i++) {
              vec.push_back(mat[i][right]) ;
          }
              right -- ;
          
          // third 
          if(top<=bottom) {
              for(int i = right ; i>= left; i--) {
                  vec.push_back(mat[bottom][i]) ;
              }
                  bottom -- ;
          }
          // forth
          if(left <=right) {
              for(int i=bottom ; i>=top; i-- ){
                  vec.push_back(mat[i][left]) ;
              }
                  left ++ ;
          }
          
      }
    
      return vec ;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends