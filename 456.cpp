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
    public:
        bool find132pattern(vector<int>& nums) {
            int n = nums.size();
            stack<int> st;
            int my_j = INT_MIN;
            for(int i = n-1; i >= 0;i--){
                if(my_j > nums[i])
                    return true;
                while(!st.empty() && nums[i] > st.top()){
                    my_j = st.top();
                    st.pop();                   
                }
                st.push(nums[i]);
            }
            
            return false;
        }

};


int main()
{
    vector<int> test = {10,12,6,8,3,5,11};
    Solution a;
    cout<<a.find132pattern(test);
    return 0;
}