// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long prod=1;
        int ans=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            prod*=a[i];
            
            if(prod>=k)
            {
                while(j<i && prod>0)
                {
                    prod=prod/a[j];
                    
                    if(prod<k)
                    {
                        ans+=i-j;
                        j++;
                        break;
                    }
                    j++;
                }
            }else
                ans+=i-j+1;
            
        }
        
        return ans; 
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends