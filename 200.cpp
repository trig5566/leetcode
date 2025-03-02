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
        int numIslands(vector<vector<char>>& grid) {
            m = grid.size();
            n = grid[0].size();
            int result = 0;
            cout<<m<<n<<endl;
            for(int i = 0;i < m;i++){
                for(int j = 0; j < n; j++){
                    if(grid[i][j] != '0'){
                        result++;
                        bfs(grid,i,j);
                    }
                }
            }
            return result;
        }

        void bfs(vector<vector<char>>& grid,int r,int c){
            cout<<"["<<r<<","<<c<<"] done"<<endl;
            grid[r][c] = '0';
            if(r-1 >= 0 && (grid[r-1][c] != '0'))
                bfs(grid,r-1,c);
            if(r+1 < m && grid[r+1][c] != '0')
                bfs(grid,r+1,c);
            if(c-1 >= 0 && grid[r][c-1] != '0')
                bfs(grid,r,c-1);
            if(c+1 < n && grid[r][c+1] != '0')
                bfs(grid,r,c+1);
        }
};

int main()
{
    //vector<vector<char>> test = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    vector<vector<char>> test = {{'1','1','0','0','0'},
    {'1','1','0','0','0'},
    {'0','0','1','0','0'},
    {'0','0','0','1','1'}};
    Solution a;
    cout<<a.numIslands(test);
}