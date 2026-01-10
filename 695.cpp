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
    int result;
    int m;
    int n;
    int max_area_cal_dfs(vector<vector<int>>& grid, int x, int y){
        if(grid[x][y] == 0)
            return 0;
        int acc = 1;
        grid[x][y] = 0;
        if(x -1 >= 0)
            acc += max_area_cal_dfs(grid, x - 1, y);
        if(x + 1 < m )
            acc += max_area_cal_dfs(grid, x + 1, y);
        if( y - 1 >= 0)
            acc += max_area_cal_dfs(grid, x, y - 1);
        if( y + 1 < n)
            acc += max_area_cal_dfs(grid, x, y + 1);
        return acc;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        result = 0;
        m = grid.size();
        n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int area = max_area_cal_dfs(grid, i, j);
                if(area > result)
                    result = area;
            }
        }
        return result;
    }
};