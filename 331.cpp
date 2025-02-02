#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> stack_s;
    bool isValidSerialization(string preorder) 
    {
        vector<string> handled = split(preorder,',');
        for(int i = 0; i < handled.size(); i++){
            if(handled[i].compare("#") == 0)
                stack_s.push_back(2);
            else 
                stack_s.push_back(1);
            s_check();
        }
        if(stack_s.size() == 1 && stack_s[0] == 2)
            return true;
        return false;
    }

    const vector<string> split(const string &str, const char &delimiter) {
        vector<string> result;
        stringstream ss(str);
        string tok;

        while (std::getline(ss, tok, delimiter)) {
            result.push_back(tok);
        }
        return result;
    }

    void s_check()
    {        
        while(stack_s.size() > 2){
            if(stack_s[stack_s.size()-1] == 2 && stack_s[stack_s.size()-2] == 2){
                stack_s.pop_back();
                stack_s.pop_back();
                if(stack_s[stack_s.size()-1] == 1)
                    stack_s[stack_s.size()-1] = 2;
                else
                    stack_s[stack_s.size()-1] = 0;
            }else
                break;
        }
    }

};

int main()
{
    string test = "9,#,#";
    Solution s;
    cout<<s.isValidSerialization(test);
}