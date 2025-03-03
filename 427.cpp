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
#define ALL_SAME(x,y) (grid[y][x] == grid[y+1][x] && grid[y][x] == grid[y][x+1] && grid[y][x] == grid[y+1][x+1])
#define NEED_MERGE(a,b,c,d) (a->isLeaf && b->isLeaf && c->isLeaf && d->isLeaf && (a->val == b->val && a->val == c->val && a->val == d->val))
    public:
        Node* construct(vector<vector<int>>& grid) {
            return divide(grid,0,0,grid.size());
        }

        Node* divide(vector<vector<int>>& grid,int x,int y,int len){
            Node* it = NULL;
            if(len < 2){
                it = new Node(grid[y][x],true);
            } else if(len == 2){
                if(ALL_SAME(x,y)){
                    it = new Node(grid[y][x],true);
                } else {
                    it = new Node(1, 0,new Node(grid[y][x],true),new Node(grid[y][x+1],true),
                    new Node(grid[y+1][x],true),new Node(grid[y+1][x+1],true));
                }
            } else {
                int len2 = len/2;
                Node* tL;
                Node* tR;
                Node* bL;
                Node* bR;
                tL = divide(grid,x,y,len2);
                tR = divide(grid,x+len2,y,len2);
                bL = divide(grid,x,y+len2,len2);
                bR = divide(grid,x+len2,y+len2,len2);
                if(NEED_MERGE(tL,tR,bL,bR)){
                    it = new Node(tL->val,true);
                } else {
                    it = new Node(1, 0, tL, tR, bL, bR) ;
                }
            }
            return it;
        }

    };