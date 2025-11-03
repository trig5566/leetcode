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
    int triangleNumber(vector<int>& nums) {
        int result = 0;
        if(nums.size() < 3)
            return 0;
        int first = 0;       
        sort(nums.begin(), nums.end());
        for(int last = 2; last < nums.size(); last++){
            
            for(int tmp = first; tmp+1 < last; tmp++){
                auto it = lower_bound(nums.begin()+tmp+1, nums.begin()+last, nums[last]-nums[tmp]+1);
                if(it == nums.begin()+last){
                    //first = tmp + 1;
                    continue;
                }
                cout<<"last["<<last<<"]:"<<nums[last]<<endl;
                cout<<"sec["<<(it - nums.begin())<<"]:"<<nums[(it - nums.begin())]<<endl;
                cout<<"first["<<tmp<<"]:"<<nums[tmp]<<endl;
                cout<<"result+="<<(last-(it - nums.begin()))<<endl;
                result += (last-(it - nums.begin()));               
            }
        }
        return result;
    }
};

int main()
{
    Solution a;
    //vector<int> test = {1, 2, 2, 2, 3, 4};
    vector<int> test = {2, 2, 2, 1, 1, 1, 2, 3, 4, 4};
    cout<<a.triangleNumber(test);
    return 0;
}