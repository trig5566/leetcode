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

using namespace std;

class Solution {
    public:
        vector<vector<pair<int,double>>>  weight_map;
        unordered_map<string,int>   index;
        int n;
        vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
            vector<double> result;
            n = 2*equations.size()+1;
            index = unordered_map<string,int>(n);
            weight_map = vector<vector<pair<int,double>>>(n);
            int extra_index = 1;
            for(int i = 0; i < equations.size();i++){
                vector<string> tmp = equations[i];
                if(index[tmp[0]] == 0){
                    index[tmp[0]] = extra_index;
                    extra_index++;
                }
                if(index[tmp[1]] == 0){
                    index[tmp[1]] = extra_index;
                    extra_index++;
                }
                pair<int,double> node(index[tmp[1]],values[i]);
                weight_map[index[tmp[0]]].push_back(node);
                node = {index[tmp[0]],1/values[i]};
                weight_map[index[tmp[1]]].push_back(node);
            }

            for(int i = 0; i < queries.size(); i++){
                if(index[queries[i][0]] == 0 || index[queries[i][1]] == 0)
                    result.push_back(-1);//cout<<-1<<",";
                else
                    result.push_back(find_cal(index[queries[i][0]],index[queries[i][1]]));
            }
            //for(auto it = index.begin();it != index.end() ;it++)
                //cout<<"["<<it->first<<","<<it->second<<"]"<<endl;
            /*for(int i = 0; i < n; i++){
                for(int j = 0; j < weight_map[i].size(); j++){
                    pair<int,double> node = weight_map[i][j];
                    cout<<"["<<node.first<<","<<node.second<<"] ";
                }
                cout<<endl;
            }*/
            return result;
        }

        double find_cal(int a,int b)
        {
            if(a == b)
                return 1;
            queue<pair<int,double>>  waited;
            vector<int> used(n,0);
            used[a] = 1;
            for(int i = 0; i < weight_map[a].size();i++){
                waited.push(weight_map[a][i]);
            }
            while(!waited.empty()){
                pair<int,double> node = waited.front();
                waited.pop();
                if(node.first == b)
                    return node.second;
                used[node.first] = 1;
                for(int i = 0; i < weight_map[node.first].size();i++){
                    pair<int,double> next_node = weight_map[node.first][i];
                    if(used[next_node.first] == 0){
                        next_node.second = next_node.second*node.second;
                        waited.push(next_node);
                    }
                }
            }
            return -1;
        }

    };

int main()
{
    Solution a;
    vector<vector<string>> equations = {{"a","b"},{"b","c"},{"bc","cd"}};
    vector<double> values = {1.5,2.5,5.0};
    vector<vector<string>> queries = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
    vector<double> result = a.calcEquation(equations, values, queries);
    for(auto i: result)
        cout<<i<<",";
    return 0;
}