// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string topologicalSort(char parent, unordered_map<char, vector<char>> &G, unordered_set<char> &visited) {
        if(visited.count(parent)) return "";

        visited.insert(parent);

        if(G.count(parent) == 0) return string(1, parent);

        string ans = "";
        for(auto child: G[parent]) {
            ans += topologicalSort(child, G, visited);
        }

        ans += parent;

        return ans;
    }

    string findOrder(string dict[], int N, int K) {

        unordered_map<char, vector<char>> G;

        // build graph
        for(int i = 1; i < N; ++i) {
            int j = 0;
            int limit = min(dict[i-1].size(), dict[i].size());

            while(j < limit && dict[i-1][j] == dict[i][j]) ++j;

            if(j < limit) G[dict[i-1][j]].push_back(dict[i][j]);
        }

        unordered_set<char> visited;
        string ans_rev = "";

        for(auto node: G) {
            if(visited.count(node.first)) continue;
            ans_rev += topologicalSort(node.first, G, visited);
        }

        reverse(ans_rev.begin(), ans_rev.end());

        return ans_rev;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends