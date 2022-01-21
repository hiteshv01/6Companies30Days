class Solution {
public:
  
  // BINARY SEARCH APPLICATION HERE IT IS 
  
  bool possible(int mid , vector<int> & piles , int H) {
    int total =0 ;
    int n = piles.size() ;
    for(int i=0; i< n ; i++) {
      int x = piles[i]/mid ;
      int y =piles[i] % mid ;
      if(y) { x ++ ; }
        total += x ;
      
    }
  
    return (total <=H) ;
  }
  
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1 ;
        int r = (int)(1e9+1) ;
        while(l<r) {
          int mid = l + (r-l)/2 ;
          if(possible(mid,piles,H)) 
              r = mid ;
          else
              l = mid+1 ;
        }
      return l ;
    }
};