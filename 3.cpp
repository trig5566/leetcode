#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        for(int i = 0;i < s.size();i++){
            pair<unordered_map<char, int>::iterator, bool> retPair;
            retPair = map.insert(std::pair<char, int>(s[i], i));
        }
    }
};