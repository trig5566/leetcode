#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <bitset>
#include <cmath>
#include <string>

using namespace std;

class Solution {
    public:
        class Distance_W{
            public:
                double dis;
                int p_index;
                Distance_W (double d_,int p_){
                    dis = d_;
                    p_index = p_;
                }
        };
        int numberOfBoomerangs(vector<vector<int>>& points) {
            int n = points.size();
            int result = 0;
            vector<vector<Distance_W>> p_list;
            return result;
        }
};

int main()
{
    Solution a;
    vector<vector<int>> test = {{0,0},{1,0},{-1,0},{0,1},{0,-1}};
    cout<<a.numberOfBoomerangs(test);
    return 0;
}