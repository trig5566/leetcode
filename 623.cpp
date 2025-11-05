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
    int goal_dep = 0; 
    int goal_val = 0; 
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        goal_dep = depth;
        goal_val = val;
        if(depth == 1){
            TreeNode * tmp = new TreeNode(goal_val, root, nullptr);
            return tmp;
        }
        add_node(root, 1);
        return root;
    }

    void add_node(TreeNode* root, int depth){
        if(root == nullptr)
            return;
        if(depth + 1 == goal_dep){
            TreeNode * tmp = root->left;
            root->left = new TreeNode(goal_val, tmp, nullptr);
            tmp = root->right;
            root->right = new TreeNode(goal_val, nullptr, tmp);
        }
        add_node(root->left, depth + 1);
        add_node(root->right, depth + 1);
    }
};