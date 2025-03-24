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
        vector<int> nextGreaterElements(vector<int>& nums) {
            int n = nums.size();
            stack<int> st;
            vector<bool> record(n,0);
            vector<int> result(n,-1);
            if(n <= 1)
                return result;
            st.push(0);
            int i = 1;
            while(st.size() > 0){
                if(st.top() == i)
                    break;
                if(nums[st.top()] >= nums[i]){
                    if(!record[i]){
                        st.push(i);
                        record[i] = 1;
                    }
                } else {
                    while(st.size() > 0 && nums[st.top()] < nums[i]){
                        result[st.top()] = nums[i];
                        st.pop();
                    }
                    if(!record[i]){
                        st.push(i);
                        record[i] = 1;
                    }
                }

                i++;
                if(i >= n)
                    i = 0;
            }
            return result;
        }
        
    };


int main()
{
    Solution a;
    vector<int> test = {2,2,1,1,3,2};
    vector<int> result = a.nextGreaterElements(test);
    for(int i:result){
        cout<<i<<",";
    }
    return 0;
}