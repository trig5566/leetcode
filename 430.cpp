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


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
    public:
        stack<Node*> ptr_list;
        Node* flatten(Node* head) {
            Node* it = head;
            while(it != NULL || !ptr_list.empty()){
                if(it->child != NULL){
                    if(it->next != NULL)
                        ptr_list.push(it->next);
                    it->next = it->child;
                    it->child->prev = it;
                    it->child = NULL;
                }

                if(it->next == NULL && !ptr_list.empty()){
                    Node* tmp = ptr_list.top();
                    ptr_list.pop();
                    it->next = tmp;
                    tmp->prev = it;
                }

                it = it->next;
            }

            return head;
        }
};