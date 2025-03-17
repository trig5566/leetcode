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
        int stick_record = 0;
        bool makesquare(vector<int>& matchsticks) {
            bool result = 1;
            n = matchsticks.size();
            int sum = 0;
            if(n < 4)
                return false;
            for(int i = 0; i < n; i++){
                sum += matchsticks[i];
            }
            sort(matchsticks.begin(),matchsticks.end());
            int check = sum%4;
            if(check != 0)
                return false;
            int average = sum/4;
            for(int i = 0; i < 4; i++){
                result &= can_get(matchsticks, average,stick_record);
            }
            return result;
        }

        bool can_get(vector<int>& matchsticks, int target,int used){
            if(target < 0)
                return false;
            else if(target == 0){
                stick_record |= used;
                return true;
            }
            for(int i = n-1; i >= 0; i--){
                if((used & (1 << i)) == 0){
                    if(can_get(matchsticks,target - matchsticks[i],(used | (1 << i))))
                        return true;
                }
            }
            return false;
        }

};


int main()
{
    Solution a;
    vector<int> test = {5,5,5,5,4,4,4,4,3,3,3,3};
    cout << a.makesquare(test);
    return 0;
}