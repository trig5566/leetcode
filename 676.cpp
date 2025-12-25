#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

class MagicDictionary {
public:
    class TriNode {
        public: 
            bool end;
            vector<TriNode *>letter;
            TriNode(){
                letter = vector<TriNode *>(26, nullptr);
                end = false;
            }
    };

    void builtTri(TriNode *root, string s, int pos){
        if(pos >= s.size()){
            root->end = true;
            return;
        }

        if(root->letter[s[pos] - 'a'] == nullptr)
            root->letter[s[pos] - 'a'] = new TriNode();

        builtTri(root->letter[s[pos] - 'a'], s, pos+1);
    }
    bool change_one;
    bool searchTri(TriNode *root, string s, int pos){
        if(root == nullptr)
            return false;

        if(pos == s.size()){
            if(root->end)
                return change_one;
            else
                return false;
        }

        if(root->letter[s[pos] - 'a'] != nullptr)
            return searchTri(root->letter[s[pos] - 'a'], s, pos + 1);
        else if(change_one == false){
            change_one = true;
            bool multi_result = false;
            for(int i = 0; i < 26; i++)
                if(root->letter[i] != nullptr)
                    multi_result |= searchTri(root->letter[i], s, pos + 1);
            return multi_result;
        } else
            return false;
    }

    TriNode *tri_root;
    MagicDictionary() {
        tri_root = new TriNode();
    }
    
    void buildDict(vector<string> dictionary) {
        for(string s : dictionary)
            builtTri(tri_root, s, 0);
    }
    
    bool search(string searchWord) {
        change_one = false;
        return searchTri(tri_root, searchWord, 0);
    }
};