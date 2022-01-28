class Solution {
public:
    int dp[201][201] ;
    
    int f(int i,int j) 
    {
        if(i>=j){
            return 0 ;
        }
        if(dp[i][j]!= -1) 
            return dp[i][j] ;
        
        int ans = 100000;
        
        for(int k= i ; k<=j ; k++)
        {
            int cost = max(k+f(i,k-1) , k+ f(k+1,j)) ;
            ans = min(ans,cost) ;
        }
        return  dp[i][j] = ans ;
        
    }
    
    
    int getMoneyAmount(int n) 
    {
        memset(dp,-1,sizeof dp) ;
         
        return f(1,n) ;
    }
};