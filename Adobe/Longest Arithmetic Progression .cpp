// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) 
    {
        int len = 2 ;
        // there will be two states in the dp table 
        // one is diff 
        // other is last element of the AP 
        if(n<=2) return n ;
        //
        vector<unordered_map<int,int>> dp(n) ;
    
        for(int i=0; i< n ; i++)
        {
            for(int j= i+1 ; j< n ; j++) 
            {
              int diff = A[j]  - A[i] ; 
              
              if(dp[i].find(diff) != dp[i].end())
              {
                dp[j][diff] = 1 + dp[i][diff] ;
              }
              else 
               {
                   dp[j][diff] = 2 ;
               }
            
              len  = max(len ,dp[j][diff]) ;
            }
        }
        
        return len ;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends