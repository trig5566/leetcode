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
            bool operator <(const Distance_W &b){
                return (dis < b.dis);
            };
            bool operator ==(const Distance_W &b){
                return (dis == b.dis);
            };
        };
        int numberOfBoomerangs(vector<vector<int>>& points) {
            int n = points.size();
            vector<vector<Distance_W>> p_list(n);
            int result = 0;
            for(int i = 0;i < n; i++){
                for(int j = 0; j < n;j++){
                    if(i == j)
                        continue;
                    double a = pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2);
                    p_list[i].push_back(Distance_W(a,j));
                }
                sort(p_list[i].begin(),p_list[i].end());
                //for(Distance_W k: p_list[i])
                    //cout<<"("<<k.dis<<","<<k.p_index<<")";
                //cout<<endl;
            }

            for(int i = 0; i < n; i++){
                int acc = 0;
                int old_dis = 0;
                for(int j = 0; j < p_list[i].size();j++){
                    if(old_dis != p_list[i][j].dis){
                        old_dis = p_list[i][j].dis;                      
                        if(acc >= 2)
                            result += (acc*(acc-1));
                        acc = 1;
                    } else 
                        acc++;
                }
                if(acc >= 2)
                    result += acc*(acc-1);
            }
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