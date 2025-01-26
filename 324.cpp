#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mid = (mid%2 == 1?n/2+1:n/2);
        for(int i = mid,j = 2; i < n && j < mid; i++){

        }
    }
};