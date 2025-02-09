#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>
#include <sstream>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution {
    vector<int> worked;
    public:
        bool canMeasureWater(int x, int y, int target) {
            int big = 0,sma = 0,temp = 0;
            worked = vector<int>(1001,0);
            if(target > (x+y))
                return false;
            if(x > y){
                temp = x;
                x = y;
                y = temp;
            }
            worked[0] = 1;
            worked[x] = 1;
            worked[y] = 1;
            worked[x+y] = 1;
            big = y;
            sma = 0;
            while(1){
                if(big == (x-sma)){
                    break;
                }
                else if(big > (x-sma)){
                    big = big-(x-sma);
                    sma = 0;
                    worked[x+big] = 1;
                    worked[big] = 1;
                    //cout<<"big:"<<big<<" sma:"<<sma<<endl;
                } else {
                    sma += big;
                    big = y;
                    worked[sma] = 1;
                    worked[sma+big] = 1;
                    //cout<<"big:"<<big<<" sma:"<<sma<<endl;
                }
            }
            if(worked[target])
                return true;
            return false;
        }
};

int main()
{
    Solution a;
    cout<<INT_MAX<<endl;
    cout<<a.canMeasureWater(71,24,86);
}