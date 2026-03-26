#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    class Mynode{
        public:
        string addr;
        vector<Mynode *> neigh;
        Mynode(string _addr){addr = _addr;}
    };
    unordered_map<string, Mynode *>node_map;
    unordered_map<string, int> map_index;


    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                map_index[accounts[i][j]] = i;
                if(node_map[accounts[i][j]] == nullptr)
                    node_map[accounts[i][j]] = new Mynode(accounts[i][j]);                 

                if(j != 1){
                    node_map[accounts[i][j]]->neigh.push_back(node_map[accounts[i][1]]);
                    node_map[accounts[i][1]]->neigh.push_back(node_map[accounts[i][j]]);
                }
            }
        }
        unordered_map<Mynode *, int> used;
        vector<vector<string>> result;
        //int i = 0;
        for(int i = 0; i < accounts.size(); i++)
            for(int j = 1; j < accounts[i].size(); j++){
            //cout<<i<<":"<<it->first<<endl;
            if(used[node_map[accounts[i][j]]] == 1)
                continue;

            vector<Mynode *> bfs_stack;
            set<string> set_result;
            
            bfs_stack.push_back(node_map[accounts[i][j]]);
            while(!bfs_stack.empty()){
                Mynode *tmp = bfs_stack[bfs_stack.size() - 1];
                bfs_stack.pop_back();
                if(used[tmp] == 1)
                    continue;
                used[tmp] = 1;
                set_result.insert(tmp->addr);
                
                for(auto node: tmp->neigh)
                     bfs_stack.push_back(node);               
            }
            vector<string> vet_result;
            vet_result.push_back(accounts[i][0]);
            for(auto &s: set_result)
                vet_result.push_back(s);
            result.push_back(vet_result);
        }
        return result;
    }
};


int main()
{
    //vector<vector<string>> test = {{"Ryan", "A@gmail.com", "B@hotmail.com", "C@yahoo.com"}, {"Ryan","D@hotmail.com","E@yahoo.com"}, {"Ryan", "B@hotmail.com", "D@hotmail.com", "F@apple.com"}, {"Lily", "G@gmail.com","F@gmail.com"}};
    vector<vector<string>> test = {{"Ethan","Ethan1@m.co","Ethan2@m.co","Ethan0@m.co"},{"David","David1@m.co","David2@m.co","David0@m.co"},{"Lily","Lily0@m.co","Lily0@m.co","Lily4@m.co"},{"Gabe","Gabe1@m.co","Gabe4@m.co","Gabe0@m.co"},{"Ethan","Ethan2@m.co","Ethan1@m.co","Ethan0@m.co"}};
    //vector<vector<string>> test = {{"David","David0@m.co","David1@m.co"},{"David","David3@m.co","David4@m.co"},{"David","David4@m.co","David5@m.co"},{"David","David2@m.co","David3@m.co"},{"David","David1@m.co","David2@m.co"}};
    Solution a;
    vector<vector<string>> result = a.accountsMerge(test);
    for(auto i: result){
        for(auto j: i){
            cout<<j<<", ";
        }
        cout<<endl;
    }
    return 0;
}