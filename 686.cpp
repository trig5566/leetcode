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
    int repeatedStringMatch(string a, string b) {
        string tmp = "";
        int count = 0;
        for(int i = 0; i < b.size(); i += a.size()){
            tmp += a;
            count++;
        }
        int i = 0;
        for(; i < tmp.size(); i++){
            if(i + b.size() >tmp.size())
                break;
            if(tmp[i] == b[0] && tmp.substr(i, b.size()) == b)
                return count;
        }
        tmp += a;
        count++;
        for(; i < tmp.size(); i++){
            if(i + b.size() >tmp.size())
                break;
            if(tmp[i] == b[0] && tmp.substr(i, b.size()) == b)
                return count;
        }

        return -1;
    }
};

int main()
{
    string a = "ba";
    string b = "abababababababababab";
    Solution v;
    cout<<v.repeatedStringMatch(a, b);
    return 0;
}