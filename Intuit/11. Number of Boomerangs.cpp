class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& p)
    {
        map<int, int> f ;
        int ans = 0;
        int n = p.size() ;
        for(int i=0; i<n ; i++)
        {
            for(int j=0; j< n; j++)
            {
                if(i==j) 
                    continue;
                else 
                {
                  int dist= (p[i][0] -p[j][0]) *(p[i][0] - p[j][0]) + 
                            (p[i][1] - p[j][1])* (p[i][1] - p[j][1]) ;
                    f[dist]++;
                }
            }
            for(auto it : f)
            {
                ans += (it.second)*(it.second - 1);
            }
            f.clear();
        }
        
        return ans; 
    }
};