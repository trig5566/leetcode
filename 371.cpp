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
    public:
        int getSum(int a, int b) {
            int xor_r = a^b;
            int carry_r = (a&b)<<1;
            while(carry_r){
                int temp = xor_r;
                xor_r = xor_r ^ carry_r;
                carry_r = (temp&carry_r)<<1;
            }
            return xor_r;
        }
};

int main()
{
    Solution a;
    cout<<a.getSum(0,-45);
    return 0;
}