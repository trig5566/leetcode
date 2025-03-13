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
#include <cmath>
#include <string>

using namespace std;

class Solution {
    public:
        int n;
        bool result = false;
        int dir,cir;
        bool circularArrayLoop(vector<int>& nums) {
            n = nums.size();
            for(int i = 0;i < n;i++){
                if(nums[i] == 0)
                    continue;
                else {
                    cir = -1;
                    dir = 0;
                    nums[i] = loop_find(nums,i);
                }          
            }
            return result;
        }
        int loop_find(vector<int>& nums,int it){
            //cout<<it<<",";
            int mov = nums[it] < -1000? nums[it]+1000: (nums[it] > 1000 ? nums[it]-1000:nums[it]);
            if(it == move_it(it,mov,n))
                return 0;
            if(it == cir){
                if(dir > 0)
                    result = true;
                return  0;
            }
            if(nums[it] < -1000 || nums[it] > 1000){
                if(cir < 0){
                    cir = it;
                    dir = nums[it] > 0? 1:2;
                }
                if((dir == 1 && nums[it] < 0) || (dir == 2 && nums[it] > 0))
                    dir = 0;
                nums[it] = loop_find(nums,move_it(it,mov,n));

            }else if(nums[it] < 0 || nums[it] > 0){
                nums[it] = nums[it] > 0 ? nums[it]+1000:nums[it]-1000;
                nums[it] = loop_find(nums,move_it(it,mov,n));
            }
            return nums[it];
        }
        int move_it(int start,int x,int n){
            while(start+x < 0)
                x += n;
            while(start+x >= n)
                x -= n;
            
            return start+x;
        }
};

int main()
{
    Solution a;
    vector<int> test = {2,-1,1,2,2};
    cout<<a.circularArrayLoop(test);
    for(int i:test)
        cout<<","<<i;
    return 0;
}