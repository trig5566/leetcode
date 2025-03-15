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
        vector<char> can_stat = vector<char>(1<<20,0);
    public:
        bool canIWin(int maxChoosableInteger, int desiredTotal) {
            if(desiredTotal <= maxChoosableInteger)
                return true;
            int total = maxChoosableInteger*(maxChoosableInteger+1)/2;
            if(total < desiredTotal)
                return false;
            return canwin(maxChoosableInteger,desiredTotal,0);
        }

        bool canwin(int m, int d, int status){
            if(can_stat[status] != 0)              
                return can_stat[status] == 1?true:false;
            
            if(d <= 0){
                //can_stat[status] = 2;
                return false;
            }
            for(int i = 0;i < m;i++){
                if((status & (1<<i)) == 0 && !canwin(m, d-i-1, status | (1<<i))){
                    can_stat[status] = 1;
                    //cout<<bitset<8>(status)<<":"<<1<<endl;
                    return true;
                }
            }
            can_stat[status] = 2;
            //cout<<bitset<8>(status)<<":"<<2<<endl;
            return false;
        }
};

int main()
{
    Solution a;
    cout<<a.canIWin(5,14);
}