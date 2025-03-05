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
        vector<int> findDuplicates(vector<int>& nums) {
            vector<int> result;
            if(nums.size() <= 1)
                return result;
            int it = 0;

            for(; it < nums.size(); it++){
                while(nums[it] != it+1 && nums[it] != 0){
                    if(nums[it] == nums[nums[it]-1]){
                        result.push_back(nums[it]);
                        nums[it] = 0;
                        break;
                    } else
                        swap(nums[it],nums[nums[it]-1]);
                }
            }
            return result;
        }
};

int main()
{
    Solution a;
    //vector<int> test = {4,3,2,7,8,2,3,1};
    vector<int> test = {1};
    vector<int> result = a.findDuplicates(test);
    for(int i: result)
        cout<<i<<",";
    return 0;
}