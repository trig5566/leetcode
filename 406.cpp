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

using namespace std;



class Solution {
    public:
        typedef pair<int, int> pi; 
        vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
            priority_queue<pi,vector<pi>,greater<pi>> pq;
            int n = people.size();
            vector<vector<int>> result(n,vector<int>(2,-1));
            for(int i = 0; i < n;i++){
                vector<int> num = people[i];
                //cout<<"["<<num[0]<<","<<num[1]<<"]"<<endl;
                pq.push(make_pair(num[0],num[1]));
            }

            while(!pq.empty()){
                pi temp = pq.top();
                pq.pop();
                int front = 0;
                int i = 0;
                for(;i < n && front <= temp.second;i++){
                    if(result[i][0] == -1 || result[i][0] >= temp.first)
                        front++;
                }
                result[i-1][0] = temp.first;
                result[i-1][1] = temp.second;

            }
            return result;
        }
};

int main()
{
    Solution a;
    //vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> people = {{7,0}};
    vector<vector<int>> result;
    result = a.reconstructQueue(people);
    for(int i = 0;i < result.size();i++){
        cout<<"["<<result[i][0]<<","<<result[i][1]<<"]"<<endl;
    }
    return 0;
}
