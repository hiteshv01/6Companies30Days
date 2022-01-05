// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    long long squaresInChessBoard(long long N) {
       // Number of 1*1 squares = n*n
       // Number of 2*2 squares = (n-1)*(n-1)
       // ...
       // Number of n*n squares = 1*!
       // Total squares = Summation of(1*1+2*2+ ... +n*n)
        
        return N * (N + 1) * (2*N + 1) / 6 ;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.squaresInChessBoard(N) << endl;
    }
    return 0;
}  // } Driver Code Ends