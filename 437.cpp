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



//Definition for a binary tree node.
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
        int result = 0;
        int pathSum(TreeNode* root, int targetSum) {
            if(root){
                get_sum(root, targetSum);
                pathSum(root->left, targetSum);
                pathSum(root->right, targetSum);
            }
            return result;
        }

        void get_sum(TreeNode* root, long targetSum){

            if(root == NULL)
                return;

            if(root->val == targetSum)
                result++;

            get_sum(root->left,targetSum - root->val);
            
            get_sum(root->right,targetSum - root->val);
            
        }

};