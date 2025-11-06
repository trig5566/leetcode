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
    int maxDistance(vector<vector<int>>& arrays) {
        int result = 0;
        int max_p = arrays[0][arrays[0].size()-1] > arrays[1][arrays[1].size()-1]? 0 : 1;
        int max_v = arrays[0][arrays[0].size()-1] > arrays[1][arrays[1].size()-1]? arrays[0][arrays[0].size()-1]: arrays[1][arrays[1].size()-1];
        int sec_max_v = arrays[0][arrays[0].size()-1] > arrays[1][arrays[1].size()-1]? arrays[1][arrays[1].size()-1]:arrays[0][arrays[0].size()-1];
        int min_p = arrays[0][0] < arrays[1][0]? 0 : 1;
        int min_v = arrays[0][0] < arrays[1][0]? arrays[0][0]:arrays[1][0];
        int sec_min_v = arrays[0][0] < arrays[1][0]? arrays[1][0]:arrays[0][0];
        for(int i = 2; i < arrays.size();i++){
            if(arrays[i][arrays[i].size()-1] >= max_v){
                sec_max_v = max_v;
                max_v = arrays[i][arrays[i].size()-1];
                max_p = i;
            } else if(arrays[i][arrays[i].size()-1] > sec_max_v){
                sec_max_v = arrays[i][arrays[i].size()-1];
            }

            if(arrays[i][0] <= min_v){
                sec_min_v = min_v;
                min_v = arrays[i][0];
                min_p = i;
            } else if(arrays[i][0] < sec_min_v){
                sec_min_v = arrays[i][0];
            }

        }

        if(max_p != min_p)
            return max_v - min_v;
        else{
            return max((max_v - sec_min_v), (sec_max_v - min_v));
        }
        

    }
};