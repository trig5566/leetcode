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

using namespace std;

class Solution {
    public:
        int maxRotateFunction(vector<int>& nums) {
            int n = nums.size();
            int sum = 0;
            int my_max = 0;
            if(n <= 1)
                return 0;
            for(int i : nums)
                sum += i;
            
            int first = 0;
            for(int i = 0;i < n;i++){
                first += i*nums[i];
            }
            my_max = max(my_max,first);

            for(int i = n-1; i >= 0;i--){
                first = first + sum - nums[i]*n;
                my_max = max(my_max,first);
            }

            return my_max;
        }
};

int main()
{
    Solution a;
    vector<int> test = {1,100};
    cout<<a.maxRotateFunction(test);
    return 0;
}