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


        bool checkSubarraySum(vector<int>& nums, int k) {
            int n = nums.size();
            unordered_map<int,int> dp;
            vector<int> prefix_sum(n+1,0);
            vector<int> prefix_mod(n+1,0);
            int sum = 0;
            int mod = 0;
            for(int i = 1; i <= n;i++){
                sum += nums[i-1];
                mod = sum%k;
                prefix_sum[i] = sum;
                prefix_mod[i] = mod;
                dp[mod]++;
            }
            for(int i = 1; i <= n;i++){
                if(dp[prefix_mod[i]] >= 2)
                    return true;
            }
            return false;
        }



    };

int main()
{
    Solution a;
    vector<int> test = {23};
    cout<<a.checkSubarraySum(test,11);
    return 0;
}