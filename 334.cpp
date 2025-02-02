#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = 0;
        int mid_index = -1;
        if(nums.size() < 3)
            return false;
        min = nums[0];
        for(int i = 1;i < nums.size();i++){
            if(mid_index != -1 && nums[i] > nums[mid_index])
                return true;
            if(nums[i] > min)
                mid_index = i;
            if(nums[i] < min)
                min = nums[i];
        }
        return false;
    }
};

int main()
{
    vector<int> test = {2,1,0,4,3};
    Solution a;
    cout<<a.increasingTriplet(test);
}