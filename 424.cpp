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
        int characterReplacement(string s, int k) {
            vector<int> map(26,0);
            int l = 0;
            int freq = 0;
            int result = 0;
            for(int r = 0; r < s.size(); r++){
                map[s[r] - 'A']++;
                freq = max(freq,map[s[r] - 'A']);
                while(r-l-freq > k){
                    map[s[l] - 'A']--;
                    l++;
                }
                result = max(result,r-l+1);
            }
            return result;
        }

};

int main()
{
    string test = "AAAAAAA";
    Solution a;
    cout << a.characterReplacement(test,2);
    return 0;
}