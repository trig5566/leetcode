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
    int n = 100;
    Solution(){
        dp = vector(10001,10000);
        for(int i = 1;i <= n;i++){
            dp[i*i] = 1;
            for(int j = i*i+1;j <= 10000;j++){
                dp[j] = min(dp[j],dp[j-i*i]+1);
            }
        }
    }
    int numSquares(int n) {
        return dp[n];
    }
};


int main()
{
    Solution a;
    cout<<a.numSquares(99);
}