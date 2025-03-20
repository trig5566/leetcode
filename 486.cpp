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
        vector<int> hs;
        int n;
        bool predictTheWinner(vector<int>& nums) {
            hs = vector<int>(1<<20,-1);
            n = nums.size();
            return canwin(nums,0,0,n-1);
        }

        bool canwin(vector<int>& nums, int mask, int l, int r){
            if(hs[mask] != -1){
                return hs[mask];
            }
            if(l > r){
                int p1 = 0;
                int p2 = 0;
                for(int i = 0; i < n; i++){
                    if(mask & (1<<i))
                        p1 += nums[i];
                    else
                        p2 += nums[i];
                }
                
                if(p1 >= p2)
                    hs[mask] = 1;
                else
                    hs[mask] = 0;
                cout<<"mask["<<mask<<"]:"<<hs[mask]<<endl;
                return hs[mask];            
            }

            return (canwin(nums, mask|1<<l, l+2, r) && canwin(nums, mask|1<<l, l+1, r-1)) ||
                    (canwin(nums, mask|1<<r, l, r-2) && canwin(nums, mask|1<<r, l+1, r-1));
          
        }
};

int main()
{
    Solution a;
    vector<int> test = {1,5,2};
    cout<<a.predictTheWinner(test);
    return 0;
}