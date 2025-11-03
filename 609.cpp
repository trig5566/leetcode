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

class file_cata {
public:
    string path;
    string name;
    file_cata(string path_t, string name_t){
        path = path_t;
        name = name_t;
    }
};

class Solution {
public:
    vector<string> split_delim(string str, char delim){
        vector<string> tokens;
        istringstream iss(str);
        string token;
        while(getline(iss, token, delim)){
            tokens.push_back(token);
        }
        return tokens;
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> result;
        unordered_map<string, vector<file_cata>> dup_dict;
        unordered_map<string, int> dup_list;
        for(string one_dir: paths){ 
            vector<string> tmp = split_delim(one_dir, ' ');
            for(int i = 1; i < tmp.size();i++){
                if(tmp[i].find("(") != string::npos && tmp[i].find(")") != string::npos){
                    string index = tmp[i].substr(tmp[i].find("(")+1, tmp[i].find(")") - tmp[i].find("(")-1);
                    file_cata tmp_file(tmp[0], tmp[i].substr(0, tmp[i].find("(")));
                    if(!dup_dict[index].empty())
                        dup_list[index] = 1;
                    dup_dict[index].push_back(tmp_file);
                    cout<<"index:"<<index<<" add path:"<<tmp_file.path<<" name:"<<tmp_file.name<<endl;
                }
            }
        }
        int j = 0;
        for(auto &it : dup_list){
            vector<string> tmp;
            for(file_cata res_str:dup_dict[it.first]){
                tmp.push_back(res_str.path+"/"+res_str.name);
            }
            result.push_back(tmp);
        }
        return result;
    }
};

int main()
{
    Solution a;
    vector<string> test = {"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"};
    vector<vector<string>> result = a.findDuplicate(test);
    for(vector<string> i: result){
        cout<<"{";
        for(string j:i){
            cout<<j<<",";
        }
        cout<<"}";
    }
    return 0;
}