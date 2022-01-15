// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int p[], int n)
    {
        if(n==1)
          return p[0] ;
        
        if(n==2)
           return max(p[0],p[1]) ;
           
         p[2] = max(p[1] , p[0] + p[2]) ; 
         
        for(int i=3 ; i<n ; i++)
        {
            p[i] = max( {p[i-1] , p[i-2] + p[i] , p[i-3] + p[i]} ) ;
        } 
        return p[n-1] ;
    
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends