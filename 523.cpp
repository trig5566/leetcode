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

        bool checkSubarraySum(vector<int>& nums, int k) {
            int n = nums.size();
            if(n <= 1)
                return false;
            unordered_map<int,int> found_ht;
            int mod = 0;
            found_ht[0] = -1;
            for(int i = 0; i < n;i++){
                mod = (mod+nums[i])%k;
                if(found_ht.find(mod)!=found_ht.end()){
                    if(i - found_ht[mod] > 1)
                        return true;
                } else {
                    found_ht[mod] = i;
                }

            }

            return false;
        }

    };

int main()
{
    Solution a;
    vector<int> test = {1,2,12,4};
    cout<<a.checkSubarraySum(test,6);
    return 0;
}