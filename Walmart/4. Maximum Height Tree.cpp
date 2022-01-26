// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int height(int N){
      int i =0 ;
      
      
      for( i=0 ; i< 1000 ; i++)
      {
        int val = (i*(i+1))/2 ;
        if(val > N) 
          break ;
      }
      
      return i-1 ;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.height(N)<<endl;
    }
    return 0;
}  // } Driver Code Ends