class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size() ;
        sort(nums.begin(),nums.end(),cmp) ;
        return nums[n-k] ;
    }
    
    static bool cmp(string x , string y) {
        int X = x.size() ;
        int Y = y.size() ;
        if(X==Y)
            return x<y ;
        else
            return (X<Y) ;
    }
};