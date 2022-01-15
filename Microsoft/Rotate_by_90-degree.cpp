// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& m)
{
    // Your code goes here
    int n = m.size() ;
    
    // transpose 
    for(int i=0; i<n ; i++)
    {
        for(int j = 0; j < i; j++)
        {
            swap(m[i][j] , m[j][i]) ;
        }
    }
    
    
    // reverse  the whole matrix at all 
   reverse(m.begin() , m.end()) ;
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

  // } Driver Code Ends