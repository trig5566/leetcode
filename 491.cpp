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
        vector<vector<int>> findSubsequences(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> t;
            dfs(0, -1000, t, nums, ans);
            return ans;
        }
    
        void dfs(int u, int last, vector<int>& t, vector<int>& nums, vector<vector<int>>& ans) {
            if (u == nums.size()) {
                if (t.size() > 1) ans.push_back(t);
                return;
            }
            if (nums[u] >= last) {
                t.push_back(nums[u]);
                dfs(u + 1, nums[u], t, nums, ans);
                t.pop_back();
                
            }
            if (nums[u] != last){
                dfs(u + 1, last, t, nums, ans);
                
            }
        }
    };

int main()
{
    Solution a;
    vector<int> test = {1,2,3,1,1};
    vector<vector<int>> result = a.findSubsequences(test);
    for(int i = 0;i < result.size();i++){
        for(int j:result[i]){
            cout<<j<<",";
        }
        cout<<endl;
    }
    return 0;
}