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
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
    public:
        vector<vector<int>> ans;
        vector<vector<int>> levelOrder(Node* root) {
            ans.push_back({root->val});
            vector<Node*> new_list = get_new_list(root->children);
            while(new_list.size() != 0){
                new_list = get_new_list(new_list);
            }
            return ans;
        }

        vector<Node*> get_new_list(vector<Node*> list){
            vector<Node*> result;
            vector<int> list_val;
            for(Node *it:list){
                list_val.push_back(it->val);
                for(Node *jt:it->children)
                    result.push_back(jt);
            }
            ans.push_back(list_val);
            return result;
        }

    };