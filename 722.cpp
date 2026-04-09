#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> result;
        int state = 0;//0 = normal, 1 = in block, 2 = in line
        string tmp = "";
        for(string i: source){
            int pre = 0; // 0 = else, 1 = /, 2 = *
            for(int j = 0; j < i.size(); j++){
                if(i[j] == '/'){
                    if(state == 0){
                        tmp += '/';
                        if(pre == 1){
                            tmp.pop_back();
                            tmp.pop_back();
                            break;
                        }
                        pre = 1;
                    } else {
                        if(pre == 2){
                            state = 0;
                            pre = 0;
                            continue;
                        }
                        pre = 1;
                    }                   
                } else if(i[j] == '*'){   
                    if(state == 0){
                        tmp += '*';                
                        if(pre == 1){
                            state = 1;
                            tmp.pop_back();
                            tmp.pop_back();
                            pre = 0;
                            continue;
                        }
                        pre = 2;
                    } else 
                        pre = 2;
                } else {
                    if(state == 0){
                        tmp += i[j];
                    }
                    pre = 0;
                }
            }
            if(!tmp.empty())
                if(state == 0 ){
                    result.push_back(tmp);
                    tmp = "";
                }
        }
        return result;
    }
};

int main()
{
    vector<string> test = {"/*Test program */", "int main()", "{ ", "  // variable declaration ", "int a, b, c;","/", "*/* //This is a test", "   /*multiline  ",
         " /***  comment for ", "///***   testing */", "a = b + c;", "}"};
    Solution a;
    vector<string> result = a.removeComments(test);
    for(string i: result)
        cout<<i<<endl;
    return 0;
}