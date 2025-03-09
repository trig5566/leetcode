

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
        TreeNode* deleteNode(TreeNode* root, int key) {
            if(root == NULL)
                return root;
            TreeNode* it = root;
            TreeNode* pre = NULL;
            while(it != NULL){
                if(key == it->val){
                    if(it->left != NULL){
                        it
                    }
                    break;
                } else if(key > it->val)
                    it = it->right;
                else
                    it = it->left;
                pre = it;
            }
        }

        void move_to_end(TreeNode* tar, TreeNode* pre){
            if(tar->left == NULL && tar->right == NULL){
                tar = NULL;
            }else if(tar->left != NULL){
                TreeNode* swap_tar = (tar->left->left == NULL?tar->left:tar->left->left);
                if(pre->left == tar)
                    pre->left = 
            }
        }

        TreeNode* swap_tn(TreeNode* a, TreeNode* b){
            TreeNode* tmp_r = a->right == b?a:a->right;
            TreeNode* tmp_l = a->left == b?a:a->left;
            TreeNode* parent;
            if(a->right == b || a->left == b){
                parent = b;
            }
            a->left = b->left;
            a->right = b->right;
            b->left = tmp_l;
            b->right = tmp_r;
            return b;
        }
};