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
        int n = 0;
        vector<signed char> mask;
        int average;
        bool makesquare(vector<int>& matchsticks) {
            n = matchsticks.size();
            mask = vector<signed char>(1<<n,-1);
            int sum = 0;
            if(n < 4)
                return false;
            for(int i = 0; i < n; i++){
                sum += matchsticks[i];
            }
            int check = sum%4;
            if(check != 0)
                return false;
            average = sum/4;

            return can_get(matchsticks,4, average,0);
        }

        bool can_get(vector<int>& matchsticks, int remain, int target,int used){
            if(remain == 1)
                return true;
            if(mask[used] != -1)
                return mask[used];
            if(target == 0){
                return mask[used] = can_get(matchsticks, remain-1,average,used);
            }
            for(int i = n-1; i >= 0; i--){
                if((used & (1 << i)) == 0 && target - matchsticks[i] >= 0 && can_get(matchsticks,remain,target - matchsticks[i],(used | (1 << i)))){
                    return mask[used] = true;
                }
            }
            return mask[used] = false;
        }

};


int main()
{
    Solution a;
    vector<int> test = {13,11,5,8,5,7,8,8,6,7,8,9,5};
    cout << a.makesquare(test);
    return 0;
}