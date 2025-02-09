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
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int dp[9];
        int countNumbersWithUniqueDigits(int n) {
            int result = 0;;
            dp[0] = 1;
            dp[1] = 9;
            dp[2] = 81;
            for(int i = 3;i <= n;i++){
                dp[i] = dp[i-1]*(11-i);
            }
            for(int i = 0;i <= n;i++)
                result+=dp[i];
            return result;
        }
};

int main()
{
    Solution a;
    cout<<a.countNumbersWithUniqueDigits(8);
}