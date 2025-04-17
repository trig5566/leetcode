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
            vector<unordered_map<string,bool>>  hm = vector<unordered_map<string,bool>>(n);
            for(int i = 0; i < n; i++){
                for(int mask = 1; mask < (1 << strs[i].size()); mask++){
                    string tmp = "";
                    for(int j = 0; j < strs[i].size();j++)
                        if(mask & (1 << j))
                            tmp += strs[i][j];
                    //cout<<"tmp:"<<tmp<<endl;
                    hm[i][tmp] = 1;
                }
            }

            for(int i = 0; i < n;i++){
                for(int j = 0; j < n;j++){
                    if(j != i){
                        if(hm[i][strs[j]])
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
    };

int main()
{
    Solution a;
    vector<string> test = {"abcc","bcd","abc","bcc"};
    cout<<a.findLUSlength(test); 
    return 0;
}