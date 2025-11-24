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
    static bool compare(const vector<int>& a, const vector<int>& b) {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int result = 0;
        sort(pairs.begin(), pairs.end(), compare);
        for(int i = 0; i < pairs.size(); i++){
            cout<<"my["<<i<<"]:"<<pairs[i][0]<<","<<pairs[i][1]<<endl;
        }
        int start = INT_MIN;
        for(int i = 0; i < pairs.size(); i++){
            if(pairs[i][0] > start){
                result++;
                start = pairs[i][1];
            }
        }
        return result;
    }

};

int main() {
   Solution a;
   vector<vector<int>> test = {{-10,-8},{8,9},{-5,0},{6,10},{-6,-4},{1,7},{9,10},{-4,7}};
   cout<<a.findLongestChain(test);
return 0;
}