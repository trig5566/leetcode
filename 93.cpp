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
    vector<string> result;
    void sep_ip(string &s, vector<int> &ip_dot, int start_pos, int dot_num)
    {
        //cout<<s.substr(start_pos)<<endl;
        if(dot_num == 3 && stoi(s.substr(start_pos)) >= 0 && stoi(s.substr(start_pos)) < 256){
            if(s[start_pos] == '0' &&  s.size() - start_pos > 1)
                return;
            string tmp = s;
            tmp.insert(start_pos, ".");
            for(int i = ip_dot.size() - 1; i > 0; i--){
                tmp.insert(ip_dot[i], ".");
            }
            //cout<<tmp<<endl;
            result.push_back(tmp);
            return;
        }
        if(dot_num >= 3)
            return;
        if(s[start_pos] == '0' && start_pos + 1 < s.size()){
            ip_dot.push_back(start_pos);
            sep_ip(s, ip_dot, start_pos + 1, dot_num + 1);
            ip_dot.pop_back();
            return ;
        }
        for(int i = 1; i < 4 && start_pos + i < s.size(); i++){
            //cout<<s.substr(start_pos, i)<<endl;
            int num_s = stoi(s.substr(start_pos, i));
            if(num_s > 0 && num_s < 256){
                ip_dot.push_back(start_pos);
                sep_ip(s, ip_dot, start_pos + i, dot_num + 1);
                ip_dot.pop_back();
            }
                       
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<int> ip_dot;
        if(s.size() < 4 || s.size() > 12)
            return result;
        sep_ip(s, ip_dot, 0, 0);
        return result;
    }
};

int main()
{
    Solution a;
    string test = "0690";
    vector<string> result = a.restoreIpAddresses(test);
    for(auto i: result)
        cout<<i<<endl;
    return 0;
}