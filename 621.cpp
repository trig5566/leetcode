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
    int leastInterval(vector<char>& tasks, int n) {
        int result = 0;
        vector<int> times = vector<int>(26, 0);
        for(int i = 0; i < tasks.size();i++)
            times[tasks[i] - 'A']++;

        int acc = 0;
        unsigned int bitmask = 0;
        for(int i = 0; i < tasks.size();i++){
            int high = the_highest_one(times, bitmask);
            acc++;
            if(high == -1 || acc > n){
                result += (n+1);
                acc = 0;
                bitmask = 0;
                cout<<"done."<<endl;
                if(high == -1)
                    i--;
            }          
        }
        return result + acc;
    }

    int the_highest_one(vector<int> &times, unsigned int &bitmask){
        int highest_p = -1;
        int highest = 0;
        for(int i = 0; i < 26;i++){
            if( ((0x1<<i) & bitmask) == 0 && times[i] > highest){
                highest_p = i;
                highest = times[i];
            }
        }
        if(highest_p != -1){
            cout<<"highest:"<<(char)('A'+highest_p)<<" times:"<<times[highest_p]<<endl;
            times[highest_p]--;
            bitmask |= (1 << highest_p);
        }

        return highest_p;
    }
};

int main()
{
    Solution a;
    //vector<char> test = {'A','A','C','B','B','B','Z','Z','C','X','X','D'};
    vector<char> test = {'A','A','A','B','B','B'};
    //vector<char> test = {'B'};
    cout<<a.leastInterval(test, 3);
    return 0;
}