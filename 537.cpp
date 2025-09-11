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
    vector<string> split(string &target, string &delimiter){
        vector<string> result;
        int find_pos = target.find(delimiter);

        result.push_back(target.substr(0, find_pos));
        result.push_back(target.substr(find_pos + 1, (target.size() - find_pos -2)));
        
        return result;
    }
    string complexNumberMultiply(string num1, string num2) {
        string delimiter = "+";
        vector<string> data1 = split(num1, delimiter);
        vector<string> data2 = split(num2, delimiter);
        int data1_1 = stoi(data1[0]);
        int data1_2 = stoi(data1[1]);
        int data2_1 = stoi(data2[0]);
        int data2_2 = stoi(data2[1]);
        cout << "1_1:" <<data1_1<<" 1_2:"<<data1_2<<" 2_1:" <<data2_1<<" 2_2:"<<data2_2<<endl; 
        int integer = data1_1*data2_1 - data1_2*data2_2;
        int complex = data1_1*data2_2 + data1_2*data2_1;
        cout << "int:" <<integer<<" complex:"<<complex;
        string result = to_string(integer) + "+" + to_string(complex)+"i" ;//+ "i";
        return result;
    }
};

int main()
{
    Solution a;
    string test = "-234+-678i";
    string test2 = "456+598i";
    cout << "ans1:" <<a.complexNumberMultiply(test, test2); 
    //cout << "ans2:" <<a.complexNumberMultiply(test2, test2);
    return 0;
}