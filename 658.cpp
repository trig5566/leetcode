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
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto find_i = lower_bound(arr.begin(), arr.end(), x);
        vector<int> result(k);        
        int l, r;
        r = find_i - arr.begin();
        l = r - 1;
        int i = 0;
        for(;i < k && l >= 0 && r < arr.size(); i++){
            if(abs(arr[l] - x) > abs(arr[r] - x)){
                result[i] = arr[r];
                r++;
            } else {
                result[i] = arr[l];
                l--;
            }
        }
        if(l < 0)
            for(;i < k;i++, r++)
                result[i] = arr[r];
        if(r >= arr.size())
            for(;i < k;i++, l--)
                result[i] = arr[l];            
        sort(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution a;
    vector<int> test = {1, 2, 3, 4, 5};
    vector<int> result = a.findClosestElements(test, 4, 3);
    for(int i: result)
        cout<<i<<" ";
    return 0;
}