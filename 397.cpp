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

using namespace std;

class Solution {
    public:
        int integerReplacement(int n) {
            return find_min(n);
        }

        int find_min(unsigned long n)
        {
            //cout<<n<<endl;
            if(n == 1)
                return 0;
            if((n & 0x1) == 0){
                return find_min(n>>1)+1;
            } else {
                return min(find_min((n+1)>>1)+2,find_min(n>>1)+2);
            }
        }
};

int main()
{
    Solution a;
    //cout << INT_MAX;
    cout << a.integerReplacement(2147483647);
    return 0;
}