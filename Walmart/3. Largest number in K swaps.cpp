// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    
    /// backtrack problem 
    void solve(string str , int n , int k ,string & ans , int ind ) {
        
         if(k==0)   return ;
         
         char maxi = str[ind] ;
         
         for(int i  = ind + 1 ; i< n ; i++)
         {
             maxi = max(str[i],maxi) ;
         }
         
         if(maxi != str[ind]) 
         k-- ;
         
         for(int i=n-1 ; i>=0 ; i--)
         {
             if(maxi == str[i])
             {
                 swap(str[ind] , str[i]) ;
                 ans = max(ans,str) ;
                 
                 solve(str,n,k,ans,ind +1) ;
                 swap(str[ind] , str[i]) ;
             }
         }
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans  = str ;
       int n = str.length() ;
       solve(str,n,k,ans,0) ;
       return ans ;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends