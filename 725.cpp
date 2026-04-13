#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int num = 0;
        vector<ListNode*> result;

        for(ListNode *it = head; it != nullptr; it = it->next)
            num++;    

        int group_num = num/k;
        int the_rest = num%k;
        ListNode *it = head;
        for(int i = 0; i < k; i++){
            int add = 0;
            if(the_rest){
                add = 1;
                the_rest--;
            }
            
            result.push_back(it);
            if(it != nullptr){
                for(int count = group_num + add; count > 1; count--)
                    it = it->next;

                ListNode *pre = it;
                it = it->next;
                pre->next = nullptr;
            }
        }

        return result;
    }
};
