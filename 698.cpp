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
    int buck_size;
    vector<int8_t> record;
    bool separation_subset(int remaining, int start, int bucket_num, vector<int> &nums){
        if(bucket_num == 0)
            return true;
        if(remaining == 0) return separation_subset(buck_size, 0, bucket_num - 1, nums);
        for(int i = start; i < nums.size(); i++){
            if(record[i] == 1 || remaining < nums[i])continue;
            record[i] = 1;
            if(separation_subset(remaining - nums[i], i + 1, bucket_num, nums))
                return true;
            record[i] = 0;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        record = vector<int8_t>(nums.size(), 0);
        for(int i : nums){
            sum += i;
        }
        if(sum % k != 0 )
            return false;
        buck_size = sum/k;
        sort(nums.begin(), nums.end(), greater<int>());
        if (nums.back() > buck_size) return false;
        vector<int> buckets(k, sum/k);   

        return  separation_subset(buck_size, 0, k-1, nums);
    }
};

int main()
{
    Solution a;
    //vector<int> test = {4,5,9,3,10,2,10,7,10,8,5,9,4,6,4,9};
    //int k = 5;
    vector<int> test = {1,1,1,1,2,2,2,2,4,3,2,3,5,2,1};
    int k = 4;
    //vector<int> test = {18,20,39,73,96,99,101,111,114,190,207,295,471,649,700,1037};
    //int k = 4;
    //vector<int> test = {2,9,4,7,3,2,10,5,3,6,6,2,7,5,2,4};
    //int k = 7;
    //vector<int> test = {5309,7138,779,8949,8568,2250,1794,6539,4948,7189,4270,9866,5867,2112,9176,3162};
    //int k = 2;
    cout<<a.canPartitionKSubsets(test, k);
    return 0;
}