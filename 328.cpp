#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = head;
        ListNode* even = nullptr;
        ListNode* even_head = nullptr;
        ListNode* odd_n = nullptr;
        ListNode* even_n = nullptr;
        if(head == nullptr || odd->next == nullptr)
            return head;
        else{
            even = odd->next;
            even_head = odd->next;
        }
        odd_n = even->next;
        if(odd_n != nullptr)
            even_n = odd_n->next;
        else 
            return head;

        while(1){
            odd->next = odd_n;
            even->next = even_n;
            if(even_n == nullptr)
                break;
            odd = odd_n;
            odd_n = even_n->next;
            if(odd_n == nullptr)
                break;
            even = even_n;
            even_n = odd_n->next;
        }
        if(odd_n == nullptr)
            odd->next = even_head;
        else
            odd_n->next = even_head;
        return head;
    }
};