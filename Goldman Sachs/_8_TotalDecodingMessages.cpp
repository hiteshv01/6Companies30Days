// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		     int N = str.size() ;
		    
		    long long dp[N+1] ;
		    dp[0] =1 ;
		    dp[1] =1 ;
		    if(str[0] == '0')
		      return 0 ;
		      
		   long long mod  = 1000000007 ;
		   for (int i=2 ; i<= N ; i++)
		   {
		       dp[i] =0 ;
		       if(str[i-1] > '0')
		         dp[i] = dp[i-1] ;
		       
		       int b =(str[i-2]-'0') * 10  + (str[i-1] - '0') ;
		      
		      if(b==0)
		             return  0 ;
		       
		       if( 10 <=b and  b<= 26)
		       {
		           dp[i] = (dp[i] %mod + dp[i-2] % mod) % mod ;
		           
		       }
		         
		   }
		   return (int) dp[N] ;
		    
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends