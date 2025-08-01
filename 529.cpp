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
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }

        vector<int> pos_ = {click[0], click[1]};
        q.push(pos_);

        while(!q.empty())
            bfs(board);

        return board;
    }

#define check_point(__pos__) {if(board[__pos__[0]][__pos__[1]] == 'M')accum++; \
        else if(board[__pos__[0]][__pos__[1]] == 'E')q.push(__pos__); \
        }
    

    void bfs(vector<vector<char>>& board){
        int accum = 0;
        
        vector<int> pos = q.front();
        q.pop();
        if(pos[0] + 1 < r){
            vector<int> pos_ = {pos[0] + 1, pos[1]};
            check_point(pos_);
        }
        if(pos[0] - 1 >= 0){
            vector<int> pos_ = {pos[0] - 1, pos[1]};
            check_point(pos_);
        }
        if(pos[1] + 1 < c){
            vector<int> pos_ = {pos[0], pos[1] + 1};
            check_point(pos_);
        }
        if(pos[1] - 1 >= 0){
            vector<int> pos_ = {pos[0], pos[1] - 1};
            check_point(pos_);
        }

        if(accum == 0)
            board[pos[0]][pos[1]] = 'B';
        else
            board[pos[0]][pos[1]] = '0' + accum;
    }

};

int main()
{
    Solution a;
    vector<vector<char>> board;
    board.push_back(vector<char>{'E', 'E', 'E'});
    board.push_back(vector<char>{'E', 'E', 'E'});
    board.push_back(vector<char>{'E', 'M', 'E'});

    vector<int> pos = {1,0};
    board = a.updateBoard(board, pos);
    //cout<<"r:"<<board.size()<<" c:"<<board[0].size()<<endl;
    cout<<" c:"<<board[0].size()<<endl;
    for(int i = 0; i < board.size();i++){
        for(int j = 0; j < board[0].size();j++)
            cout<<board[i][j]<<",";
        cout<<endl;
    }
    return 0;
}