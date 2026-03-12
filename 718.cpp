#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        for(int i = nums1.size() - 1; i >= 0; i--){
            for(int j = nums2.size() - 1; j >= 0; j--){
                if(nums1[i] == nums2[j]){
                    dp[i][j] = dp[i+1][j+1] + 1;
                    //cout<<"dp["<<i<<"]["<<j<<"]:"<<dp[i][j]<<endl;
                }
                else 
                    dp[i][j] = 0;
                if(dp[i][j] > result)
                    result = dp[i][j];
            }           
        }
        return result;
    }
};

int main()
{
    Solution a;
    vector<int> nums1 = {1,2,3,4,5,6,7,6,5,4,3,2,1};
    vector<int> nums2 = {4,3,2,1,4,5,6,7};
    cout<<a.findLength(nums1, nums2);
    return 0;
}