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
    
    int minSteps(int n) {
        vector<int> dp(n+1, 0);
        for(int i = 2; i <= n/2;i++){
            for(int j = i/2; j >= 1;j--){
                if(i % j == 0){
                    dp[i] = dp[j] + i/j;
                    break;
                }
            }
        }

        for(int j = n/2; j >= 1;j--){
            if(n % j == 0){
                dp[n] = dp[j] + n/j ;
                break;
            }
        }
        if(n >= 2)
            dp[2] = 2;
        //for(int i = 2; i <= n/2;i++){
        //    cout<<"dp["<<i<<"]:"<<dp[i]<<endl;
        //}
        return dp[n];
    }
};

int main()
{
    Solution a;
    cout<<a.minSteps(60);
    return 0;
}