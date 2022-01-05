
#include math
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& A) 
    {
     int i = 0, n = A.size() ,summation = n + 1;
        for (int j = 0; j < n; ++j)
        {
            s -= A[j];
            while (s <= 0) 
            {
                summation  = min(summation ,j - i + 1);
                s += A[i++];
            }
        }
        return summation % (n + 1);
    }
};