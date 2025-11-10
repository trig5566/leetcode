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
    vector<string> split(string str, char delim){
        vector<string> result;
        stringstream ss(str);
        string token;
        while(getline(ss, token, delim)){
            result.push_back(token);
        }
        return result;
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n, 0);
        stack<int> mytask;
        vector<string> tmp = split(logs[0], ':');
        mytask.push(stoi(tmp[0]));
        int time = stoi(tmp[2]);
        bool pre_start = tmp[1] == "start"?true:false;
        int cur_id =  mytask.top();
        for(int i = 1; i < logs.size(); i++){
            
            tmp = split(logs[i], ':');           
            if(tmp[1] == "start"){
                int tmp_time = stoi(tmp[2]);
                if(!mytask.empty())
                    cur_id =  mytask.top();
                if(!pre_start)
                    result[cur_id]--;
                result[cur_id] += (tmp_time - time);
                //cout<<"s "<<cur_id<<":"<<result[cur_id]<<endl;
                time = tmp_time;
                mytask.push(stoi(tmp[0]));
                pre_start = true;
                
            }else if(tmp[1] == "end"){
                int tmp_time = stoi(tmp[2]);
                cur_id =  mytask.top();
                if(pre_start)
                    result[cur_id]++;
                result[cur_id] += (tmp_time - time);
                //cout<<"e "<<cur_id<<":"<<result[cur_id]<<endl;
                time = tmp_time;
                mytask.pop();
                pre_start = false;
                //
            }
        }
        return result;
    }
};

int main()
{
    Solution a;
    int n = 8;
    vector<string> test = {"0:start:0","1:start:5","2:start:6","3:start:9","4:start:11","5:start:12","6:start:14","7:start:15","1:start:24","1:end:29","7:end:34","6:end:37","5:end:39","4:end:40","3:end:45","0:start:49","0:end:54","5:start:55","5:end:59","4:start:63","4:end:66","2:start:69","2:end:70","2:start:74","6:start:78","0:start:79","0:end:80","6:end:85","1:start:89","1:end:93","2:end:96","2:end:100","1:end:102","2:start:105","2:end:109","0:end:114"};
   // vector<string> test = {"0:start:0","0:end:0","1:start:1","1:end:1","2:start:2","2:end:2","2:start:3","2:end:3"};
    vector<int> result = a.exclusiveTime(n, test);
    for(int i = 0; i < n;i++){
        cout<<i<<":"<<result[i]<<endl;
    }
    return 0;
}