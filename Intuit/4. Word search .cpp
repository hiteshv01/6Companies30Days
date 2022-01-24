// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
 bool findWord(int i, int j, int index, vector<vector<char>>& board, 
               string& word, vector<vector<int>>& vis)
 {
        
        if(vis[i][j]) 
            return false;
        if(index == word.size())
              return true;
        
        vis[i][j] = 1;
        
        // up
        if(i > 0 && word[index] == board[i-1][j])
        {
            if(findWord(i-1, j, index + 1, board, word, vis)) {
                return true;
            }
        }
        
        // down
        if(i < board.size()-1 && word[index] == board[i+1][j]) {
            if(findWord(i+1, j, index + 1, board, word, vis)) {
                return true;
            }
        }
        
        // left
        if(j > 0 && word[index] == board[i][j-1])
        {
            if(findWord(i, j-1, index + 1, board, word, vis)) {
                return true;
            }
        }
        
        // right
        if(j < board[0].size()-1 && word[index] == board[i][j+1])
        {
            if(findWord(i, j+1, index + 1, board, word, vis)) {
                return true;
            }
        }
        
        vis[i][j] = 0;
        
        return false;
    }
    
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n =  board.size();
        int m = board[0].size();
        
        vector<vector<int>> vis (n, vector<int>(m, 0));

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(board[i][j] == word[0] &&  findWord(i, j, 1, board, word, vis)) {
                    return true ;
                }
                
            }
        }
        
        return false ;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends