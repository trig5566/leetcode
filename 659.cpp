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
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_map<int, int> tail;
        for(int i : nums){
            mp[i]++;
        }
        for(int i : nums){
            if(mp[i] == 0)
                continue;
            mp[i]--;
            if(tail[i-1] != 0){
                tail[i-1]--;
                tail[i]++;
            } else if(mp[i+1] != 0 && mp[i+2] != 0){               
                mp[i+1]--;
                mp[i+2]--;
                tail[i+2]++;
            } else 
                return false;
        }
        return true;
    }
};

int main()
{
    Solution a;
    //vector<int> test = {1,2,3,3,4,4,5,5};
    vector<int> test = {1,2,3,3,4,5};
    cout<<a.isPossible(test);
    return 0;
}