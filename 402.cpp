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

using namespace std;

class Solution {
    public:
        string removeKdigits(string num, int k) {
            int in_ptr = 0;
            if(num.size() == k)
                return "0";
            string result = num;
            while(k > 0 && (in_ptr+1 < result.size())){
                if(result[in_ptr] <= result[in_ptr + 1]){
                    in_ptr++;
                } else {
                    result.erase(result.begin() + in_ptr);
                    if(in_ptr > 0)
                        in_ptr--;
                    k--;                   
                } 
            }

            for(;k > 0;k--){
                result.erase(result.end()-1);
            }

            while(result[0] == '0' && result.size() > 1){
                result.erase(result.begin());
            }
            return result;
        }
};

int main()
{
    Solution a;
    string test = "4321";
    cout<<a.removeKdigits(test,1);
    return 0;
}