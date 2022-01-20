// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string num) { 
        //complete the function here
        int n= num.size();
        if (n <= 3) 
        {
        return "-1";
        }
    
        // find the index of last digit
        // in the 1st half of 'num'
        // -1 is done becuse it follow 0 based indexing
        int mid = n / 2 - 1;
        int i, j;
    
        // Start from the (mid-1)th digit and
        // find the first digit that is
        // smaller than the digit next to it.
        for (i = mid - 1; i >= 0; i--)
            if (num[i] < num[i + 1])
                break;
        
        // if i<0 then next no cannot be formed
        if (i < 0) {
           
            return "-1";
        }
    
        // Find the smallest digit on right
        // side of ith digit which is just greater 
        // than num[i] up to index 'mid'
        int smallest;
        
        for (j = mid; j >=0; j--)
        {
            if (num[j] > num[i])
            {
                smallest = j;
                break;
            }
                
        }
        
            
    
        // swap num[i] with num[smallest]
        swap(num[i], num[smallest]);
    

        // swapping the nos of second half also
        swap(num[n - i - 1], num[n - smallest - 1]);
    
        // reverse digits in the range (i+1) to mid
        reverse(num.begin()+i+1,num.begin()+mid+1);
    
        // reversing the second half
        // if n is even, then reverse digits in the
        // range mid+1 to n-i-2
        if (n % 2 == 0)
            reverse(num.begin()+mid+1,num.begin()+n-i-1);
        else// else if n is odd, then reverse digit in the range mid+2 to n-i-2
        reverse(num.begin()+mid+2,num.begin()+n-i-1);
    
        // required next higher palindromic number
        return num;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends
