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
        vector<int> dp;
        vector<int> record;
        vector<int> result;       

        vector<int> largestDivisibleSubset(vector<int>& nums) {
            dp = vector<int>(1001,0);
            record = vector<int>(1001,-1);
            int max_i = 0;
            int max_v = 0;
           // int record_max = 0;
            sort(nums.begin(), nums.end());
            for(int i = 0; i < nums.size();i++){
                //record_max = 0;
                for(int j = i-1;j >= 0; j--){
                    if(nums[i] % nums[j] == 0){
                        if(dp[j]+1 > dp[i]){
                            dp[i] = dp[j]+1;
                            record[i] = j;
                            if(dp[i] > max_v){
                                max_v = dp[i];
                                max_i = i;
                            }
                        }
                    }
                    
                    //record_max = max(record_max,record[j]);
                    //cout<<"nums:"<<nums[j]<<" record["<<j<<"]:"<<record[j]<<" record_max:"<<record_max<<endl;
                }
                //cout<<"num["<<i<<"]:"<<nums[i]<<" dp:"<<dp[i]<<endl;
            }

            while(max_i >= 0){
                result.push_back(nums[max_i]);
                max_i = record[max_i];
            }
            return result;
        }
};

int main()
{
    Solution a;
    vector<int> test = {1,3,9,4,8,5,25,17,13,15,27,32,81};
    for(int i:a.largestDivisibleSubset(test)){
        cout<< i <<" ";
    }
    return 0;
}