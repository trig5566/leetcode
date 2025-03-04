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

using namespace std;

class Solution {
    public:
        class Compare{
            public:
            bool operator()(const std::pair<int, int>& p1, const std::pair<int, int>& p2){
                return p1.second < p2.second;
            }
        };

        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            vector<pair<int,int>> list;
            int n = intervals.size();
            int result = 0;
            for(int i = 0; i < n; i++){
                list.push_back(pair<int,int>(intervals[i][0],intervals[i][1]));
            }
            sort(list.begin(),list.end(),Compare{});
            int r = -50001;

            for(int i = 0; i < n;i++){
                if(r <= list[i].first)
                    r = list[i].second;
                else
                    result++;
            }
            //for(int i = 0; i < n;i++)
            //    cout<<"["<<list[i].first<<","<<list[i].second<<"]"<<endl;
            return result;
        }
};

int main()
{
    Solution a;
    //vector<vector<int>> test = {{1,2},{2,3},{3,4},{1,3}};
    //vector<vector<int>> test = {{1,2},{1,2},{1,2}};
    //vector<vector<int>> test = {{-2,0},{-1,1},{1,2}};
    vector<vector<int>> test = {{1,2},{2,3}};
    cout<<a.eraseOverlapIntervals(test);
    return 0;
}