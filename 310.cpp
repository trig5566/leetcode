#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>


using namespace std;

class Solution {
public:
    map<int,set<int>> graph;
    queue<int> q_one;
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        graph = map<int,set<int>>(n,0);
        for(vector<int> edge:edges){
            graph[edge[0]].insert (edge[1]);
            graph[edge[1]].insert (edge[0]);
        }
        int g_size = graph.size();
        for(int i = 0; i < g_size;i++){
            if(graph[i].size() == 1){
                auto it = graph[i].begin();
                q_one.push(*it);
                graph[i].erase(*it);
                graph.erase(i);
            }
        }
        int q_size = q_one.size();
        while(!q_one.empty()){
            int q_erase = q_one.front(); 
            q_one.pop();
            for(int j = 0;j < graph.size();j++){
                graph[j].erase(q_erase);
                q_one.front(); 
            }

        }

    }
};


int main()
{

    map<int,list<int>> graph = {{0,{1}},{1,{2}}};

    int g_size = graph.size();
    for(int i = 0; i < g_size;i++){
        if(graph[i].size() == 1){
            graph[i].pop_back();
            graph.erase(i);
        }
    }
    cout<<graph.size()<<endl;
    cout<<graph[1].size()<<endl;
    return 0;
}