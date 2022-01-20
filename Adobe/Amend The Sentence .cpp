// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
       string a = "" ;
       a += tolower(s[0]) ;
       int i=1 ;
       while( s[i] != '\0') {
           if(isupper(s[i])) a += " " ;
           a += tolower(s[i]) ;
           i++ ;
       }
       return a  ;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends
