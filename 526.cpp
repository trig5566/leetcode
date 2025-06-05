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
    int result = 0;
    void set_find_perm(set<int> &remaining, int level){
        if(level == 0){
            result++;
            return;
        }
        set<int> temp = remaining;
        for(auto i : temp){
            remaining.erase(i);
            if((level % i == 0) || (i % level == 0)){
                set_find_perm(remaining, level-1);
            }
            remaining.insert(i);
        }
    }

    int countArrangement(int n) {
        set<int> remaining;
        for(int i = 1; i <= n; i++){
            remaining.insert(i);
        }
        set_find_perm(remaining, n);

        return result;
    }
};

int main(){
    Solution a;
    cout << a.countArrangement(15);
    return 0;
}