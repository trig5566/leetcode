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


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(quadTree1->isLeaf)
            return quadTree1->val == 1?quadTree1:quadTree2;
        else if(quadTree2->isLeaf)
            return quadTree2->val == 1?quadTree2:quadTree1;
        else {
            Node* tl = intersect(quadTree1->topLeft, quadTree2->topLeft);
            Node* tr = intersect(quadTree1->topRight, quadTree2->topRight);
            Node* bl = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            Node* br = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
            Node *my_new = NULL;
            if(tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf){
                if(tl->val && tr->val && bl->val && br->val)
                    my_new = new Node(true, true);
                else if(!tl->val && !tr->val && !bl->val && !br->val)
                    my_new = new Node(false, true);
                else
                    my_new = new Node(0, false, tl, tr, bl, br);
            }
            else
                my_new = new Node(0, false, tl, tr, bl, br);
            return my_new;
        }
        
    }
};