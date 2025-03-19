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
        vector<pair<int,int>> line;
        static bool mycompare(const pair<int,int> &a, const pair<int,int> &b){
            return a.first < b.first;
        }
        int findRadius(vector<int>& houses, vector<int>& heaters) {
            vector<int> heat_loc(heaters.size(),0);
            for(int i = 0; i < heaters.size();i++)
                line.push_back(pair<int,int>(heaters[i],1));

            for(int i = 0; i < houses.size();i++)
                line.push_back(pair<int,int>(houses[i],2));
            
            sort(line.begin(),line.end(),mycompare);
            int count = 0;
            for(int i = 0; i < line.size();i++){
                if(line[i].second == 1){
                    heat_loc[count] = i;
                    count++;
                }
                //cout<<"line["<<i<<"] = ("<<line[i].first<<","<<line[i].second<<")"<<endl;
            }
            if(heaters.size() == 1)
                return abs(line[0].first - line[heat_loc[0]].first) > abs(line[line.size()-1].first - line[heat_loc[count-1]].first)?
                abs(line[0].first - line[heat_loc[0]].first):abs(line[line.size()-1].first - line[heat_loc[count-1]].first);

            int radius = 0;
            if(line[0].first < line[heat_loc[0]].first)
                radius = line[heat_loc[0]].first - line[0].first;
            if(radius < line[line.size()-1].first - line[heat_loc[count-1]].first)
                radius = line[line.size()-1].first - line[heat_loc[count-1]].first;
            //cout<<"r:"<<radius<<endl;
            for(int i = 1; i < count;i++){
                int l = heat_loc[i-1];
                int r = heat_loc[i];
                int l_move = l + 1;
                int r_move = r - 1;
                while(l_move <= r_move){
                    int line_len = 0;
                    if(line[l_move].first - line[l].first > line[r].first - line[r_move].first){
                        line_len = line[r].first - line[r_move].first;
                        //cout<<"line_len:"<<line[r].first - line[r_move].first<<endl;
                        r_move--;
                    } else {
                        line_len = line[l_move].first - line[l].first;
                        //cout<<"line_len:"<<line[l_move].first - line[l].first<<endl;
                        l_move++;
                    }
                    if(line_len > radius)
                        radius = line_len;
                    //cout<<"r:"<<radius<<endl;
                }
            }
            return radius;

        }
};

int main()
{
    Solution a;
    vector<int>houses = {1};
    vector<int> heaters = {2};
    cout<<a.findRadius(houses,heaters);
    return 0;
}