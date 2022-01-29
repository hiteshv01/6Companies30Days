class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums)
    {
        sort(begin(sums),end(sums)) ;
        
        vector<int> ans ;
        
        while(n--)  {
            int d = sums[1] - sums[0] ;
            
            unordered_map<int,int> f ;
            
            vector<int> a,b  ; 
            // two subsets 
            bool ok = false ;
            for(auto & x : sums) 
        {        
                if(!f[x])
                {
                    a.push_back(x) ;
                    f[x+d] ++ ;
                    if(x==0)  ok = true ;
                }
                else 
                {
                    b.push_back(x) ;
                    f[x]-- ;
                }
        }
            
            if(ok==true) 
            {
                ans.push_back(d) ;
                sums = a ;
            }
            else 
            {
                ans.push_back(-d) ;
                sums =b ;
            }
        }
        
    
         return ans ;  
    }
};