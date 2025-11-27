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
    int depth_lev = 0; 
    vector<vector<string>> result;
    vector<vector<string>> printTree(TreeNode* root) {
        if(root == nullptr)
            return result;
        fin_dep(root, 1);
        int n = pow(2, depth_lev) - 1;
        result = vector<vector<string>>(depth_lev, vector<string>(n));
        replace_node(root, 0, 0, n - 1);
        return result;
    }

    void replace_node(TreeNode* root, int lev, int l, int r){
        if(root == nullptr)
            return;
        result[lev][(l+r)/2] = to_string(root->val);
        replace_node(root->left, lev+1, l, ((r-l)/2+l)-1);
        replace_node(root->right, lev+1, ((r-l)/2+l)+1, r);
    }

    void fin_dep(TreeNode* root, int level){
        if(root == nullptr)
            return;

        if(level > depth_lev)
            depth_lev = level;
        if(root->left != nullptr)
            fin_dep(root->left, level+1);
        if(root->right != nullptr)
            fin_dep(root->right, level+1);
    }

}