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
    string predictPartyVictory(string senate) {
        vector<bool> ban(senate.size(), 0);
        int start = 0;
        bool isR = (senate[0] == 'R');
        while(1){
            if(ban[start] == 0){
                cout<<"start["<<start<<"] is process"<<""<<endl;
                int i = 1;
                for(; i < senate.size();i++){
                    int tmp_index = (start + i)%senate.size();                   
                    if((isR ^ senate[tmp_index] == 'R') && ban[tmp_index] == 0){
                        ban[tmp_index] = 1;
                        cout<<"["<<tmp_index<<"] is banned"<<endl;
                        break;
                    }
                }
                if(i == senate.size()){
                    if(senate[start] == 'R')
                        return "Radiant";
                    else
                        return "Dire"; 
                }
            } 
            start = (start+1) % senate.size();
            isR = (senate[start] == 'R');
        }
        return ""; 
    }
};

int main()
{
    Solution a;
    string test = "RD";
    cout << a.predictPartyVictory(test);
    return 0;
}