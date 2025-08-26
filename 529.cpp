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
    queue<vector<int>> q;
    int r = 0;
    int c = 0;
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        r = board.size();
        c = board[0].size();
        dfs(click[0], click[1], board);

        return board;
    }

    void dfs(int m, int n, vector<vector<char>>& board){
        if(board[m][n] == 'M'){
            board[m][n] = 'X';
            return;
        }
        int count = 0;
        for(int i = -1; i <= 1; i++){
            if(m+i >= 0 && m+i < r){
                for(int j = -1; j <= 1; j++){
                    if(n+j >= 0 && n+j < c){
                        if(board[m+i][n+j] == 'M')
                            count++;
                    }
                }
            }
        }

        if(count == 0){
            board[m][n] = 'B';
            for(int i = -1; i <= 1; i+=2){
                if(m+i >= 0 && m+i < r){
                    if(board[m+i][n] == 'E')
                        dfs(m+i, n, board);
                }
            }
            for(int j = -1; j <= 1; j+=2){
                if(n+j >= 0 && n+j < c){
                    if(board[m][n+j] == 'E')
                        dfs(m, n+j, board);
                }
            }
        } else {
            board[m][n] = count + '0';
        }
    }

};

int main()
{
    Solution a;
    vector<vector<char>> board;
    board.push_back(vector<char>{'E', 'E', 'E'});
    board.push_back(vector<char>{'E', 'E', 'E'});
    board.push_back(vector<char>{'E', 'M', 'E'});

    vector<int> pos = {0,0};
    board = a.updateBoard(board, pos);
    cout<<"r:"<<board.size()<<" c:"<<board[0].size()<<endl;
    cout<<" c:"<<board[0].size()<<endl;
    for(int i = 0; i < board.size();i++){
        for(int j = 0; j < board[0].size();j++)
            cout<<board[i][j]<<",";
        cout<<endl;
    }
    return 0;
}