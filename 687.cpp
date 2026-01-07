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
    int result; 

    int longestUnivaluePath(TreeNode* root) {
        result = 0;
        if(root == nullptr)
            return result;
 
        maxPath(root, root->val);
 
        return result;
    }

    int maxPath(TreeNode* root, int val){
        if(root == nullptr)
            return 0;
        else if(root->val != val){
            maxPath(root, root->val);
            return 0;
        }
        int left_len = 0;
        int right_len = 0;
        if(root->left != nullptr)
            left_len = maxPath(root->left, val);
        if(root->right != nullptr)
            right_len = maxPath(root->right, val);
        if(result < left_len + right_len)
            result = left_len + right_len;
        return max(left_len, right_len)+1;
    }
};