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
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        int result = 0;

        for(int j = 0; j < n;j++){
            if(count[j] == 0){
                int length = 1;
                int i = nums[j];
                while(count[i] == 0){
                    count[i] = length++;
                    i = nums[i];                   
                }
            }
            if(count[j] > result)
                result = count[j];
        }
        return result;
    }
};

int main()
{
    Solution a;
    vector<int> test = {3,4,2,5,6,0,1};
    cout<<a.arrayNesting(test);
    return 0;
}