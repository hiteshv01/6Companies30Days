// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n)
	{
	    // align nuts and bolts
        for(int i = 0; i < n; ++i)
        {
            for(int j = i; j < n; ++j)
            {
                if(bolts[j] == nuts[i])
                {
                    char temp = bolts[i];
                    bolts[i] = bolts[j];
                    bolts[j] = temp;
                    continue;
                }
            }
        }
        
        // find original position in an array
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int i, int j) {
            return nuts[i] < bolts[j];
        });
        
        // place nuts and bolts on its original position
        for(int i = 0; i < n; ++i) {
            nuts[i] = bolts[order[i]];
        }
        for(int j = 0; j < n; ++j) {
            bolts[j] = nuts[j];
        }

	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends