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




class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
public:
    int result;
    unordered_map<int, Employee*> ht;
    void countImport(Employee* e){
        //if(e == nullptr)
        //    return;
        result += e->importance;
        for(int i = 0; i < e->subordinates.size(); i++){
            countImport(ht[e->subordinates[i]]);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        result = 0;
        ht.clear();
        for(int i = 0; i < employees.size(); i++){
           ht[employees[i]->id] = employees[i];
        }

        countImport(ht[id]);
        return result;
    }
};