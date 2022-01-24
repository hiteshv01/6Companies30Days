/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    
  Node * solve(vector<vector<int>>& grid , int rowstart , int rowend ,int colstart , int colend , int factor)
 
  {
      int sum = 0;  
      for(int i=rowstart ;  i <rowend ; i++)
      {
          for(int j = colstart ; j < colend ; j++) 
          {
              sum += grid[i][j] ;
          }
      }
      
      
      Node * dp ;
      
      if(sum ==0) 
          dp = new Node(false ,true) ;
      
      else if(sum == (factor * factor))
          
          dp = new Node(true , true) ;
      
      
      else 
      {
            dp = new Node(false,false);
            factor/=2 ;
          
            dp->topLeft = solve(grid,rowstart,rowstart+factor,colstart,colstart+factor,factor);
          
            dp->topRight = solve(grid,rowstart,rowstart+factor,colstart+factor,colend,factor);
          
            dp->bottomLeft = solve(grid,rowstart+factor,rowend,colstart,colstart+factor,factor);
          
            dp->bottomRight = solve(grid,rowstart+factor,rowend,colstart+factor,colend,factor);
      }
       return dp ;
  }
    
    
    
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size() ;
        if(n==0) return NULL ;
        Node* ans;
        ans = solve(grid,0,n,0,n,n) ;
        return ans;
    }
};