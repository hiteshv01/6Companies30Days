// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 5;

int missingNumber(const string& str);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        cout << missingNumber(str)<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* You are required to complete this function
which return the required missing number
if present else return -1*/
int missingNumber(const string& str)
{
    int len = str.size();
    int max_window = min(6, len/2);

    for(int w = 1; w <= max_window; ++w)
    {
        int last_num = 0 ;
        int num = 0;
        bool search  = true ;
        bool solved = false;
        int missing_number;

        for(int i = 0; i < w; ++i) 
        {
            last_num = last_num * 10 + str[i] - '0';
        }
        
        int window_size = (int) log10(last_num + 1) + 1;
        
        for(int d = w; d < len; d += window_size) 
        {
            window_size = (int) log10(last_num + 1) + 1;
            num = 0;
            for(int i = 0; i < window_size; ++i)
            {
                num = num * 10 + str[d + i] - '0';
            }
            
            if(num != last_num + 1 && (int)log10(last_num + 1) < (int)log10(last_num + 2)) 
            {
                num = 0;
                window_size = (int) log10(last_num + 2) + 1;
                for(int i = 0; i < window_size; ++i) 
                {
                    num = num * 10 + str[d + i] - '0';
                }
            }

            if(num == last_num + 2) 
            {
                if(search) {
                    search= false;
                    solved = true;
                    missing_number = last_num + 1;
                }
                else {
                    solved = false;
                    break;
                }
            }
            else if(num != last_num + 1) 
            {
                solved = false;
                break;
            }
            last_num = num;
        }
        
        if(solved) {
            return missing_number;
        }
    }
    
    return -1;
    // Code here
}