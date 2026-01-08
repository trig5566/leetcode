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

#define CHECK_ON_BOARD(x, y, move_x, move_y, n)  if(x+move_x >= 0 && x+move_x < n && y+move_y >= 0 && y+move_y < n)  

class Solution {
public:
    vector<vector<double>> chessBoard;
    double knightProbability(int n, int k, int row, int column) {
        chessBoard = vector<vector<double>>(n, vector<double>(n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

            }
        }
    }
};