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
        class IntVal{
            public:
                int l;
                int r;
                int i;
                IntVal(int l_,int r_,int i_){
                    l = l_;
                    r = r_;
                    i = i_;
                }

                bool operator < (const IntVal& p1) const {
                    return l < p1.l;
                }

                bool operator == ( IntVal * n ) const {
                    return l == n->l;
                }
        };

        int bin_ser(vector<IntVal> &list,int val){
            int start = 0;
            int end = list.size()-1;
            if(list.size() == 0 || val > list[end].l)
                return -1;
            else if(list.size() == 2)
                return (val <= list[0].l)?list[0].i:list[1].i;
            int mid;
            while(end-start >= 2){
                mid = start + (end-start)/2;
                if(list[mid].l > val){
                    end = mid;
                }else if(list[mid].l < val){
                    start = mid;
                }else {
                    end = mid;
                    break;
                }
            }
            return list[end].i;
        }

        vector<int> findRightInterval(vector<vector<int>>& intervals) {
            vector<IntVal> list;
            vector<int> result;
            int n = intervals.size();
            for(int i = 0; i < n; i++){
                list.push_back(IntVal(intervals[i][0],intervals[i][1],i));
            }
            sort(list.begin(),list.end());

            for(int i = 0; i < n;i++){
                result.push_back(bin_ser(list,intervals[i][1]));
            }
            /*for(int i = 0; i < n; i++){
                cout<<"["<<list[i].l<<","<<list[i].r<<","<<list[i].i<<"]"<<endl;
            }*/
            return result;
        }
};

int main()
{
    vector<vector<int>> test = {{1,4},{2,3},{4,5},{0,1},{-1,4},{-2,0},{-3,-1},{6,8},{-8,-6}};
    Solution a;
    vector<int> result;
    result = a.findRightInterval(test);
    for(int i = 0;i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}