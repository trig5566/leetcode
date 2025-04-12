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

        unordered_map<int,int> unused_map;
        int size;
        int my_m, my_n;
        Solution(int m, int n) {
            my_m = m;
            my_n = n;
            size = m*n;
            srand(time(NULL));
        }
        
        vector<int> flip() {
            vector<int> result;
            if(size <= 0)
                return result;
            int x = rand()%(size);
            result = vector<int>(2,0);
            int used = 0;
            used = unused_map[x] ? unused_map[x] : x;
            size--;
            unused_map[x] = unused_map[size] ? unused_map[size] : size ;
            result[0] = used/my_n;
            result[1] = used%my_n;
            return result;
        }
        
        void reset() {
            size = my_m*my_n;
            unused_map.clear();            
        }
};

int main()
{
    Solution a(2, 1);
    vector<int> result1;
    vector<int> result2;
    for(int i = 0; i < 100;i++){
        result1 = a.flip();
        //cout<<"("<<result1[0]<<","<<result1[1]<<")"<<endl;
        result2 = a.flip();
        //cout<<"("<<result2[0]<<","<<result2[1]<<")"<<endl;
        if(result1[0] == result2[0] && result1[1] == result2[1])
            cout<<"error";
        a.reset();
    }
    return 0; 
}