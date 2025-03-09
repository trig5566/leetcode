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

using namespace std;


class Solution {
    public:
        class Freq{
            public:
                char ch;
                int times;
            Freq(char ch_,int ti_){
                ch = ch_;
                times = ti_;
            }
            bool operator <(Freq b){
                return times < b.times;
            }
        };
        string frequencySort(string s) {
            unordered_map<char,int> record;
            vector<Freq> ch_freq;
            string result = "";
            if(s.empty())
                return result;
            ch_freq.push_back(Freq(0,0));
            int index = 1;
            for(char i:s){
                if(record[i] == 0){
                    record[i] = index++;
                    ch_freq.push_back(Freq(i,1));
                } else {
                    ch_freq[record[i]].times++;
                }
            }
            sort(ch_freq.begin(),ch_freq.end());
            for(int i = ch_freq.size()-1;i >= 1;i--){
                for(int j = 0;j < ch_freq[i].times;j++)
                    result += ch_freq[i].ch;
            }
            return result;
        }
    };

int main()
{
    Solution a;
    //string test = "acabacagbc";
    string test = "";
    cout<<a.frequencySort(test);
    return 0;
}