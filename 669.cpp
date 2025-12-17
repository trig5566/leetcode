#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

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
    TreeNode* TrimBST(TreeNode* root, int low, int high) {
        if(root == nullptr)
            return nullptr;
        if(root->val < low){
            if(root->right != nullptr && root->right->val >= low)
                return root->right;
            else
                return nullptr;
        } else if(root->val > high) {
            if(root->left != nullptr && root->left->val <= high)
                return root->left;
            else
                return nullptr;
        } else {
            root->left = TrimBST(root->left, low, high);
            root->right = TrimBST(root->right, low, high);
            return root;
        }
    }
};