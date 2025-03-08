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

using namespace std;
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Codec {
    public:
    
        // Encodes a tree to a single string.
        string serialize(TreeNode* root) {
            string result = "";
            queue<TreeNode*> tq;
            tq.push(root);
            while(!tq.empty()){
                TreeNode* it = tq.front();
                tq.pop();
                if(it != NULL){
                    result.append(to_string(it->val));                   
                    tq.push(it->left);
                    tq.push(it->right);
                } else {
                    result.append(".");
                }
                result.append(",");
            }
            return result;
        }
    
        // Decodes your encoded data to tree.
        TreeNode* deserialize(string data) {
            queue<TreeNode**> tq;
            TreeNode** it = NULL;
            TreeNode* head = NULL;
            stringstream ss(data);
            char delimiter = ',';
            string token;
            if(data.size() < 1)
                return head;
            tq.push(&head);
            while(getline(ss,token,delimiter)){
                it = tq.front();
                tq.pop();
                if(token[0] == '.')
                    *it = NULL;
                else {
                    *it = new TreeNode(stoi(token));
                    tq.push(&(*it)->left);
                    tq.push(&(*it)->right);
                }
            }
            return head;
        }
    };


int main()
{
    Codec a;
    TreeNode* b = a.deserialize("4,.,2,1,.,.,3,.,3,.,.,");
    cout<<a.serialize(b);
    return 0;
}