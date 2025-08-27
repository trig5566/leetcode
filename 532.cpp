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
    int findPairs(vector<int>& nums, int k) {
        set<vector<int>> result;
        sort(nums.begin(), nums.end());
        //for(int i = 0; i < nums.size(); i++)
            //cout<< nums[i] << " ";
        //cout<<endl;
        for(int i = 0; i < nums.size(); i++){
            int j = lower_bound(nums.begin(), nums.begin()+i, nums[i] - k) - nums.begin();
            if(nums[j] == nums[i] - k && j < i){
                cout<<nums[j]<<","<<nums[i]<<endl;
                vector<int> tmp = {nums[j], nums[i]};
                result.insert(tmp);
            }
        }

        //return result.size();
        return result.size();
    }
};

int main()
{
    Solution a;
    vector<int> test = {-10000000,-9999999,-9999998,-9999997,-4,4,-4,-2,-2,1,2,3,4,7,6,5};
    cout<<a.findPairs(test, 1);
    return 0;
}