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
    vector<int> w_rang_high;
    vector<int> w_rang_low;
    int w_size;
    unsigned int total_accum = 0;
    Solution(vector<int>& w) {
        w_size = w.size();
        w_rang_high.resize(w.size(), 0);
        w_rang_low.resize(w.size(), 0);
        for(int i = 0; i < w.size();i++){
            w_rang_low[i] = total_accum;
            w_rang_high[i] = total_accum + w[i] - 1;
            total_accum += w[i];
        }
        /*cout<<"low: ";
        for(int i:w_rang_low)
            cout<<i<<" ";
        cout<<endl;
        cout<<"high:";
        for(int i:w_rang_high)
            cout<<i<<" ";
        cout<<endl;*/

    }
    
    int pickIndex() {
        if(w_size == 1)
            return 0;
        random_device my_ran;
        mt19937 gen(my_ran());
        uniform_int_distribution<> distrib(0, total_accum-1);
        unsigned int randomNumber = distrib(gen); 
        int left = 0;
        int right = w_size - 1;
        int mid = 0;
        //cout<<"random:"<<randomNumber;

        while (left <= right) {
        mid = left + (right - left) / 2; // 防止溢位

        if (randomNumber >= w_rang_low[mid] && randomNumber <= w_rang_high[mid])
            break; // 找到目標，回傳索引
        else if (randomNumber < w_rang_low[mid])
            right = mid - 1; // 搜尋左半邊
        else
            left = mid + 1; // 搜尋右半邊           
        }
        return mid;
    }
};


int main(){
    vector<int> test = {1, 3, 1, 5, 3, 4, 4};
    Solution a(test);
    for(int i = 0; i < 40;i++)
        cout<<a.pickIndex()<<" ";
    return 0;
}