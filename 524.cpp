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
        string findLongestWord(string s, vector<string>& dictionary) {
            vector<string> result_list;
            int max_length = 0;
            for(int i = 0; i < dictionary.size();i++){
                if(s1IsSubseqOfS2(dictionary[i], s)){
                    if(dictionary[i].size() > max_length){
                        result_list.clear();
                        result_list.push_back(dictionary[i]);
                        max_length = dictionary[i].size();
                    }else if(dictionary[i].size() == max_length){
                        result_list.push_back(dictionary[i]);
                    }
                }
            }
            if(result_list.empty())
                return "";
            sort(result_list.begin(), result_list.end());
            for(string s: result_list)
                cout<<s<<endl;
            return result_list[0];
        }
        
        bool s1IsSubseqOfS2(string s1, string s2){
            if(s1.size() > s2.size())
                return false;
            int i = 0;
            for(int j = 0; i < s1.size() && j < s2.size(); j++){
                if(s1[i] == s2[j])
                    i++;
            }
            return (i == s1.size());
        }
    };


    int main(){
        Solution a;
        vector<string> test = {"applepie", "applejuice", "extraordinary", "oval", "stringy","app","ple","ppl"};
        string target = "apple";
        cout << a.findLongestWord(target, test);
    }