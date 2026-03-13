#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct trie_tree{
    bool isExist;
    unordered_map<char, trie_tree*> ch_list;

    trie_tree() : isExist(false) {}
};

string getbigger(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) {
        return (s1.length() > s2.length()) ? s1 : s2;
    }
    return (s1 < s2) ? s1 : s2;
}

class Solution {
public:
    string longestWord(vector<string>& words) {
        trie_tree root;
        string result = "";
        std::sort(words.begin(), words.end(), [](const std::string& first, const std::string& second) {
        return first.length() < second.length();});
        root.isExist = true;
        for(string s: words){
            trie_tree *it = &root;
            
            bool isCandidate = true;
            //cout<<"it:";
            for(int i = 0; i < s.size(); i++){
                if(!it->isExist)
                    isCandidate = false;

                if(it->ch_list[s[i]] == nullptr)
                    it->ch_list[s[i]] = new trie_tree();
                //cout<<it<<",ex:"<<it->isExist;
                it = it->ch_list[s[i]];
            }
            it->isExist = true;
            if(isCandidate && result.size() <= s.size())
                result = getbigger(s, result);
            //cout<<"result:"<<result<<endl;
        }
        return result;
    }
};

int main()
{
    Solution a;
    vector<string> words = {"yo","ew","fc","zrc","yodn","fcm","qm","qmo","fcmz","z","ewq","yod","ewqz","y"}; //{"w","wo","wor","worl","world"};
    cout<<a.longestWord(words);
    return 0;
}