#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m = matrix.size();
            int n = matrix[0].size();
            int r = 0;
            int c = n-1;
            while(c >= 0 && r < m){
                if(matrix[r][c] == target)
                    return true;
                else if(target < matrix[r][c])
                    c--;
                else
                    r++;
            }
            return false;
        }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    //vector<vector<int>> matrix = {{1},{2}};
    int target = 24;
    Solution a;
    cout<<a.searchMatrix(matrix,target);
    return 0;
}