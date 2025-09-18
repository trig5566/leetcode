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
    int n = 0;
    vector<int> union_set;
    queue<int> my_qu;
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        n = isConnected.size();
        union_set = vector<int>(n, 0);
        set<int> result;
        for(int i = 0; i < n;i++)
            union_set[i] = i+1;
        for(int i = 0; i < n;i++){
            if(union_set[i] == i+1)
                my_qu.push(i);
            while(!my_qu.empty()){
                int temp = my_qu.front();
                my_qu.pop();
                find_set(isConnected, temp);
            }
        }

        for(int i = 0; i < n;i++)
            result.insert(union_set[i]);
        
        return result.size();
    }

    void find_set(vector<vector<int>>& isConnected, int x)
    {
        for(int j = 0; j < n; j++){
            if(isConnected[x][j] == 1){
                if(union_set[j] > union_set[x]){
                    union_set[j] = union_set[x];
                    my_qu.push(j);
                }
            }
        }
    }

};

int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 1, 0, 0},
                               {0, 1, 0, 0, 1, 0},
                               {0, 0, 1, 0, 0, 0},
                               {1, 0, 0, 1, 0, 0},
                               {0, 1, 0, 0, 1, 1},
                               {0, 0, 0, 0, 1, 1},};
    Solution a;
    cout<<a.findCircleNum(mat);
    return 0;
}