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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return find_max_sub(nums, 0, nums.size());
    }

    TreeNode* find_max_sub(vector<int>& nums, int l, int r){
        if(l >= r)
            return nullptr;
        if(l+1 == r){
            TreeNode* tmp = new TreeNode(nums[l]);
            return tmp;
        }
        int my_max = nums[l];
        int max_index = l;
        for(int i = l+1; i < r; i++){
            if(nums[i] > my_max){
                my_max = nums[i];
                max_index = i;
            }
        }
        TreeNode* tmp = new TreeNode(nums[max_index]);
        tmp->left = find_max_sub(nums, l, max_index);
        tmp->right = find_max_sub(nums, max_index+1, r);
        return tmp;
    }

};