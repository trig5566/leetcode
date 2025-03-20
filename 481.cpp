#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <bitset>

using namespace std;

class Solution {
    public:
        vector<int> mag_list;
        int magicalString(int n) {
            if(n == 0)
                return 0;
            else if(n < 3)
                return 1;
            int next = 1;
            int num_ptr = 2;
            int result = 0;
            mag_list.push_back(1);
            mag_list.push_back(2);
            mag_list.push_back(2);
            for(int i = 2;i < n;){
                int num = mag_list[num_ptr];
                for(int j = i;j < num+i && j < n; j++)
                    mag_list.push_back(next);
                i += num;
                next = (next == 2)?1:2;
                num_ptr++;               
            }
            for(int i = 0;i < n;i++)
                if(mag_list[i] == 1)
                    result++;

            return result;

        }
};

int main(){
    Solution a;
    cout<<a.magicalString(6);
    return 0;
}