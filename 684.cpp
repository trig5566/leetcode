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
    int union_find(vector<int> &s, int pos)
    {
        if(s[pos] == pos)
            return pos;
        s[pos] = union_find(s, s[pos]);
        return s[pos];
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> myset(1001, 0);
        vector<int> result(2, 0);
        for(int i = 0; edges.size(); i++){
            if(myset[edges[i][0]] == 0){
                myset[edges[i][0]] = edges[i][0];
            }

            if(myset[edges[i][1]] == 0){
                myset[edges[i][1]] = edges[i][1];
            }
            int node1 = union_find(myset, edges[i][0]);
            int node2 = union_find(myset, edges[i][1]);
            if(node1 == node2)
                return edges[i];
            else if(node1 < node2)
                myset[node2] = node1;
            else
                myset[node1] = node2;

        }
        return result;
    }
};

int main()
{
    //vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    Solution a;
    vector<int> result = a.findRedundantConnection(edges);
    cout<<"["<<result[0]<<","<<result[1]<<"]"<<endl;
    return 0;
}