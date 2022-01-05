// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *result=new int(2);
        
        int xorr = 0 ;
        for (int  i=0 ; i < n ;  i++)
        {
            xorr^= arr[i] ;
        }
         for (int  i=1 ; i <= n ;  i++)
        {
            xorr^= i ;
        }
        int rsbm = xorr & -xorr ;
        int x= 0 , y =0 ;
        
        for (int i=0; i<n  ; i++)
        {
            if((arr[i] &rsbm)==0)
             x^=arr[i];
             else
             y^=arr[i] ;
        }
        for (int  i = 1 ; i <=n ; i++)
        {
            if((i &rsbm)==0)
             x^= i ;
             else
             y^= i ;
        }
        
        for ( int i = 0 ; i < n ;  i++)
        {
            if(arr[i] == x)
            {
                 result[0] = x ;
                 result[1] = y ;
                 
                 break ;
            }
            else if(arr[i] == y)
            {
                 result [0] = y ;
                 result[1] = x ;
                  break ;

            }
        }
        return result ;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends