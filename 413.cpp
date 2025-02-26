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

using namespace std;

class Solution {
    public:
        int numberOfArithmeticSlices(vector<int>& nums) {
            int n = nums.size();
            if(n < 3)
                return 0;        
            int diff = nums[1] - nums[0];
            int pre = 1;   
            int start = 0; 
            int result = 0;
            for(int i = 2; i < nums.size(); i++){
                if(diff != (nums[i] - nums[pre])){
                    result += cal_nums(start,pre);
                    start = pre;
                    diff = nums[i] - nums[pre];              
                }              
                pre = i;
            }
            result += cal_nums(start,pre);
            return result;
    }

    int cal_nums(int l,int r){
        if(r-l < 2)
            return 0;
        else{
            int n = r - l + 1;
            return (n-2)*(n-1)/2;
        }
    }

};

int main()
{
    vector<int> test = {1,2,3,4,5,5,5,6,7};
    Solution a;
    cout<<a.numberOfArithmeticSlices(test);
    return 0;
}