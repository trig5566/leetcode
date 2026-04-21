#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

class MyCalendar {
public:
    vector<pair<int, int>> time_schulde;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        time_schulde.push_back(pair<int, int>(startTime, endTime));
        int start = 0;
        int interval = time_schulde.size()/2;
        while(interval > 0){

            interval = time_schulde.size()/2;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */