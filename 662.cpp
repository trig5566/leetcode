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
    int widthOfBinaryTree(TreeNode* root) {
        int result = 1;
        find_depth(root, 0, 0);
        farthest_pos = vector<unsigned long long>(deepest+1, 0 );
        find_farthest(root, 0, 0);
        for(int i = farthest_pos.size()-1; i >= 0;i--){
            if(farthest_pos[i]+1 > result)
                result = farthest_pos[i]+1;
            
        }
        return result;
    }
    int deepest = -1;
    int farthest = 0;
    vector<unsigned long long> deepest_pos;
    vector<unsigned long long> farthest_pos;

    void find_depth(TreeNode* root, int lev, unsigned long long pos)
    {
        if(root == nullptr)
            return;
        if(lev > deepest){
            deepest = lev;
            deepest_pos.push_back(pos);
            //cout<<"deepest lev:"<<deepest<<", pos:"<<deepest_pos[lev]<<endl;
        }
        //cout<<"pos:"<<pos<<endl;
        find_depth(root->left, lev+1, pos<<1);
        find_depth(root->right, lev+1, (pos<<1)|1);
    }

    void find_farthest(TreeNode* root, int lev, unsigned long long pos)
    {
        if(root == nullptr)
            return;

        //cout<<"pos:"<<pos<<endl;
        if ((pos - deepest_pos[lev]) > farthest_pos[lev]) {
            farthest_pos[lev] = pos - deepest_pos[lev];
        }
        find_farthest(root->left, lev+1, pos<<1);
        find_farthest(root->right, lev+1, (pos<<1)|1);
    }

};