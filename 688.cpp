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
    vector<vector<vector<double>>> chessBoard;
    double knightProbability(int n, int k, int row, int column) {
        double result = 0;
        chessBoard = vector<vector<vector<double>>>(k+1, vector<vector<double>>(n, vector<double>(n, 0)));
        chessBoard[0][row][column] = 1;
        for(int l = 1; l <= k; l++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i - 2 >= 0 && j - 1 >= 0)
                        chessBoard[l][i][j] += chessBoard[l-1][i-2][j-1]*0.125;
                    if(i - 2 >= 0 && j + 1 < n)
                        chessBoard[l][i][j] += chessBoard[l-1][i-2][j+1]*0.125;
                    if(i + 2 < n && j - 1 >= 0)
                        chessBoard[l][i][j] += chessBoard[l-1][i+2][j-1]*0.125;
                    if(i + 2 < n && j + 1 < n)
                        chessBoard[l][i][j] += chessBoard[l-1][i+2][j+1]*0.125;
                    if(i - 1 >= 0 && j - 2 >= 0)
                        chessBoard[l][i][j] += chessBoard[l-1][i-1][j-2]*0.125;
                    if(i - 1 >= 0 && j + 2 < n)
                        chessBoard[l][i][j] += chessBoard[l-1][i-1][j+2]*0.125;
                    if(i + 1 < n && j - 2 >= 0)
                        chessBoard[l][i][j] += chessBoard[l-1][i+1][j-2]*0.125;
                    if(i + 1 < n && j + 2 < n)
                        chessBoard[l][i][j] += chessBoard[l-1][i+1][j+2]*0.125;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                result += chessBoard[k][i][j];
            }
        }
        return result;
    }
};