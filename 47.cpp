#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    unordered_map<int, int> ht;
    void get_permute(vector<int>& nums, vector<int>& list){
        if(list.size() == nums.size()){
            result.push_back(list);
            return;
        }
        for(auto &i: ht){
            if(i.second == 0)continue;
            i.second--;
            list.push_back(i.first);
            get_permute(nums, list);
            i.second++;
            list.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(int i :nums)
            ht[i]++;
        vector<int> list;
        get_permute(nums, list);
        return result;
    }
};

int main()
{
    vector<int> test = {1,1,2,3,3};
    Solution a;
    vector<vector<int>> ans = a.permuteUnique(test);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++)
            cout<<ans[i][j]<<",";
        cout<<endl;
    }
    return 0;
}