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
    vector<int> s1_map = vector<int>(26,0);
    unsigned int s1_bit = 0x3FFFFFF;
    vector<int> s2_map = vector<int>(26,0);
    unsigned int s2_bit = 0;
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;

        for(int i = 0; i < s1.size();i++){
            int ch = s1[i] - 'a';
            s1_map[ch]++;
        }

        for(int i = 0;i < s1.size();i++){
            int ch = s2[i] - 'a';
            s2_map[ch]++;
        }

        for(int i = 0; i < 26; i++){
            if(s2_map[i] == s1_map[i])
                s2_bit = s2_bit | (1 << i);
            else 
                s2_bit = s2_bit & (~(1 << i));
        }

        if(s2_bit == s1_bit)
            return true;
        int l = 1;
        int r = l + s1.size()-1;
        for(; r < s2.size();l++,r++){
            int ch_l = s2[l-1] - 'a';
            s2_map[ch_l]--;
            if(s2_map[ch_l] == s1_map[ch_l])
                s2_bit = s2_bit | (1 << ch_l);
            else 
                s2_bit = s2_bit & (~(1 << ch_l));
            int ch_r = s2[r] - 'a';
            s2_map[ch_r]++;
            if(s2_map[ch_r] == s1_map[ch_r])
                s2_bit = s2_bit | (1 << ch_r);
            else 
                s2_bit = s2_bit & (~(1 << ch_r));
            if(s2_bit == s1_bit)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution a;
    string s1 = "xsa";
    string s2 = "aswdcxasdwsdxcadwswab";
    cout << a.checkInclusion(s1, s2);
    return 0;
}