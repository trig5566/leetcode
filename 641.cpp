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

class MyCircularDeque {
public:
    vector<int> dq;
    int size = 0;
    int f_p = 0;
    int l_p = 0;
    int max_size = 0;
    MyCircularDeque(int k) {
        dq = vector<int>(k,0);
        max_size = k;
    }
    
    bool insertFront(int value) {
        if(isFull())
            return false;
        dq[f_p] = value;
        size++;
        if(--f_p < 0)
            f_p = max_size - 1;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())
            return false;
        l_p = (++l_p)%max_size;
        dq[l_p] = value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) 
            return false;        
        f_p = (++f_p)%max_size;  
        size--;    
        return true; 
    }
    
    bool deleteLast() {
        if(isEmpty()) 
            return false;
        if(--l_p < 0)
            l_p = max_size - 1;  
        size--;    
        return true;         
    }
    
    int getFront() {
        if(isEmpty()) 
            return -1; 
        return dq[(f_p+1)%max_size];
    }
    
    int getRear() {
        if(isEmpty()) 
            return -1;
        return dq[l_p];
    }
    
    bool isEmpty() {
        return f_p == l_p && size == 0;
    }
    
    bool isFull() {
        return f_p == l_p && size == max_size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */