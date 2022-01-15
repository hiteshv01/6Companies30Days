// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        
      int n =arr.size() ;
      sort(begin(arr), end(arr)) ;
      vector<vector<int>> ans ;
      set<vector<int>> S ;
      
      for(int i=0; i<n; i++) {
         for(int j=i+1 ; j< n ; j++) {
             int start = j+1 ;
             int end  = n-1 ;
             while(start<end) 
             {
              int sum  = arr[i] +arr[j] + arr[start] + arr[end] ;
              if(sum==k)
              {
                 S.insert({arr[i],arr[j],arr[start],arr[end]}) ;
                 start ++ ;
                 end -- ;
               }
               else if(sum >k) {
                   end -- ;
               }
               else  {
                   start ++ ;
               }
               
             }
         }
      }
      
      
      for(auto x : S) {
          ans.push_back(x) ;
      }
      
      return ans ;
    
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends