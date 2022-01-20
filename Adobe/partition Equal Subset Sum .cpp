// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        sort(arr,arr+N) ;
        int sum  = accumulate(arr,arr+N , 0) ;
        if(sum & 1) return  0 ;
        int K = sum /2 ;
        vector<vector<int>> dp(N+1 , vector<int> (K+1,0)) ;
        for(int i=0;i<N ; i++) {
            for(int j = 1 ; j<= K ; ++j) {
             
             if(j< arr[i]) {
                 dp[i+1][j] = dp[i][j] ;
                 continue ; 
             }   
             
        dp[i+1][j] = max({arr[i] , dp[i][j] ,arr[i] + dp[i][j-arr[i]] } )  ;    
            }
        }
        
        
        
        return (K == dp.back().back()) ;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
