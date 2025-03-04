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

class Solution {
    vector<vector<int>> graph;
    int n;
    public:
        int minMutation(string startGene, string endGene, vector<string>& bank) {
            n = bank.size();
            int target = 0;

            vector<string> replica = vector<string>(n+1);
            replica[0] = startGene;
            for(int i = 1; i < n+1; i++){
                replica[i] = bank[i-1];
            }
            n = n+1;
            int z = 0;
            for(z = 0;z < n;z++){
                if(endGene.compare(replica[z]) == 0){
                    target = z;
                    break;
                }
            }
            if(z == n)
                return -1;

            for(int i = 0;i < n; i++){
                vector<int> tmp;
                for(int j = 0;j < n;j++){
                    if(i != j && get_path(replica[i],replica[j]) == 1)
                        tmp.push_back(j);
                }
                graph.push_back(tmp);
            }

/*           for(int i = 0; i < graph.size();i++){
                cout<<"["<<i<<"]:";
                for(int j = 0;j < graph[i].size();j++){
                    cout<<graph[i][j]<<",";
                }
                cout<<endl;
            }*/
            int result = dijkstas(0,target);
            return result >= 256?-1:result;

        }

        int dijkstas(int start,int end)
        {
            vector<bool> used = vector<bool>(n,0);
            vector<int> shortest = vector<int>(n,256);
            queue<int> qu;
            qu.push(start);     
            shortest[start] = 0;      
            while(!qu.empty()){
                int it = qu.front();
                qu.pop();
                used[it] = 1;
                for(int i = 0;i < graph[it].size();i++){
                    if(!used[graph[it][i]]){
                        shortest[graph[it][i]] = min(shortest[graph[it][i]],shortest[it]+1);
                        qu.push(graph[it][i]);
                    }
                }
            }
            //for(int i = 0;i < n;i++)
                //cout<<"sh["<<i<<"]:"<<shortest[i]<<endl;
            
            return shortest[end];
        }

        int get_path(string a,string b){
            int dif = 0;
            for(int i = 0;i < 8;i++){
                if(a[i] != b[i])
                    dif++;
                if(dif > 1)
                    break;
            }
            return dif >= 2?0:1;
        }
    };


    int main()
    {
        Solution a;
        vector<string> test = {"AACCGGTA","AACCGCTA","AAACGGTA","AACCTGTA","AAACTGTA","AAACAGTA","AAACAGTT"};
        cout<<a.minMutation("AACCGGTT","AAACAGTT",test);
        return 0;
    }