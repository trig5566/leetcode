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
    int minDistance(string word1, string word2) {
        int w1_size = word1.size();
        int w2_size = word2.size();
        int result = 0;
        vector<vector<int>> dp(w1_size+1, vector<int>(w2_size+1, 0));
        
        for(int i = 1; i <= w1_size; i++){           
            for(int j = 1; j <= w2_size ;j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        //cout<<"dp["<<w1_size<<"]["<<w2_size<<"]:"<<dp[w1_size][w2_size]<<endl;
        return (w1_size - dp[w1_size][w2_size]) + (w2_size - dp[w1_size][w2_size]);
    }
};

int main()
{
    Solution a;
    string test1 = "a";
    string test2 = "a";
    cout<<a.minDistance(test1, test2);
    return 0;
}