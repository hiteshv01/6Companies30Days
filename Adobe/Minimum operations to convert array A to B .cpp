// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minInsAndDel(int A[], int B[], int N, int M) 
    {
    
        vector<int> LIS ; // store the longest increasing subsequesnce in the (NLOGN) time 
          
        unordered_set<int> set;
        
        for(int i = 0 ; i < M; i++) {
            set.insert(B[i]);
        }
        
        for(int i = 0; i < N; i++)
        {
            if(set.find(A[i]) !=set.end())
            {
                auto x = lower_bound(LIS.begin(), LIS.end(), A[i]);
                
                if(x == LIS.end()) 
                // means A is in order of B ..therefore push_element at back
                {
                    LIS.push_back(A[i]);
                }
                else /// just replace with the element which is greater or equal to that element
                    *x = A[i];
            }
        }
        // lis is the longest vector of elemets in both the array 
        return (N+M- 2* LIS.size())   ;
    }
};
