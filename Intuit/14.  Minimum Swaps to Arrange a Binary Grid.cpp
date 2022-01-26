class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) 
    {
         int n = grid.size() ; vector<int>arr(n);
        
        for(int i=0; i<n; i++)
        {
            int count = 0;
            for(int j=n-1; j>=0; j--)
            {
                if(grid[i][j] !=0)
                {
                    break;
                }
                count++;
            }
            arr[i] = count;
        }
        
        int swaps = 0;
        for(int i=0;i<n;i++)
        {   
            int req_trailing_zero = (n-1)-i ;
            
            if(arr[i] >= req_trailing_zero)
            {
                continue;
            }
            int val = arr[i] ;
            int j = i+1 ;
            while(j<n)
            {
                swap(val,arr[j]) ;  
                if(val >= req_trailing_zero)
                {
                    break;
                }
               j++ ;
            }
            
            if(j == n)
            {
                return -1;
            }
            swaps += (j-i) ; // for this window 
            arr[i] = val ;
        }
        
        return swaps ; 
    }
};