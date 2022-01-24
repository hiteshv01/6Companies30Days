class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res ;
        vector<int> indegree(numCourses ,0) ;
        vector<vector<int>> graph(numCourses,vector<int>()) ;
   
        for (vector<int> &pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]] ++ ;
        }
    
      queue<int> q ;
      for(int i=0;i<indegree.size() ; i++) {
        if(indegree[i]==0) 
            q.push(i) ;
      }
      
      ///BFS KIND OF APPROACH 
      while(q.empty() == false) {
        auto u = q.front() ;
        q.pop() ;
        res.push_back(u) ;
        for(auto v : graph[u])
        {
          indegree[v] -- ;
          if(indegree[v] ==0) 
            q.push(v) ;
        }    
      }
        
        if(res.size() == numCourses) 
          return res ;
        else 
          return {} ;
      
    }
};