#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <stack>
#include <sstream>
#include <cmath>
#include <random>
#include <bitset>

using namespace std;

class Solution {
public:
    int flipLights(int n, int presses) {
        //A: do button 1
        //B: do button 2
        //C: do button 3
        //D: do button 4
        //if press is even, status includes 1. ABCD all do odd times, 2.ABCD all do even times, 3. two of ABCD do odd times and rest of them doing even times
        //1. = D 2. initial status = ~A 3. AB=C, AC=B, AD, BC= A, BD, CD
        //Total: D, initial status, C, B, AD, BD, CD
        //if press is odd, status includes 1. one of ABCD does odd times and rest of them doing even times 2. three of ABCD do odd times and rest of them doing even times
        //1. A, B, C, D
        //2. ABC = initial status, ABD = CD, ACD = BD, BCD = AD
        //Total: A, B, C, D, CD, BD
        unordered_map<string, int> tab;
        string origin_s = "";
        int result = 0;
        for(int i = 0; i < n; i++)
            origin_s += "1";
        vector<string> operation;
        if(presses % 2 == 0){
            if(presses >= 4)
                operation = {"1", "A", "AD", "B", "C", "D", "BD", "CD"};
            else if(presses == 2)
                operation = {"1", "A", "AD", "B", "C", "BD", "CD"};
            else
                operation = {"1"}; 
        } else {
            if(presses >= 3)
                operation = {"1", "A", "B", "C", "D", "BD", "CD", "AD"};
            else
                operation = {"A", "B", "C", "D"};
        }
        for(int i = 0; i < operation.size(); i++){
            string tmp = origin_s;
            for(int j = 0; j < operation[i].size();j++){
                switch(operation[i][j]){
                    case 'A':
                        for(int k = 0; k < tmp.size();k++)
                            if(tmp[k] == '1')
                                tmp[k] = '0';
                            else
                                tmp[k] = '1';
                        break;
                    case 'B':
                        for(int k = 1; k < tmp.size(); k += 2)
                            if(tmp[k] == '1')
                                tmp[k] = '0';
                            else
                                tmp[k] = '1';
                        break;
                    case 'C':
                        for(int k = 0; k < tmp.size(); k += 2)
                            if(tmp[k] == '1')
                                tmp[k] = '0';
                            else
                                tmp[k] = '1';
                        break;
                    case 'D':
                        for(int k = 0; k < tmp.size(); k += 3)
                            if(tmp[k] == '1')
                                tmp[k] = '0';
                            else
                                tmp[k] = '1';
                        break;
                    default:
                        break;
                }
            }
            if(tab[tmp] == 0){
                tab[tmp] = 1;
                cout<<"tmp:"<<tmp<<endl;
                result++;
            }
        }
        return result;
    }
};

int main()
{
    Solution a;
    cout<<a.flipLights(8, 3);
    return 0;
}