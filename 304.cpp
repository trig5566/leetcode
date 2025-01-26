#include <iostream>
#include <vector>
#include <string>

using namespace std;


class NumMatrix {
public:
    vector<vector<int>> sum;
    int row;
    int column;
    NumMatrix(vector<vector<int>>& matrix) {
        row = matrix.size();
        column = matrix[0].size();
        sum = vector<vector<int>>(row+1,vector<int>(column+1,0));
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= column;j++){
                sum[i][j] = sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (sum[row2+1][col2+1]-sum[row2+1][col1]-sum[row1][col2+1]+sum[row1][col1]);
    }
};

int main()
{
    vector<vector<int>> test = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    NumMatrix a{test};
    cout<< a.sumRegion(2,1,4,3);

}