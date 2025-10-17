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
    unordered_map<int, int> mp;
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;
        int n = nums.size();
        int sum = 0;
        mp[0] = 1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(mp[sum - k])
                result += mp[sum - k];
            mp[sum]++;
        }

        return result;
    }
};

int main()
{
    vector<int> test = {6,4,3,1};
    Solution a;
    cout << a.subarraySum(test, 10);
    return 0;
}