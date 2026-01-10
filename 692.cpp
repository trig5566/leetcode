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
    static bool word_info_compare(pair<string, int> a, pair<string, int> b){
        if(a.second == b.second){
            return a.first < b.first;
        } else
            return a.second > b.second;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> times_table;        
        vector<string> result;
        for(int i = 0; i < words.size(); i++){
            times_table[words[i]]++;
        }
        vector<pair<string, int>> word_table(times_table.begin(), times_table.end());

        sort(word_table.begin(), word_table.end(), word_info_compare);
        
        for(int i = 0; i < k; i++){
            result.push_back(word_table[i].first);
        }
        return result;
    }
};