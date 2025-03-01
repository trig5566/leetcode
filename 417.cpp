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
        vector<vector<char>> p_map;
        vector<vector<char>> a_map;
        int m,n;
        vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            m = heights.size();
            n = heights[0].size();           
            vector<vector<int>> result;
            p_map = vector<vector<char>>(m,vector<char>(n,0));
            a_map = vector<vector<char>>(m,vector<char>(n,0));
            for(int i = 0; i < m; i++){
                find_p_occean(heights, i, 0);
                find_a_occean(heights, i, n-1);               
            } 

            for(int j = 0; j < n; j++){
                find_p_occean(heights, 0, j);
                find_a_occean(heights, m-1, j);   
            }

            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(p_map[i][j]&&a_map[i][j] & 0x1)
                        result.push_back({i,j});
                }
            } 

            return result;           
        }

#define move_nor(r,c) (r-1 >= 0 && heights[r-1][c] >= heights[r][c])
#define move_sou(r,c) (r+1 < m && heights[r+1][c] >= heights[r][c])
#define move_eas(r,c) (c+1 < n && heights[r][c+1] >= heights[r][c])
#define move_wes(r,c) (c-1 >= 0 && heights[r][c-1] >= heights[r][c])

        void find_p_occean(vector<vector<int>>& heights, int r, int c){
            
            if(p_map[r][c])
                return;

            p_map[r][c] = 1;

            if(move_nor(r,c))
                find_p_occean(heights,r-1,c);

            if(move_wes(r,c))
                find_p_occean(heights,r,c-1);   

            if(move_sou(r,c))
                find_p_occean(heights,r+1,c);

            if(move_eas(r,c))
                find_p_occean(heights,r,c+1);

        }

        void find_a_occean(vector<vector<int>>& heights, int r, int c){  
            
            if(a_map[r][c])
                return;
                       
            a_map[r][c] = 1;

            if(move_sou(r,c))
                find_a_occean(heights,r+1,c);

            if(move_eas(r,c))
                find_a_occean(heights,r,c+1);

            if(move_nor(r,c))
                find_a_occean(heights,r-1,c);

            if(move_wes(r,c))
                find_a_occean(heights,r,c-1);   

        }

};

int main()
{
    Solution a;
    vector<vector<int>> test = {{10,10,10},{10,1,10},{10,10,10}};
    //vector<vector<int>> test = {{1}};
    //vector<vector<int>> test = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> result = a.pacificAtlantic(test);
    for(int i = 0;i < result.size();i++)
        cout<<"["<<result[i][0]<<","<<result[i][1]<<"]"<<endl;
    return 0;
}