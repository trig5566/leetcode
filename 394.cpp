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
#define NUM_STAT 0
#define CHA_STAT 1
#define BRAC_STAT 2
        string decodeString(string s) {
            int ptr = 0;
            int state = NUM_STAT;
            string result = "";
            stack<int> st_num;
            stack<string> st_cha;
            int i = 0;
            for(i = 0; i < s.size(); i++){
                if(s[i] == '['){
                    if(state == CHA_STAT){
                        st_cha.push(s.substr(ptr,i-ptr));
                    } else if (state == NUM_STAT){
                        st_num.push(stoi(s.substr(ptr,i-ptr)));
                    }
                    state = BRAC_STAT;
                } else if (s[i] == ']'){
                    if(state = CHA_STAT)
                        st_cha.push(s.substr(ptr,i-ptr));
                    int num = st_num.top();
                    string cha = st_cha.top();
                    string tmp = "";
                    st_num.pop();
                    st_cha.pop();
                    for(int j = 0;j < num;j++){
                        tmp += cha;
                    }
                    if(!st_num.empty()){
                        if(!st_cha.empty()){
                            cha = st_cha.top();
                            st_cha.pop();
                        }else
                            cha = "";
                        cha += tmp;
                        st_cha.push(cha);
                    } else 
                        result += tmp;
                    state = BRAC_STAT;
                } else if(s[i] >= '0' && s[i] <= '9'){
                    if(state == CHA_STAT){
                        st_cha.push(s.substr(ptr,i-ptr));
                        state = NUM_STAT;
                        ptr = i;
                    } else if(state == BRAC_STAT){
                        state = NUM_STAT;
                        ptr = i;
                    }
                } else if(s[i] >= 'a' && s[i] <= 'z'){
                    if(state == NUM_STAT){
                        st_num.push(stoi(s.substr(ptr,i-ptr)));
                        state = CHA_STAT;
                        ptr = i; 
                    } else if(state == BRAC_STAT){
                        state = CHA_STAT;
                        ptr = i;
                    } 
                }
                    
            }
            if(state == CHA_STAT)
                result += s.substr(ptr,i-ptr);
            if(!st_cha.empty())
                result = st_cha.top() + result;
            return result;
        }
};

int main()
{
    Solution a;
   // string test = "asdc2[12[3[a]]]asd1[d]fc10[a]rfd";
    string test = "3[a2[c]]";
    cout<<a.decodeString(test);
    return 0;
}