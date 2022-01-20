//Given two library versions of an executable: for example, "10.1.1.3" and "10.1.1.9" or "10" and "10.1". Find out which one is more recent? Strings can be empty also.


#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<vector<int>> arr(n);

    for (int i = 0; i < n; ++i) 
    {
        string version;
        cin >> version;
        V[i].push_back(0);
        for(char c: version) 
        {
            if(c == '.') 
                arr[i].push_back(0);
            else
                arr[i].back() =  arr[i].back()*10 + (c-48) ;
        }
    }

    sort(arr.begin(), arr.end());

    bool dot = false;

    for(auto n: arr.back()) 
    {
        if(dot) cout << ".";
        cout << n;
        dot = true;
    }

    return 0;
}
