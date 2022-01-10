// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int isValid(vector<vector<int>> mat)
    {
        int row[9][9]  = {0} ;
        int col[9][9]  = {0} ;
        int box[9][9]  = {0} ;
        
        
        
        for(int i=0;i<9;++i) {
            for(int j=0; j <9 ; ++j) {
                if(mat[i][j]!=0) 
                {
                    row[i][mat[i][j]-1] ++ ;
                    col[j][mat[i][j]-1] ++ ;
                    box[(i/3) * 3  + (j/3)][mat[i][j]-1] ++ ;
                    
            
            // imp cond check
if(row[i][mat[i][j]-1] > 1 or 
    col[j][mat[i][j]-1] >1 or box[(i/3) * 3  + (j/3)][mat[i][j]-1] > 1)
                    {
                        return false ;
                    }
                    
                }
            }
        }
        
        
        
        
        return true ;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends