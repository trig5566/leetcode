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
        vector<int> result;
        vector<int> tmp_larg;
        int max_lay = 0;
        vector<int> largestValues(TreeNode* root) {
            if(root == NULL)
                return result;
            tmp_larg = vector<int>(10001,INT_MIN);
            find_row_max(root, 0);
            for(int i = 0; i <= max_lay; i++)
                result.push_back(tmp_larg[i]);
            
            return result;
        }
        void find_row_max(TreeNode* root, int layer){
            if(tmp_larg[layer] < root->val)
                tmp_larg[layer] = root->val;
            if(max_lay < layer)
                max_lay = layer;
            if(root->left == NULL && root->right == NULL){
                return ;
            }
            if(root->left != NULL)
                find_row_max(root->left, layer + 1);
            if(root->right != NULL)
                find_row_max(root->right, layer + 1);
        }
    };