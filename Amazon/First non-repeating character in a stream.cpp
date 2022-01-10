// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
	public:
		string FirstNonRepeating(string A){
		 string s = "" ; 
		 // non repeating characters queue
        queue<char> q; 
        int n = A.length() ;
        
        vector<int> used(26, false);


        for(int i = 0; i < n ; ++i) {
            char c = A[i] , output;
            
            if(used[c - 'a'] < 1) 
            {
                q.push(c);
            }
            ++used[c - 'a'];

            while(!q.empty() and  used[q.front() - 'a'] > 1)
            {
                q.pop();
            }

            if(q.empty()) {
                output = '#';
            }
            else {
                output = q.front();
            }
            s += output;
        }
		    
	
		    return s ;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends