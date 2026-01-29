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
    vector<vector<int>> result;
    void get_subset(vector<int>& nums, vector<int>& now,int start){
        if(start == nums.size()){
            result.push_back(now);
            return;
        }
        now.push_back(nums[start]);
        get_subset(nums, now, start + 1);
        now.pop_back();
        get_subset(nums, now, start + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> now;
        get_subset(nums, now, 0);
        return result;
    }
};

int main()
{
    vector<int> test = {1, 2, 3, 4};
    Solution a;
    vector<vector<int>> result = a.subsets(test);
    for(int i = 0; i < result.size();i++){
        cout<<"["<<i<<"]:";
        for(int j = 0; j < result[i].size();j++)
            cout<<result[i][j]<<",";
        cout<<endl;
    }
    return 0;
}