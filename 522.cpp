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
        int findLUSlength(vector<string>& strs) {
            int n = strs.size();
            vector<int> result_arr = vector<int>(n,0);
            int result = INT_MIN;

            for(int i = 0; i < n;i++){
                for(int j = 0; j < n;j++){
                    if(j != i){
                        if(s1IsSubseqOfS2(strs[j],strs[i]))
                            result_arr[j] = -1;
                    }
                }
                if(result_arr[i] == 0)
                    result_arr[i] = strs[i].size();
            }

            for(int i = 0; i < n;i++)
                result = max(result, result_arr[i]);

            return result;
        }

        bool s1IsSubseqOfS2(string s1, string s2){
            if(s1.size() > s2.size())
                return false;
            int i = 0;
            int j = 0;
            for(i = 0; i < s1.size(); i++){
                while(j < s2.size() && s1[i] != s2[j]) j++;
                if(j >= s2.size())
                    break;
                j++;
            }
            return (i == s1.size());
        }

    };

int main()
{
    Solution a;
    vector<string> test = {"abcabc","abcabc","abc","abc","abc","cca"};
    //cout<<a.s1IsSubseqOfS2(test[1],test[0]);
    cout<<a.findLUSlength(test); 
    return 0;
}