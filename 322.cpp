#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> dp;
    int n;
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        sort(coins.begin(),coins.end());
        dp = vector<int>(amount+1,amount+1);
        dp[0] = 0;
        for(int i = 0; i < n;i++){
            for(int j = 1; j <= amount;j++){                       
                if(j - coins[i] >= 0){
                    dp[j]  = min(dp[j] ,dp[j-coins[i]]+1);
                }

            }
        }
        return dp[amount] == amount+1?-1:dp[amount];

    }
};

int main()
{
    Solution a;
    vector<int> coins = {186,419,83,408};
    cout<<a.coinChange(coins,6249);
}