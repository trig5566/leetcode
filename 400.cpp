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
#include <cmath>
#include <string>

using namespace std;

class Solution {
    public:
        int findNthDigit(int n) {
            if(n < 10)
                return n;
            int i = 1;
            while(n > 9*i*pow(10,i-1)){               
                n -= 9*i*pow(10,i-1);
                i++;
            }
            int num = pow(10,i-1) + (n-1)/i;
            
            return to_string(num)[(n-1)%i]-'0';
        }
};

int main(){
    Solution a;
    cout<<a.findNthDigit(190);
    
    return 0;
}