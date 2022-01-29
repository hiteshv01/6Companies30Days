class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        
        vector<vector<pair<int,double>>> next(n) ;
        int N = edges.size() ;
        
        for(int i=0;i<N ; i++)
        {
            next[edges[i][0]].push_back({edges[i][1], succProb[i]});
            next[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        
        /// BFS approach 
        vector<double> prob(n) ;
        
        prob[start]=1 ;
        
        queue<int> q ;
        q.push(start) ;
        
        while(!q.empty())
        {
            int curr = q.front() ;
            q.pop() ;
              
            for(auto x : next[curr]) 
            {
                
                if(prob[x.first] >= prob[curr] * x.second)
                    continue ;
                
                prob[x.first] = prob[curr] * x.second ;
                
                q.push(x.first) ;
            }
        }
        
        
        return prob[end] ;
        
        
    }
};