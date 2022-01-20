// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
     // there are only two possibility 
    // if we take a value then the next person can take the value from the same end
    // or from another end
    // so we just need to find the min value from both the ends taken 
    
    long long t[1000][1000];
    
    long long f(vector<int> &a,int n,int i,int j)
    {
        // if odd
        if(i==j)  return t[i][j]=a[i];
        
        // if even
        if(j==i+1) return t[i][j]=max(a[i],a[j]);
        
      
        // pecompute 
       if(t[i][j]!=-1)  return t[i][j];
       
        // inner value is taken min beacuse when
        //the oppent chance come it will try to leave min to min value for us
        return t[i][j]=max(a[i] + min(f(a,n,i+2, j), f(a,n,i+1, j-1) ),
                           a[j]+ min(f(a,n,i+1, j-1), f(a,n,i, j-2) )) ;
    }
    
    
    
    int maxCoins(vector<int>&A,int n)
    {
        memset(t,-1, sizeof t) ;
        
        return f(A,n,0,n-1) ;
	    
    }
};



// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends
