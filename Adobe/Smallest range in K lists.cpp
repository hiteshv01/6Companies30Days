// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
// function should print the required range


class Solution{
    typedef  pair<int,pair<int,int>>  ppi ;
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
          // create min heap
          // pq --> {val,{row,col}}
      priority_queue <ppi,vector<ppi>,greater<ppi>> pq;
      int maxi =0;
      for(int i=0; i<k; i++)
      {
          pq.push({arr[i][0],{i,0}});
          
          maxi =max(maxi , arr[i][0]);
      }
      
      // just initialse thr range and left and right values
      // {max-min,{max,min}}
      ppi minRange = { maxi -pq.top().first, { maxi,pq.top().first}};
      
      
      while(pq.size()==k)
      {
          ppi curr=pq.top();
          pq.pop();
          
          int curRow = curr.second.first;
          int curCol = curr.second.second;
         
          if(curCol+1 < n)
          {
              //push the ele
              pq.push({arr[curRow][curCol+1],{curRow,curCol+1}});
             
              //update m
               maxi =max(maxi ,arr[curRow][curCol+1]);
              
              //update minrange
              if(maxi -pq.top().first<minRange.first)
                    {
                        minRange={maxi -pq.top().first,{maxi,pq.top().first}};
                    }
               
          }
      }
     
      return {minRange.second.second, minRange.second.first};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends
