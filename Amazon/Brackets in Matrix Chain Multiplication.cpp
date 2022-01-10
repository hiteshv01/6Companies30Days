
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string matrixChainOrder(int p[], int n)
    {
        
        
         vector<vector<pair<int,string>>> dp(n-1, vector<pair<int,string>>(n-1));

        for(int i = 0; i < n-1; ++i)
        {
            string M = "";
            M += (char) ('A' + i);
            dp[i][i] = {0,M} ;
        }
       
        for(int size = 1; size <= n; ++size) 
        {
            int l = 0;
            int m = size;
            while(m < n-1) 
            {
                dp[l][m].first = numeric_limits<int>::max();
                
                for(int i = l; i < m; ++i) 
                {
                    int operations = dp[l][i].first + dp[i+1][m].first + p[l]*p[i+1]*p[m+1];

                    if(dp[l][m].first > operations) 
                    {
                        dp[l][m].second = "(" + dp[l][i].second + dp[i+1][m].second + ")";
                        dp[l][m].first = operations;
                    }
                    
                }

                ++l;
                ++m;
            }
        }
        return dp[0].back().second ;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends