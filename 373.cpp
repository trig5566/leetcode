#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>
#include <sstream>
#include <cmath>
#include <unordered_map>

using namespace std;

class Solution {
    public:
    #define pii pair<int,int>
        vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
            priority_queue<pii,vector<pii>,greater<pii>> pq;
            vector<vector<int>> result = vector<vector<int>>(k,vector<int>(2,0));
            int count = 0;
            for(int i = 0;i < nums1.size();i++){
                pq.push(pair<int,int>(nums1[i]+nums2[0],0));
            }

            while(count < k){
                pair<int,int> tmp = pq.top();
                result[count][0] = tmp.first - nums2[tmp.second];
                result[count][1] = nums2[tmp.second];
                pq.pop();
                int next = tmp.second + 1;
                if(next < nums2.size()){
                    pq.push(pair<int,int>(tmp.first - nums2[tmp.second]+nums2[next],next));
                }
                count++;
            }

            return result;
        }
};

int main()
{
    vector<int> a = {1,2,3,4,5,6};
    vector<int> b = {1,2,3};
    Solution test;
    vector<vector<int>> result = test.kSmallestPairs(a,b,8);
    for(auto i : result){
        for(auto j: i)
            cout << j <<",";
        cout << endl;
    }
    return 0;
}