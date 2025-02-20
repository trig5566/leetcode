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

using namespace std;

class Solution {
    public:
        string decodeString(string s) {
            int ptr = 0;
            string result = "";
            stack<pair<string,int>> deal;
            string tmp_s = "";
            int tmp_i = 1;
            int stat = 0;
            for(int i = 0; i < s.size(); i++){
                //cout<<tmp_s<<endl;
                if(s[i] == ']'){
                    auto tmp = deal.top();
                    deal.pop();
                    string repeat = "";
                    for(int j = 0;j < tmp.second;j++){
                        repeat += tmp_s;
                    }
                    tmp_s = tmp.first + repeat;
                } else if(s[i] >= 'a' && s[i] <= 'z'){
                    if(stat == 0){
                        stat = 1;
                    }
                    tmp_s += s[i];
                } else if(s[i] >= '0' && s[i] <= '9'){
                    if(stat == 0 || stat == 1){
                        ptr = i;
                        stat = 2;
                    }
                } else if(s[i] == '['){
                    tmp_i = stoi(s.substr(ptr,i - ptr));
                    deal.push({tmp_s,tmp_i});
                    tmp_s = "";
                    tmp_i = 1;
                    stat = 0;
                }
            
            }
            return tmp_s;
        }
};

int main()
{
    Solution a;
    //string test = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    string test = "3[a2[c]]";
    cout<<a.decodeString(test);
    return 0;
}