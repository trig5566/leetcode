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

using namespace std;

class Solution {
    public:
        int minMoves2(vector<int>& nums) {
            int result = 0;
            int n = nums.size();
            sort(nums.begin(),nums.end());
            int mid = n/2;
            for(int i = 0;i < n;i++)
                result += abs(nums[i] - nums[mid]);
            

            return result;
        }
};

int main()
{
    vector<int> test = {100,20,9};
    Solution a;
    cout<<a.minMoves2(test);
    return 0;
}