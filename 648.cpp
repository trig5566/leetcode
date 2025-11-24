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

class Solution {
public:
    unordered_map<string, int> my_dict;

    vector<string> str_split(string sentence, char delimt){
        stringstream ss(sentence);
        vector<string> result;
        string token;
        while(getline(ss, token, delimt)){
            result.push_back(token);
        }
        return result;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for(int i = 0; i < dictionary.size(); i++){
            my_dict[dictionary[i]] = 1 ;             
        }
        vector<string> sentences = str_split(sentence, ' ');
        for(int i = 0; i < sentences.size(); i++){
            string tmp = "";
            for(int j = 0; j < sentences[i].size(); j++){
                tmp += sentences[i][j];
                if(my_dict[tmp]){
                    sentences[i] = tmp;
                    break;
                }
            }
        }
        string result = "";
        for(int i = 0; i < sentences.size(); i++){
            result += (sentences[i] + " ");
        }
        return result.substr(0, result.size()-1);
    }
};

int main()
{
    Solution a;
    //string test = "the cattle was rattled by the battery";
    string test = "a";
    vector<string> mydictionary = {"cat", "rat", "bat"};
    cout<<a.replaceWords(mydictionary, test);
    return 0;
}