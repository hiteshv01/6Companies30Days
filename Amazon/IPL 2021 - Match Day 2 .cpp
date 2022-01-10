// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
      vector<int> ans  ;
    
    
      // maxheap approach 
      priority_queue< pair <int,int>> mheap ;
     
     // push only first k element s in the heap 
      for(int i=0;i<k ; i++) {
          mheap.push({arr[i],i}) ;
      }
      
      ans.push_back(mheap.top().first) ;
      
      for(int i=k ; i< n ; ++i) {
          mheap.push({arr[i],i}) ;
          
          while(!mheap.empty() and mheap.top().second <=i-k) {
           mheap.pop() ;   
          }
          
          ans.push_back(mheap.top().first) ;
      }
      
      
      return ans ;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends