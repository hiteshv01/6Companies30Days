// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // two pointer approach problem 
        //left and right pointer  
      vector<int> vec(2,-1) ;
      long long  curr_sum  =0 ;
      int left =0 ;
      int right = 0 ;
      while(right < n) {
          if((curr_sum + arr[right]) == s) {
              vec[0] = left+1 ;
              vec[1] = right+1 ;
              break ;
          }
          else if((curr_sum + arr[right]) < s) {
               curr_sum += arr[right] ;
               right++ ;
          }
          else {
              curr_sum-= arr[left] ;
              left ++ ;
          }
          
      }
      if(vec[0]==-1  && vec[1]==-1) 
             vec.pop_back() ;
     
      return vec ;
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends