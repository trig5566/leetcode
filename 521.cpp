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
        int findLUSlength(string a, string b) {
            int result = a.size() > b.size()?a.size():b.size();
            if(a.size() != b.size())
                return result;
            for(int i = 0;i < (a.size() > b.size()?b.size():a.size());i++){
                if(a[i] != b[i])
                    return result;
            }
            return -1;
        }
};

int main()
{
    return 0;
}