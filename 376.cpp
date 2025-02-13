#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
    public:
        int wiggleMaxLength(vector<int>& nums) {
            int n = nums.size();
            int high = 1;
            int low = 1;
            for(int i = 1;i < n;i++){
                if(nums[i] > nums[i-1])high = low + 1;
                else if(nums[i] < nums[i-1])low = high +1;
            }
            return max(high,low);
        }
};

int main()
{
    vector<int> test ={1,17,5,10,13,15,10,5,16,8};
    Solution a;
    cout<<"Ans:"<<a.wiggleMaxLength(test)<<endl;
}