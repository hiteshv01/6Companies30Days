class Solution {
public:
    bool ispossible(vector<int>& weights, int days, int mid) {
        int d =1 ;
        int sum  =0 ;
        for(int i=0;i<weights.size() ; i++) {
             sum += weights[i] ;
              if(sum > mid) {
                  d ++ ;
                  sum = weights[i] ;
              }
        }
        return d<=days ;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
         int maxi =0 ;
        int sum =0 ;
        for(auto val : weights)
        {
            sum += val ;
            maxi = max(maxi , val) ;
        }
        int lo = maxi ;
        int hi = sum ;
        int ans ;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2 ;
            if(ispossible(weights,days,mid)==true) 
            {
                ans = mid ;
                hi = mid -1 ;
            }
            else {
                lo = mid +1 ;
            }
        }
        return ans ;
    }
};