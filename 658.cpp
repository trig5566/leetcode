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
        l = find_i - arr.begin();
        if(l > 0){
            if(abs(arr[l-1] - x) > abs(arr[l] - x)){
                r = l+1;
            } else {
                r = l;
                l = l-1;
            }
        } else r = 1;
        //cout << "l:" << l << " r:"<< r <<endl;
        int i = 1;
        for(;i < k && (l - 1) >= 0 && r < arr.size(); i++){
            if(abs(arr[l-1] - x) > abs(arr[r] - x))
                r++;
            else
                l--;
        }
        if(l == 0)
            for(;i < k;i++, r++);       
        
        if(r == arr.size())
            for(;i < k;i++, l--);         
        //cout << "l:" << l << " r:"<< r <<endl;
        i = 0;       
        for(int j = l; j < r;j++, i++)
            result[i] = arr[j]; 
        
        return result;
    }
};

int main()
{
    Solution a;
    //vector<int> test = {1, 2, 3, 3, 3, 4, 5};
    vector<int> test = {3,5,8,10};
    vector<int> result = a.findClosestElements(test, 2, 15);
    for(int i: result)
        cout<<i<<" ";
    return 0;
}