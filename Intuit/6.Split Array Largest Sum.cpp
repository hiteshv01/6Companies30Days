class Solution {
public:
    
    bool ispossible(vector<int>& nums, int m , int mid)
    {
        int sa_count =1 ;
        int sum  =0 ;
        for(int  i =0 ; i< nums.size() ; i++) 
        {
            sum += nums[i] ;     
            if(sum > mid)
            {
                sa_count ++ ;
                sum  = nums[i] ;
            }
        }
        
        return sa_count <= m ;
    }    
    
    int splitArray(vector<int>& nums, int m) {
        int maxi =0 ;
        int sum =0 ;
        for(auto val : nums) {
            sum += val ;
            maxi = max(maxi , val) ;
        }
        int lo = maxi ;
        int hi = sum ;
        int ans ;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2 ;
            if(ispossible(nums,m,mid)==true) {
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