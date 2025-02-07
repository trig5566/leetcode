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
    unordered_map<int,int> hashtable;

    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> freq(n+1);
        vector<int> result;
        for(int i:nums)hashtable[i]++;
        for(auto [a,b]:hashtable)freq[b].push_back(a);
        for(int i = freq.size()-1;i >= 0;i--)          
            for(int j : freq[i]){
                if(result.size() == k)
                    return result;
                result.push_back(j);
            }
        return result;
    }
};

int main()
{
    vector<int> test = {4,1,-1,2,-1,2,3};
    Solution a;
    vector<int> result = a.topKFrequent(test,2);
    for(int i: result){
        cout<<i<<" ";
    }
}