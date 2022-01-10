// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
// Simple O(Log26(N)) solution
         string  ans ;
          while(n>0) {
            // to make the number 0 ondexed now 
            n-- ;
            int lastdig = n % 26 ;
            ans = string(1, lastdig + 'A') + ans ;
            n = n/26 ;
        }
        
        
        return ans ;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}
  // } Driver Code Ends