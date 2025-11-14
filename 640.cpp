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
    
    string solveEquation(string equation) {
        string tmp = "";
        bool reversal = 0;
        bool isX = false;
        int x = 0;
        int var = 0;
        bool terminate = 0;
        bool add= 0;
        bool reversal_start = 0;

        for(int i = 0; i < equation.size(); i++){
            switch(equation[i]){
                case '+':
                    terminate = 1;
                    add = 1;
                    break;
                case '-':
                    if(tmp.size() > 0 || isX)
                        terminate = 1;
                    add = 1;
                    break;
                case '=':
                    reversal_start = 1;
                    terminate = 1;
                    break;
                case 'x':
                    isX = true;
                    break;
                default:
                    tmp += equation[i];
                    break;
            }

            if(i == equation.size()-1)
                terminate = 1;

            if(terminate){
                if(isX){
                    if(tmp.size() == 0){
                        if(reversal)
                            x -= 1;
                        else 
                            x += 1;
                    } else if(tmp.size() == 1 && ((tmp[0] == '+') || (tmp[0] == '-')) ) {
                        if(reversal ^ (tmp[0] == '+'))
                            x += 1;
                        else
                            x -= 1;
                    } else {
                        if(reversal)
                            x -= stoi(tmp);
                        else
                            x += stoi(tmp);
                    }
                    isX = 0;
                } else {
                    if(tmp.size() > 0){
                        if(reversal)
                            var -= stoi(tmp);
                        else
                            var += stoi(tmp);
                    }
                }
                terminate = 0;
                tmp = "";
                isX = false;
            }

            if(reversal_start)
                reversal = 1;

            if(add){
                tmp += equation[i];
                add = 0;
            }
            cout<<"x="<<x<<" var="<<var<<endl;
        }

        cout<<"x="<<x<<" var="<<var<<endl;
        if(x == 0 && var == 0)
            return "Infinite solutions";
        else if(x == 0)
            return "No solution";
        
        string result = "x=" + to_string(-(var/x));
        return result;
    }
};

int main()
{
    Solution a;
    string test = "x-10=10-x+x+2x";
    cout<<a.solveEquation(test);
    return 0;
}