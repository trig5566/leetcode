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
#define RECORD_DONE   0x10000
    int max_r, max_c;
    queue<vector<int>> my_queue;

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        max_r = mat.size();
        max_c = mat[0].size();

        for(int i = 0;i < max_r; i++)
            for(int j = 0; j < max_c;j++)
                if(mat[i][j] == 0)
                    push_point_to_queue(mat, i, j, 0);

        while(!my_queue.empty()){
            vector<int> tmp = my_queue.front();           
            push_point_to_queue(mat, tmp[0], tmp[1], tmp[2]);
            my_queue.pop();
        }

        for(int i = 0;i < max_r; i++)
            for(int j = 0; j < max_c;j++)
                mat[i][j] -= RECORD_DONE;

        return mat;
    }

    void push_point_to_queue(vector<vector<int>>& mat, int r, int c, int val){
        if(mat[r][c] >= RECORD_DONE && (mat[r][c] - RECORD_DONE) <= val)
            return;
        mat[r][c] = RECORD_DONE;
        mat[r][c] += val;
        //cout<<"check mat["<<r<<","<<c<<"]:"<<mat[r][c]<<",dis :"<<val<<endl;
        if(r-1 >= 0)
            my_queue.push({r-1, c, val+1});
        if(c-1 >= 0)
            my_queue.push({r, c-1, val+1});
        if(r+1 < max_r)
            my_queue.push({r+1, c, val+1});
        if(c+1 < max_c)
            my_queue.push({r, c+1, val+1});
    }
};

int main()
{
    Solution a;
    vector<vector<int>> board = {{1, 1, 0, 1, 1},
                                 {0, 1, 1, 1, 1},
                                 {1, 1, 1, 1, 1},
                                 {1, 0, 1, 1, 1},};
    board = a.updateMatrix(board);
    for(int i = 0;i < board.size();i++){
        for(int j = 0; j < board[0].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}