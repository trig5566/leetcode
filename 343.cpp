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

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n == 2)
            return 1;
        else if(n == 3)
            return 2;
        int pow_3 = n/3;
        if(n%3 == 0){
            return (int)pow(3,pow_3);
        } else if(n%3 == 1){
            return (int)(pow(3,pow_3-1)*4);
        }else{
            return (int)(pow(3,pow_3)*2);
        }
    }
};

int main()
{
    int test = 4;
    Solution a;
    cout<<a.integerBreak(test);
}