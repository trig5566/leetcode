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
#define GO_UP 0
#define GO_DOW 1
    public:
        int n;
        int m;
        vector<int> result;
        vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
            m = mat.size();
            n = mat[0].size();
            int digon_len = m+n-1;
            int r = 0;
            int c = 0;
            int dir = GO_UP;
            for(int i = 0; i < digon_len;i++){
                diagon(mat, r, c, dir);
                dir = (dir == GO_UP?GO_DOW:GO_UP);
            }
            return result;
        }

        void diagon(vector<vector<int>>& mat, int &s_r, int &s_c, int dir){
            int i = 0;
            if(GO_UP == dir){
                for(i = 0; s_r-i >= 0 && s_c+i < n; i++)
                    result.push_back(mat[s_r-i][s_c+i]);
                
                if(s_c + i < n){
                    s_c = s_c + i;
                    s_r = s_r -(i-1);
                } else {
                    s_c = s_c + (i-1);
                    s_r = s_r -(i-1) + 1;
                }

            } else {
                for(i = 0; s_r+i < m && s_c-i >= 0; i++)
                    result.push_back(mat[s_r+i][s_c-i]);
                
                if(s_r + i < m){
                    s_c = s_c - (i-1);
                    s_r = s_r + i;
                } else {
                    s_c = s_c - (i-1) + 1;
                    s_r = s_r + (i-1);                   
                }           
            }
        }

    };

int main()
{
    Solution a;
    vector<vector<int>> test = {{1}};
    vector<int> result = a.findDiagonalOrder(test);
    for(int i : result)
        cout<<i<<",";
    return 0;
}