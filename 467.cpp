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
#define MYNEXT(x) (x == 'z'?'a':x+1)
        vector<int> dp = vector<int>(26,0);
        int findSubstringInWraproundString(string s) {
            int n = s.size();
            int result = 1;
            if(n <= 1)
                return n;
            int start = 1;
            char pre = s[0];
            dp[s[0] - 'a'] = 1;
            for(int i = 1; i < n;i++){
                if(MYNEXT(pre) != s[i]){
                    start = 1;
                }else{
                    start++;
                }
                if(start > dp[s[i] - 'a']){
                    result += (start-dp[s[i] - 'a']);
                    dp[s[i] - 'a'] = start;
                }
                pre = s[i];
            }


            return result; 
        }
    };

int main()
{
    Solution a;
    string test = "xyzabcdefghijklmnopqrstuvwxyzabc";
    cout<<a.findSubstringInWraproundString(test);
    return 0;
}