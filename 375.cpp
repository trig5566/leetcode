#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>
#include <sstream>
#include <cmath>

using namespace std;

class Solution {
    public:
        vector<vector<int>> dp;
        int getMoneyAmount(int n) {
            dp = vector<vector<int>>(201,vector<int>(201,-1));
            return cal(1,n);
        }
        int cal(int l,int r){
            if(dp[l][r] != -1){
                return dp[l][r];
            }
            if(l == r){
                dp[l][r] = 0;
                return dp[l][r];
            }else if((r - l) == 1){
                dp[l][r] = l;
                return dp[l][r];
            }
            dp[l][r] = INT_MAX;
            for(int i = l+1;i <= r-1;i++){
                dp[l][r] = min(dp[l][r],i+max(cal(l,i-1),cal(i+1,r)));
            }
            return dp[l][r];
        }
};

int main()
{
    int test = 84;
    Solution a;
    cout << a.getMoneyAmount(test);
    return 0;
}