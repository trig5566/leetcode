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


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<TreeNode *, int> hp;
    int same_index = 1;
    vector<TreeNode *> st;
    vector<TreeNode *> result;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root != nullptr){
            st.push_back(root);
            bfs(0);
        }
        
        while(!st.empty()){
            TreeNode *tmp = st.back();
            st.pop_back();
            find_the_same(tmp);
        }
        return result;
    }

    void bfs(int index){
        TreeNode* root = st[index];
        if(root->left != nullptr){
            st.push_back(root->left);
        }
        if(root->right != nullptr){
            st.push_back(root->right);
        }

        if(root->left == nullptr && root->left == nullptr)
            return;
        else
            bfs(index++);
    }

    void find_the_same(TreeNode *root){
        bool left_same = false;
        bool right_same = false;
        bool we_find_same = false;
        if(hp[root] == 0)
            hp[root] = same_index;
        else
            return; 

        for(int i = st.size()-1; i >= 0;i--){
            if(root->left == nullptr && st[i]->left == nullptr)
                left_same = true;
            else if(hp[root->left] != 0 && hp[root->left] == hp[st[i]->left])
                left_same = true;

            if(root->right == nullptr && st[i]->right == nullptr)
                right_same = true;
            else if(hp[root->right] != 0 && hp[root->right] == hp[st[i]->right])
                right_same = true;

            if(left_same && right_same && root->val == st[i]->val){
                hp[st[i]] = hp[root];
                we_find_same = true;
            }
        }
        if(we_find_same)
            result.push_back(root);
        same_index++;
    }

};