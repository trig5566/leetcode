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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int n = nums.size();
        int acc = 1;
        int result = 0;
        while(left < nums.size()){
            if(right < nums.size() && acc * nums[right] < k){  
                if(right != left){
                    result += 1;  
                    cout<<"+1 acc:"<<acc<<endl;
                }       
                acc *= nums[right];
                right++;
            } else {
                if(right == left){
                    right++;
                    left++;
                } else {
                    result += 1;
                    cout<<"+1 nums["<<left<<"]:"<<nums[left]<<endl;
                    if(right - left > 2){
                        result += (right - left - 2);
                        cout<<"+1 acc:"<<acc<<endl;
                    }
                    acc /= nums[left];
                    left++;                   
                }
            }
        }

        return result;
    }


};

int main(){
    Solution a;
    vector<int> test = {10,2,2,5,4,4,4,3,7,7};
    int k = 289;
    cout<<a.numSubarrayProductLessThanK(test, k);
    return 0;
}