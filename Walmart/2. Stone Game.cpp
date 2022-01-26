class Solution {
public:
    bool stoneGame(vector<int>& piles) {
       int odd_sum =0 ;
       int even_sum =0 ;
       int n = piles.size() ;
        for(int i=0;i<n;i++) {
            if(i&1){
                odd_sum += piles[i] ;
            }
            else {
                even_sum += piles[i] ;
            }
        }
        
        return (odd_sum != even_sum) ;
    }
};