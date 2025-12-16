#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if(nums.size() < 3)
            return true;
        bool special = 0;
        if(nums[0] > nums[1]){
            nums[0] = nums[1];
            special = 1;
        }
        for(int i = 2; i < nums.size();i++){
            if(nums[i-1] > nums[i] && !special){
                special = 1;
                if(i+1 < nums.size()){
                    if(nums[i-1] > nums[i+1]){
                        nums[i-1] = nums[i];
                        if(nums[i-1] < nums[i-2])
                            return false;
                    } else 
                        nums[i] = nums[i-1];
                } 
            } else if(nums[i-1] > nums[i] && special)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution a;
    vector<int> test = {1, 2, 1, 2};
    cout<<a.checkPossibility(test);
    return 0;
}