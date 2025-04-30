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
        int findMaxLength(vector<int>& nums) {
            int result = 0;
            int n = nums.size();
            vector<int> count_list(n+1, 0);
            unordered_map<int, int> hm;

            int count = 0;
            count_list[0] = 0;
            for(int i = 0;i < n;i++){
                if(nums[i] == 0)
                    count--;
                else
                    count++;
                count_list[i+1] = count;
            }

            for(int i = 0;i < n+1;i++){
                if(count_list[i] != 0){
                    if(hm[count_list[i]] == 0)
                        hm[count_list[i]] = i;                   
                    else{
                        if(i - hm[count_list[i]] > result)
                            result = i - hm[count_list[i]];
                    }
                } else {
                    if(i > result)
                        result = i;
                }
            }

            return result;
        }
        
    };

int main(){
    Solution a;
    //vector<int> test = {0,1,0,1,0,1,0,1,1,0,1,1,1,1,0,0,0,0,1,0};
    vector<int> test = {0,1};
    cout << a.findMaxLength(test);
    return 0;
}