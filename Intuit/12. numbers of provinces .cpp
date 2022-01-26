class Solution {
public:
    
    
    void dfs(vector<vector<int>> & graph , int i) 
    {
        graph[i][i] =0 ; 
        for(int j=0 ; j<graph.size(); j++)
        {
            if(graph[i][j]==1) 
            {
                graph[i][j] =0 ; 
                if(graph[j][j] == 1) 
                {
                    dfs(graph,j) ;
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& graph) {
       // connected components in the graph 
        int n = graph.size() ;
        int cnt  =0 ;
        for(int i=0 ; i< n ; i++) {
            if(graph[i][i]==0) continue ;
                cnt ++ ;
            dfs(graph,i) ;
        }
        return cnt  ;
    }
};