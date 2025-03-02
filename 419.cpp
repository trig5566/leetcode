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
        int m;
        int n;
        int countBattleships(vector<vector<char>>& board) {
            m = board.size();
            n = board[0].size();
            int result = 0;
            for(int i = 0; i < m; i++)
                for(int j = 0; j < n; j++){
                    if(board[i][j] == 'X'){
                        bool east = 0,sou = 0;
                        if(i+1 >= m){
                            sou = 1;
                        }else if(board[i+1][j] == '.'){
                            sou = 1;
                        }

                        if(j+1 >= n){
                            east = 1;
                        }else if(board[i][j+1] == '.'){
                            east = 1;
                        }

                        if(sou && east)
                            result++;

                    }
                }

            return result;
        }
};

int main()
{
    //vector<vector<char>> test = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    vector<vector<char>> test = {{'.','.','.','.','.'},
    {'X','X','.','.','.'},
    {'.','.','X','.','.'},
    {'.','.','.','X','X'}};
    Solution a;
    cout<<a.countBattleships(test);
}