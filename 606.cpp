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
    string result = "";
    string tree2str(TreeNode* root) {
        middle_fun(root);
        return result;
    }

    void middle_fun(TreeNode* root){
        if(root == nullptr)
            return;
        result += to_string(root->val);
        if(root->left){
            result += "(";
            result += tree2str(root->left);
            result += ")";
        }else if(root->right){
            result += "()";
        }

        if(root->right){
            result += "(";
            result += tree2str(root->right);
            result += ")";
        }
        
    }
};