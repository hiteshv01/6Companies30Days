// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        vector<vector<int>> dp(K+1,vector<int> (N+1,0)) ;
        //
        for(int i=1 ;i<=K; i++) {
            for(int j= 1; j<=N ; j ++) {
                dp[i][j] = dp[i][j-1] ;
                for(int p =0 ; p<j ; p++) {
                    dp[i][j] = max(dp[i][j] , dp[i-1][p] + A[j-1] - A[p]) ;
                }
            }
        }
        
        return dp.back().back() ;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends