#include <iostream>
#include <vector>
#include <set>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> sum;
    int n_size = 0;
    int m_size = 0;
    NumMatrix(vector<vector<int>>& matrix) {
        n_size = matrix.size();
        m_size = matrix[0].size();
        sum = vector<vector<int>>(n_size+1, vector<int>(m_size+1, 0));
        for(int i = 0; i < n_size; i++){
            for(int j = 0; j < m_size;j++){
                if(i == j)
                    sum[i][j] = matrix[i][j];
                else {
                    if(i-1 >= 0){
                        sum[i][j]+= 
                    }
                }

            }

        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
    }
};