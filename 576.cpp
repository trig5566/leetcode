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
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        long result = 0;
        vector<vector<vector<unsigned long>>> dp = 
        vector<vector<vector<unsigned long>>>(maxMove+1,vector<vector<unsigned long>>(m,vector<unsigned long>(n,0)));
        dp[0][startRow][startColumn] = 1;
        for(int i = 1; i < maxMove; i++){
            for(int j = 0; j < m;j++){
                for(int k = 0; k < n;k++){
                    if(j-1 >= 0 && dp[i-1][j-1][k] > 0)
                        dp[i][j][k] += dp[i-1][j-1][k];
                    if(j+1 < m && dp[i-1][j+1][k] > 0)
                        dp[i][j][k] += dp[i-1][j+1][k];
                    if(k-1 >= 0 && dp[i-1][j][k-1] > 0)
                        dp[i][j][k] += dp[i-1][j][k-1];
                    if(k+1 < n && dp[i-1][j][k+1] > 0)
                        dp[i][j][k] += dp[i-1][j][k+1];
                    dp[i][j][k] = dp[i][j][k] % 1000000007;
                }
            }
        }

        /*for(int i = 1; i < maxMove; i++)
            for(int j = 0; j < m;j++)
                for(int k = 0; k < n;k++){
                    cout << "dp["<<i<<"]["<<j<<"]["<<k<<"]:"<<dp[i][j][k]<<endl;
                }*/
        for(int k = 0; k < maxMove;k++) {      
            if(m == 1 && n == 1){
                result += (dp[k][0][0]*4);
            }else if(m == 1){
                result += (dp[k][0][0]*3);
                result += (dp[k][0][n-1]*3);
                for(int i = 1; i < n-1;i++)
                    result += (dp[k][0][i]*2);
                   
        }else if(n == 1){
            result += (dp[k][0][0]*3);
            result += (dp[k][m-1][0]*3);
            for(int i = 1; i < m-1;i++)
                result += (dp[k][i][0]*2);                    
        }else{
            result += (dp[k][0][0]*2);
            if(m > 1)
                result += (dp[k][m-1][0]*2);
            if(n > 1)
                result += (dp[k][0][n-1]*2);
            if(n > 1 && m > 1)
                result += (dp[k][m-1][n-1]*2);

            for(int i = 1; i < n-1;i++)
                result += dp[k][0][i];
                
            for(int i = 1; i < m-1;i++)
                result += dp[k][i][0];
                
            if(n > 1)
                for(int i = 1; i < m-1;i++)
                    result += dp[k][i][n-1];
                    
            if(m > 1)
                for(int i = 1; i < n-1;i++)
                    result += dp[k][m-1][i];
                
            
            }
            result = result % 1000000007;
        }
        return result;

    }
};

int main()
{
    Solution a;
    cout<<a.findPaths(1, 3, 0, 0, 1);
    return 0;
}