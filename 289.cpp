#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int i_size = board.size();
        int j_size = board[0].size();
        for(int i = 0;i < i_size;i++){          
            for(int j = 0;j < j_size;j++){
                int neigh_alive = 0;
                if(i-1>=0 && (board[i-1][j]&1))
                    neigh_alive++;
                if(j-1>=0 && (board[i][j-1]&1))
                    neigh_alive++;
                if(i-1 >=0 && j-1>=0 && (board[i-1][j-1]&1))
                    neigh_alive++;
                if(i+1 < i_size && (board[i+1][j]&1))
                    neigh_alive++;
                if(j+1 < j_size && (board[i][j+1]&1))
                    neigh_alive++;
                if(i+1 < i_size && j+1 < j_size && (board[i+1][j+1]&1))
                    neigh_alive++;
                if(i+1 < i_size && j-1>=0 && (board[i+1][j-1]&1))
                    neigh_alive++;
                if(j+1 < j_size && i-1>=0 && (board[i-1][j+1]&1))
                    neigh_alive++;

                if((neigh_alive < 2 || neigh_alive >3) && board[i][j])   
                    board[i][j] = 3;
                else if((neigh_alive == 3) && !board[i][j]) 
                    board[i][j] = 2;           
            }
        }  

        for(int i = 0;i < i_size;i++)         
            for(int j = 0;j < j_size;j++){  
                if(board[i][j] == 3)
                    board[i][j] = 0;
                else if(board[i][j] == 2)
                    board[i][j] = 1;
            }
    }
};

int main()
{
    //vector<vector<int>> test = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    //vector<vector<int>> test = {{1,1},{1,0}};
    //vector<vector<int>> test = {{1}};
    vector<vector<int>> test = {{0,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,0}};
    Solution a;
    a.gameOfLife(test);
    for(vector<int> i:test){
        for(int j:i)
            cout << j << " ";
        cout <<endl;
    }

    return 0;
}