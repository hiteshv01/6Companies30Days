class Solution {
public:
    int divide(int x, int y) 
    {
       if (x == INT_MIN && y == -1) {
           return INT_MAX;
        }
        
        long dvd = labs(x) ;
        long dvs = labs(y) ;
        long ans = 0;
        long sign = (x > 0) ^ (y > 0) ? -1 : 1;
        
        while (dvd >= dvs) 
        {
            long temp = dvs ;
            long m = 1;
            while (temp << 1 <= dvd)
            {
                temp <<= 1;
                m <<= 1;
            }
            
            dvd -= temp;
            ans += m;
        }
        return sign * ans;  
    }
};