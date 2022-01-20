// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
  
  #define ll long long 
  #define mod (ll) (1e9 +7)
  
  
    int kvowelwords(int N, int K) {
        vector<vector<ll>> dp (N+1 , vector<ll> (K+1 , 0)) ;
        
        for(int i=0;i<=N ; i++)
        {
            for(int j= 0 ; j<=K ; ++j)
            {
                
                if(i==0) {  // initial condition 
                    dp[i][j] = 1 ;
                }
                else  {
                    dp[i][j] = (dp[i-1][K] * 21) % mod ;
                    
                    if(j>0) {
                        dp[i][j] = (dp[i][j] + dp[i-1][j-1] *5 % mod) % mod ;
                    }
                }
            }
        }
        return dp[N][K] ;
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
