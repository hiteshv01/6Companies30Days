class Solution {
public:
  string gcdOfStrings(string a, string b) 
  {
        return (a + b== b + a)  ? a.substr(0, gcd(a.length(), b.length())): "";
    }
};