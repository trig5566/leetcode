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
    //vector<vector<pair<double,double>>> dp;//first is min, second is max
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        string result = "";
        if(n == 1)
            return to_string(nums[0]);
        else if(n == 2){
            result = to_string(nums[0])+"/"+to_string(nums[1]);
        } else {
            result = to_string(nums[0])+"/("+to_string(nums[1]);
            for(int i = 2; i < n;i++)
                result += "/"+to_string(nums[i]);
            result += ")";
        }

        return result;
    }
};

int main()
{
    Solution a;
    vector<int> test = {2,3,4,5,6};
    cout<<a.optimalDivision(test);
    return 0;
}