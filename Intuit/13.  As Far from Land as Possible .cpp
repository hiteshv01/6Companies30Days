class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>>visited (n,vector<int>(n,0));
        
        queue<pair<int,int>> q ;
        // BFS approach 
        
        int water = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    visited[i][j] = 1;
                    q.push({i,j});
                }
                else{
                    water++;
                }
            }
        }
        
        if(q.size() == 0 or water == 0)
        {
            return -1;
        }
        
        vector<vector<int>>DIR  = {{0,1},{1,0},{0,-1},{-1,0}};
        
        int res  = -1;
        while(!q.empty())
        {
              
            int K = q.size();
            //cout<<sz<<endl;
            for(int i=0;i<K;i++)
            {
                
                auto p = q.front();
                q.pop();
                
                int r = p.first;
                int c = p.second;
                
                for(int j=0;j<4;j++)
                {
                    
                    int new_r = r + DIR[j][0];
                    int new_c = c + DIR[j][1];
                    
             if(new_r >= 0 && new_r < n && new_c >= 0 && new_c < n && !visited[new_r][new_c])
                {
                        q.push ({new_r,new_c});
                        visited[new_r][new_c] = 1;
                    }
                }
                
            }
            res++;
        }
        
        
        return res; 
    }
};