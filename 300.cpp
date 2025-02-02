#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        int max_size = 0;
        vector<int> dp(size,1);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i],dp[j]+1);
            }
        }
        for(int i = 0; i < size; i++){
            max_size = max(max_size,dp[i]);
        }
        return max_size;
    }
};

int main()
{

    Solution a;
    //vector<int> test = {1,2,3,4,5,3,4,5,6};
    vector<int> test = {7,7,7,7,7,7,7};
    cout << a.lengthOfLIS(test);


    return 0;
}