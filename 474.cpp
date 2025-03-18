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

using namespace std;


class Solution {
    public:
        vector<pair<int,int>> z_o_list;
        int len;
        int findMaxForm(vector<string>& strs, int m, int n) {
            len = strs.size();
            vector<pair<int,int>> z_o_list = vector<pair<int,int>>(len);
            vector<vector<int>> max_times(m+1,vector<int>(n+1,0));
            for(int i = 0; i < len; i++){
                int one = 0;
                int zero = 0;
                for(char j:strs[i]){
                    if(j == '1')
                        one++;
                    else
                        zero++;
                }
                z_o_list[i].first = zero;
                z_o_list[i].second = one;
            }

            for(int k = 0; k < len;k++)
                for(int i = m; i >= 0; i--)
                    for(int j = n; j >= 0; j--){
                        if(z_o_list[k].first <= i && z_o_list[k].second <= j){
                            max_times[i][j] = max(max_times[i - z_o_list[k].first][j - z_o_list[k].second]+1,max_times[i][j]);
                            cout<<"max_times["<<i<<"]["<<j<<"]:"<<max_times[i][j] << endl;
                        }
                    }
                
            return max_times[m][n];
        }
    };

int main(){
    Solution a;
    vector<string> test = {"10","0001","111001","1","0"};
    cout<<a.findMaxForm(test,5,3);
    return 0;
}