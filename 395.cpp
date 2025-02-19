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

using namespace std;

class Solution {
    public:
        int longestSubstring(string s, int k) {
            return divide_conquer(s, 0, s.size(), k);
        }

        int divide_conquer(string &s,int start,int end,int k){
            if(end-start < k){
                return 0;
            }
            vector<int> ch_ac = vector<int>(26,0);
            for(int i = start;i < end;i++){
                ch_ac[s[i]-'a']++;
            }

            for(int i = start; i < end; i++){
                if(ch_ac[s[i]-'a'] < k){
                    int left = divide_conquer(s,start,i,k);
                    int right = divide_conquer(s,i+1,end,k);
                    return max(left,right);
                }
            }
            return end - start;
        }
};

int main()
{
    string s = "a";
    Solution a;
    cout<< a.longestSubstring(s,1);
    return 0;
}