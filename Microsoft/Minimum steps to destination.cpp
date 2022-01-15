// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minSteps(int D , int pos =0 , int lastStep =0 ){
        // code here
        int steps = ((double)-1 + sqrt(1 + 8*D)) /(double) 2;
        
        int coverage = (steps * (steps + 1))/2;

        if(coverage == D)
            return steps;

        for(int i = 0; i < 3; ++i) {
            ++steps;
            coverage += steps;
            if(((coverage - D) & 1) == 0) 
            {
                return steps;
            }
        }
    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int D;
        cin>>D;
        
        Solution ob;
        cout<<ob.minSteps(D)<<"\n";
    }
    return 0;
}  // } Driver Code Ends