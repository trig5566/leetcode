#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> dp;
    int n;
    class Solution(){
        
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        dp = vector<int>(amount+1,-1);
        dp[0] = 0;
        int mini = INT_MAX;
        for(int i = 0;i < n;i++){
            for(int j = 1;j <= amount;j++){
                mini = INT_MAX;
                if(j-coins[i] >= 0 && dp[j-coins[i]] >= 0){
                    mini = min(mini,dp[j-coins[i]]+1);
                    dp[j] = mini;
                }
            }
        }
    }
};