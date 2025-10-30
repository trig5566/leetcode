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
    vector<int>  time_record = vector<int>(24*60, 0);
    int findMinDifference(vector<string>& timePoints) {
        for(string i: timePoints){
            int pos = i.find(":");
            int hour_i = stoi(i.substr(0, pos));
            int minute_i = stoi(i.substr(pos+1, i.size() - (pos+1)));
            //cout<<"h_i:"<<hour_i<<" m_i:"<<minute_i<<endl;
            if(time_record[hour_i*60 + minute_i] == 1)
                return 0;
            else
                time_record[hour_i*60 + minute_i] = 1;
        }
        int min_v = INT_MAX;
        int pre = -1;
        int first = 0;
        for(int i = 0; i < 1440; i++){
            if(time_record[i] == 1){

                if(pre == -1){
                    first = i;
                } else { 
                    int temp = min((i - pre), 1440 - (i - pre));
                    if(temp < min_v)
                        min_v = temp;
                }
                pre = i;
            }
        }

        int temp = min((pre - first), 1440 - (pre - first));
        if(temp < min_v)
            min_v = temp;

        return min_v;
    }
};

int main()
{
    vector<string> test = {"23:45","16:46","08:55","04:05","20:59"};
    Solution a;
    cout<<a.findMinDifference(test);
}