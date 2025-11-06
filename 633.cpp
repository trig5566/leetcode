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
    
    bool judgeSquareSum(int c) {
        unordered_map<int, int> square_house;
        for(long i = 0; i*i < INT_MAX && i*i <= c;i++){
            square_house[i*i] = 1;
        }

        for(long i = 0; (i*i < (INT_MAX/2)+1) && i*i <= c;i++){
            if(i*i != (c-i*i) && square_house[c - i*i]){
                cout<<c<<" = "<<i<<"*"<<i<<" + "<<c - i*i<<endl;
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution a;
    cout<<a.judgeSquareSum(2116750066);
    return 0;
}