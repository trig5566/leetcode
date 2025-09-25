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
    unordered_map<long long, int>tab;
    int leastBricks(vector<vector<int>>& wall) {
        int result = 0;
        for(int i = 0; i < wall.size();i++){
            long long row_total = 0;
            for(int j = 0; j < wall[i].size()-1;j++){
                row_total += wall[i][j];
                tab[row_total]++;
                if(tab[row_total] > result){
                    result = tab[row_total];
                    cout << "now total:"<<row_total<<"on "<<i<<","<<j<<endl;
                }
            }
        }
        return wall.size() - result;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> test = {{1,2,2,1},{3,1,2},{1,3,2},{2,4},{3,1,2},{1,3,1,1}};
    cout<<a.leastBricks(test);
    return 0;
}