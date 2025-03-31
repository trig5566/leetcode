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
        vector<unsigned long> dp;
        int change(int amount, vector<int>& coins) {
            int n = coins.size();
            dp = vector<unsigned long>(5001,0);
            dp[0] = 1;
            for(int i = 0; i < n; i++)
                for(int j = 0; j <= amount;j++)
                    if(j - coins[i] >= 0)
                        dp[j] +=  dp[j - coins[i]];

            return dp[amount];                                
            
        }
    };

int main()
{
    Solution a;
    vector<int> test = {2};
    cout<< a.change(3,test);
    return 0;
}