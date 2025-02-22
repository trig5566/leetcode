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
#include <random>

using namespace std;

class Solution {
    public:
        unordered_map<int,vector<int>> hm;
        Solution(vector<int>& nums) {     
            srand (time (NULL));      
            for(int i = 0;i < nums.size(); i++){
                auto it = hm.find(nums[i]);
                if(it == hm.end()){
                    hm[nums[i]] = vector<int>({i});
                    //cout<<"["<<nums[i]<<"]["<<hm[nums[i]].size()-1<<"]:"<<i<<endl;
                    continue;
                }
                int size = hm[nums[i]].size();
                hm[nums[i]].push_back(i);
                //cout<<"["<<nums[i]<<"]["<<size<<"]:"<<i<<endl;
            }
        }
        
        int pick(int target) {
            int size = rand()%hm[target].size();
            return hm[target][size];
        }
};


int main()
{
    vector<int> test = {1,2,3,3,3,4,5,5};
    Solution a(test);
    for(int i = 1; i < 6;i++)
        cout<<a.pick(i)<<endl;

    return 0;
}