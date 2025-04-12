#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>
#include <sstream>
#include <cmath>
#include <random>
#include <bitset>

using namespace std;

class Solution {
    public:
        vector<vector<int>> dp;
        int n;
        int longestPalindromeSubseq(string s) {
            n = s.size();
            dp = vector<vector<int>>(n,vector<int>(n,0));
            return find_long(s, 0, n-1);
        }

        int find_long(string &s, int l, int r){
            if(l == r)
                return 1;
            else if( l > r)
                return 0;
            if(dp[l][r])
                return dp[l][r];
            
            if(s[l] == s[r])
                dp[l][r] = find_long(s, l+1, r-1)+2;
            else if(find_long(s, l+1, r) > find_long(s, l, r-1))
                dp[l][r] = find_long(s, l+1, r);
            else 
                dp[l][r] = find_long(s, l, r-1);
            return dp[l][r];
        }
};

int main()
{
    string test = "xbaabcbaxab";
    Solution a;
    cout << a.longestPalindromeSubseq(test);
    return 0;
}