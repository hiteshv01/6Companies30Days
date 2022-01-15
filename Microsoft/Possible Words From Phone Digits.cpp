// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
         unordered_map<int, vector<string>> M ;
        M[2] = {"a", "b", "c"};  
        M[3] = {"d", "e", "f"};   
        M[4] = {"g", "h", "i"};   
        M[5] = {"j", "k", "l"};       
        M[6] = {"m", "n", "o"};
        M[7] = {"p", "q", "r", "s"};
        M[8] = {"t", "u", "v"};
        M[9] = {"w", "x", "y", "z"};
        
        vector<string> first =M[a[0]]  ;
        
        for(int i=1 ; i < N ; i++)
        {
            vector<string> second  = M[a[i]] ;
            vector<string>  res  ;
            
            for(auto i :first)
            {
                for(auto j : second){
                    res.push_back(i+j) ;
                }
            }
            first = res ;
        }
        return first ;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends