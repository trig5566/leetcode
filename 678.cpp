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
    bool checkValidString(string s) {
        stack<int> st;
        stack<int> sp;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')'){
                if(!st.empty()){                   
                    st.pop();
                } else if(!sp.empty())
                    sp.pop();
                else
                    return false;
            } else if(s[i] == '*'){
                sp.push(i);
            }
        }
        while(!st.empty() && !sp.empty()){
            if(st.top() > sp.top())
                return false;
            else {
                st.pop();
                sp.pop();
            }
        }

        if(st.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    string s = "(()((*((**))(*))*)))";
    Solution a;
    cout<<a.checkValidString(s);
    return 0;
}