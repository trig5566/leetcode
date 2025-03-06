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
        int compress(vector<char>& chars) {
            if(chars.size() <= 1)
                return chars.size();
            int new_ptr = 0;
            int pre_num = 1;
            char old_char = chars[0];
            for(int i = 1; i < chars.size(); i++){
                if(old_char == chars[i])
                    pre_num++;
                else {
                    chars[new_ptr++] = old_char;
                    old_char = chars[i];
                    if(pre_num != 1){                                               
                        string p_str = to_string(pre_num);
                        for(int j = 0; j < p_str.size(); j++)
                            chars[new_ptr++] = p_str[j];                       
                    }
                    pre_num = 1;
                }
            }
            chars[new_ptr++] = old_char;
            if(pre_num != 1){                                               
                string p_str = to_string(pre_num);
                for(int j = 0; j < p_str.size(); j++){
                    chars[new_ptr++] = p_str[j];
                }
            }
            return new_ptr;
        }
};


int main()
{
    Solution a;
    //vector<char> test = {'a','a','b','b','c','c','c'};
    vector<char> test = {'a','b','c','d','e','f','g','h','i','j','k','k','k'};
    int len = a.compress(test);
    for(int i =0; i < len;i++){
        cout<<test[i]<<",";
    }
    return 0;
}