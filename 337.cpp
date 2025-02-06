#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <math.h>

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
    struct revenue {
        int selected;
        int unselected;
    };

    int rob(TreeNode* root) {
        revenue result = rob_algo(root);
        return max(result.selected,result.unselected);
    }

    revenue rob_algo(TreeNode* root){
        revenue result;
        if(root == nullptr){
            result.selected = 0;
            result.unselected = 0;
            return result;
        }
        revenue r_l = rob_algo(root->left);
        revenue r_r = rob_algo(root->right);
        result.selected = root->val + r_l.unselected + r_r.unselected;
        result.unselected = max(r_l.selected,r_l.unselected) + max(r_r.selected,r_r.unselected);
        return result;
    }
};