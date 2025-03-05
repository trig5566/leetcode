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
        vector<int> findAnagrams(string s, string p) {
            int p_len = p.size();
            vector<int> result;
            vector<int> p_arr(26,0);
            vector<int> s_arr(26,0);        
            for(int i = 0; i < p_len; i++){
                p_arr[p[i]-'a']++;
                s_arr[s[i]-'a']++;          
            }       

            for(int i = 0; i+p_len-1 < s.size(); i++){
                int end = i+p_len-1;
                bool diff = 0;
                for(int j = 0;j < 26; j++){
                    if(p_arr[j] != s_arr[j]){
                        diff = 1;
                        break;
                    }
                }
                if(!diff)
                    result.push_back(i);

                if(end + 1 < s.size()){
                    s_arr[s[i]-'a']--;
                    s_arr[s[end + 1]-'a']++;
                }
            }
            return result;
        }
};

int main()
{
    Solution a;
    string test = "abab";
    vector<int> result = a.findAnagrams(test,"aba");
    for(int i:result)
        cout<<i<<",";
    return 0;
}