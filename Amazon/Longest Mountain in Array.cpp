class Solution {
public:
    int longestMountain(vector<int>& arr) {
       int n = arr.size() ;
       // peak dekh lo 
      int ans =0 ;
      for(int i=1 ; i< n-1 ;)
      {
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) // to check for peak element 
        {
          int cnt =1 ;
          int j=i ;
          // peak to one valley 
          while(j>0 and arr[j] > arr[j-1])
          {
            j-- ; cnt ++ ;
          }
          
          // peak to another valley 
          while(i < n-1 and arr[i] > arr[i+1])
          {
            i++ ; cnt ++ ;
          }
          ans  = max(cnt ,ans) ;  // to compute the max len of mountain 
        }
        else{
          i++ ;    // if not peak then incre i otherwise not 
        }
      }
      return ans  ;
    }
};