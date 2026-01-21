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

class MyLinkedList {
public:
    class node{
        public:
        int val;
        node *next;
        node(int val_){
            val = val_;
            next = nullptr;
        }
    };
    node *root;
    node *tail;
    MyLinkedList() {
        root = new node(0);
    }
    
    int get(int index) {
        
        int i = 0;
        for(node *it = root->next; it != nullptr; it = it->next){
            if(i == index)
                return it->val;
            i++;
        }

        return -1;
    }
    
    void addAtHead(int val) {
        if(root->next == nullptr){
            root->next = new node(val);
            tail = root->next;
            return ;
        }

        node *tmp = root->next;
        root->next = new node(val);
        root->next->next = tmp;

    }
    
    void addAtTail(int val) {
        if(root->next == nullptr){
            root->next = new node(val);
            tail = root->next;
            return ;
        }
        tail->next = new node(val);
        tail = tail->next;
    }
    
    void addAtIndex(int index, int val) {
        int i = 0;
        for(node *it = root->next; it != nullptr; it = it->next){
            if(i == index){
                node *tmp = it->next;
                it->next = new node(val);
                it->next->next = tmp;
                if(it == tail)
                    tail = it->next;
            }
            i++;
        }

    }
    
    void deleteAtIndex(int index) {
        int i = 0;
        node *pre = root;
        for(node *it = root->next; it != nullptr; it = it->next){
            if(i == index){
                node *tmp = it->next;
                pre->next = it->next;
                if(it == tail)
                    tail = pre;
            }
            i++;
            pre = it;
        }        
    }
};