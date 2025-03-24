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
            vector<int> result(n,-1);
            if(n <= 1)
                return result;
            st.push(0);
            int i = 1;
            while(st.size() > 0){
                if(st.top() == i)
                    break;
                if(nums[st.top()] >= nums[i] && result[i] == -1){
                    st.push(i);
                }

                i++;
                if(i >= n)
                    i = 0;
            }
        }
    };