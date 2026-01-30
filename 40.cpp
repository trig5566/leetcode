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
    int size;
    void add_comb_sum(vector<int>& candidates, int start, vector<int>&list, int remaining){
        if(remaining == 0){       
            result.push_back(list);           
            return;
        }

        for(int i = start; i < size && candidates[i] <= remaining;i++){
            if(i > start && candidates[i] == candidates[i - 1])continue;
            list.push_back(candidates[i]);
            add_comb_sum(candidates, i + 1, list, remaining - candidates[i]);
            list.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for(int i = candidates.size() - 1; i >= 0; i--)
            if(candidates[i] <= target){
                size = i+1;
                break;
            }
        vector<int> list;
        add_comb_sum(candidates, 0, list, target);
        return result;
    }
};

int main()
{
    vector<int> test = {10,1,2,2,2,2,7,6,1,5};
    int target = 8;
    //vector<int> test = {1};
    //int target = 1;
    Solution a;
    vector<vector<int>> ans = a.combinationSum2(test, target);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++)
            cout<<ans[i][j]<<",";
        cout<<endl;
    }
    return 0;
}