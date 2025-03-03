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
#include <unordered_map>
#include <bitset>

using namespace std;


class Solution {
    class Tri{
        public:
            Tri *node[2] = {0};
    };
    public:
        Tri root;
        int findMaximumXOR(vector<int>& nums) {
            int result = 0;
            for(int i = 0; i < nums.size(); i++)
                insert_tri(nums[i]);
            for(int i: nums){
                result = max(result,find_max(i));
            }
            return result;
        }

        void insert_tri(int n){
            bitset<32> bs(n);
            Tri *it = &root;
            for(int j = 31; j >= 0; j--){
                if(it->node[bs[j]] == 0){
                    it->node[bs[j]] = new Tri();
                }
                it = it->node[bs[j]];
            }
        }

        int find_max(int n){
            bitset<32> bs(n);
            Tri *it = &root;
            int ans = 0;
            for(int j = 31; j >= 0; j--){
                if(it->node[bs[j]^0x1] != 0){
                    ans |= 1<<j;
                    it = it->node[bs[j]^0x1];
                } else {
                    it = it->node[bs[j]];
                }
            }
            return ans;
        }

};

int main()
{
    Solution a;
    vector<int> test = {14,70,53,83,49,91,36,80,92,51,66,70};
    cout<<a.findMaximumXOR(test);
}