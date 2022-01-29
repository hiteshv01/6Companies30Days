class Solution {
public:
    #define pii pair<int,int>
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pii> v ;
        
        for(int i=0;i<n;i++)
        {
            v.push_back({efficiency[i], speed[i]}) ;
        }
        sort(begin(v) , end(v)) ;
        // minheap 
        priority_queue<int,vector<int>, greater<int>> pq ;
        long ans = 0 ;
        long sum = 0 ;
        
        for(int i=n-1 ; i>=0 ; i--) 
        {
            sum += v[i].second ;
            pq.push(v[i].second) ;
            
            if(pq.size()>k) 
            {
                sum  = sum - pq.top() ;
                pq.pop() ;
            }
            ans = max(ans, sum * v[i].first)  ;            
        }
        
        
        
        return ans % 1000000007 ;
    }
};