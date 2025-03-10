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

        static bool myCompare(const vector<int> &a,const vector<int> &b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            } else
                return a[0] < b[0]; 
        }
        int findMinArrowShots(vector<vector<int>>& points) {
            int result = 1;
            if( points.size() <= 1)
                return  points.size();
            sort(points.begin(), points.end(), myCompare);
            int l = points[0][0];
            int r = points[0][1];

            for(int i = 0;i < points.size();i++){
                if(r < points[i][0]){
                    l = points[i][0];
                    r = points[i][1];
                    result++;
                } else {
                    l = points[i][0];
                    r = r < points[i][1] ? r:points[i][1];
                }
                
            }
            //for(int i = 0;i < points.size();i++)
                //cout<<"["<<points[i][0]<<","<<points[i][1]<<"]"<<endl;

            return result;
        }
};


int main()
{
    vector<vector<int>> test = {{1,2},{3,4},{2,3},{4,5},{1,3}};
    Solution a;
    cout<<a.findMinArrowShots(test);
    return 0;
}