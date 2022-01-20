// { Driver Code Starts

#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string,int> votes ;
        
        for(int i=0;i< n ; i++)
        {
            votes[arr[i]] ++ ;
        }
        
        
        unordered_map<int,vector<string>> rank ;
        
        int max_votes =0 ;
        
        for(auto cand : votes) 
        {
            if(cand.second >= max_votes)
            {
                max_votes = cand.second ;
                rank[max_votes].push_back(cand.first) ;
            }
        }
        sort( begin(rank[max_votes]) , end(rank[max_votes])) ;
        
        
        return {rank[max_votes][0] , to_string(max_votes)} ;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}
  // } Driver Code Ends
