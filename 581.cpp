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
    int findUnsortedSubarray(vector<int>& nums) {
        int start = -1;
        int end = 0;
        int max = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max)
                max = nums[i];

            if(nums[i] < max){
                end = i;
                if(start == -1){
                    for(start = 0;nums[start] <= nums[i] && start != i;start++);
                    swap(nums[start], nums[i]);
                    cout<<"first start:"<<start<<" "<<nums[start]<<endl;
                } else if(nums[i] < nums[start]){
                    for(;(start-1) >= 0 && nums[i] < nums[start-1];start--);
                    swap(nums[start], nums[i]);
                    cout<<"update start:"<<start<<" "<<nums[start]<<endl;
                }
            }

        }
        if(start == -1)
            start = 0;
        if(end == 0)
            return 0;
        return end - start +1;
    }
};

int main()
{
    Solution a;
    //vector<int> test = {2,6,4,8,10,9,15};
    vector<int> test = {-1,2,3,0,-3,4,5};
    cout << a.findUnsortedSubarray(test);
    return 0;
}