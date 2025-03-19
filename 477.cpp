#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <bitset>

using namespace std;

class Solution {
    public:
        int totalHammingDistance(vector<int>& nums) {
            int result = 0;
            vector<int> bit_count(32,0);
            for(int i:nums){
                for(int j = 0; j < 32;j++){
                    if((i & (1<<j)))
                        bit_count[j]++;
                }
            }

            for(int i = 0; i < 32;i++){
                result += (nums.size()-bit_count[i])*bit_count[i];
            }
            return result;
        }
};

int main()
{
    vector<int> nums = {4,14,4};
    Solution a;
    cout << a.totalHammingDistance(nums);
    return 0;
}