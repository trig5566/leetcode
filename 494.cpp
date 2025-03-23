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
        int result = 0;
        int n;
#define get_i(x) (x+sum)
        int findTargetSumWays(vector<int>& nums, int target) {
            n = nums.size();
            int sum = 0;
            for(int i = 0;i < n;i++)
                sum += nums[i];
            if(target > sum || target < (-sum))
                return 0;
            vector<vector<int>> dp(n,vector<int>(2*sum+1,0));
            if(get_i(nums[0]) == get_i(-nums[0]))
                dp[0][get_i(nums[0])] = 2;
            else{
                dp[0][get_i(nums[0])] = 1;
                dp[0][get_i(-nums[0])] = 1;
            }
            for(int i = 1; i < n; i++)
                for(int j = get_i(sum); j >= 0;j--){
                    if(dp[i-1][j] != 0){
                        dp[i][j+nums[i]] += dp[i-1][j];
                        dp[i][j-nums[i]] += dp[i-1][j];
                    }
                }
            return dp[n-1][get_i(target)];
        }
    };

int main()
{
    Solution a;
    vector<int>  test = {100};
    cout<<a.findTargetSumWays(test,-200);
    return 0;
}