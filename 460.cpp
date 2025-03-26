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

class LFUCache {
    public:
        int n;
        int mini_freq;
        unordered_map<int,pair<int,int>>  key_tb;
        unordered_map<int,list<int>>  freq_tb;
        unordered_map<int,list<int>::iterator>  pos;
        LFUCache(int capacity) {
            n = capacity;
            mini_freq = 1;
        }
        
        int get(int key) {
            if(key_tb.find(key) == key_tb.end())
                return -1;             
            freq_tb[key_tb[key].first].erase(pos[key]);
            freq_tb[++key_tb[key].first].push_back(key);
            pos[key] = --freq_tb[key_tb[key].first].end();
            if(freq_tb[mini_freq].size() == 0)
                mini_freq++;
            return key_tb[key].second;
        }
        
        void put(int key, int value) {
            if(!n)
                return;
            if(key_tb.find(key) == key_tb.end()){
                if(key_tb.size() >= n){
                    int t_key = freq_tb[mini_freq].front();
                    key_tb.erase(t_key);
                    pos.erase(t_key);
                    freq_tb[mini_freq].pop_front();
                    if(freq_tb[mini_freq].size() == 0)
                        mini_freq++;
                } 
                key_tb[key] = pair<int,int>(1,value);
                freq_tb[1].push_back(key);
                pos[key] = --freq_tb[1].end();
                mini_freq = 1;               
            } else {
                int t_freq = key_tb[key].first;              
                freq_tb[t_freq].erase(pos[key]);
                freq_tb[++t_freq].push_back(key);
                pos[key] = --freq_tb[t_freq].end();
                if(freq_tb[mini_freq].size() == 0)
                    mini_freq++;
                key_tb[key].second = value;
                key_tb[key].first = t_freq;
            }

        }

};

int main(){
    LFUCache a = LFUCache(2);


 
    return 0;
}