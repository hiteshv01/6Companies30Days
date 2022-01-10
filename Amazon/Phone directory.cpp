

#include <bits/stdc++.h>
using namespace std;



class TrieNode
{
    public:

    TrieNode* child[26];
    char value;
    int ends, depth;

    TrieNode(char letter, int d) 
    {
        value = letter;
        ends = 0;
        depth = d;

        for(int i = 0; i < 26; ++i) {
            child[i] = NULL;
        }
    }
    
    
};

class Trie {
    public:

    TrieNode* root;

    Trie() {
        root = new TrieNode('/', 0);
    }

    void insert(string& word) {
        TrieNode* node = root;

        for(int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';

            if(node->child[index] == NULL)
                node->child[index] = new TrieNode(word[i], i + 1);

            node = node->child[index];
        }

        node->ends += 1;
    }
    
    
    
    vector<string> wordsWithPrefix(string prefix) {
        TrieNode* node = root;
        vector<string> results;
    
        int N = prefix.length();
        for(int i = 0; i < N; ++i) {
            node = node->child[prefix[i] - 'a'];
            if(node == NULL) return results;
        }
        TrieNode* prefix_end = node;

        stack<TrieNode*> nodes;
        nodes.push(node);
        string stream = "";
        
        while(!nodes.empty()) {
            node = nodes.top();
            nodes.pop();
        
            if(stream.size() > node->depth - prefix_end->depth) {
                stream = stream.substr(0, node->depth - prefix_end->depth);
            }
            
            stream += node->value;
            for(int i = 25; i >= 0; --i) {
                if(node->child[i] != NULL) {
                    nodes.push(node->child[i]);
                }
            }
            
            if(node->ends) {
                results.push_back(prefix + stream.substr(1));
            }
        }

        return results;
    }
};



class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
         Trie* dict = new Trie();
        for(int i = 0; i < n; ++i)
        {
            dict->insert(contact[i]);
        }

        vector<vector<string>> ans(s.size());
        
        for(int i = 0; i < s.size(); ++i) 
        {
            vector<string> res = dict->wordsWithPrefix(s.substr(0, i + 1));
            if(res.empty())
            {
                ans[i] = {"0"};
            }
            else {
                ans[i] = res;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends