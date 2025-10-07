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
    int nextGreaterElement(int n) {   
        if(n < 10 || n == INT32_MAX)    
            return -1;
        vector<int> result;
        long my_result = 0;
        while(n > 0){           
            result.push_back(n%10);
            n /= 10;
        }
        int i = 1;
        for(i = 1; i < result.size(); i++){
            int higher_than_first = 10;
            int j_temp = 0;
            for(int j = 0; j < i; j++){               
                if(result[j] > result[i] && result[j] < higher_than_first){
                    higher_than_first = result[j];
                    j_temp = j;
                }
            }
            if(higher_than_first != 10){
                swap(result[i], result[j_temp]);
                sort(result.begin(), result.begin()+i, std::greater<int>());
                break;
            }
        }

        if(i == result.size())
            return -1;

        for(i = 0;i < result.size();i++)
            my_result += pow(10, i)*result[i];
        
        if(my_result > INT32_MAX)
            return -1;
        
        return my_result;
    }
};

int main()
{
    Solution a;
    int test = 456783423;
    cout<<a.nextGreaterElement(test);
    return 0;
}