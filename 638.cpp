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
    unordered_map<string, int> dp;
    vector<int> my_price;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
/*        for(int i = 0; i < price.size();i++){
            vector<int> tmp(needs.size()+1,0);
            tmp[i] = 1;
            tmp[needs.size()] = price[i];
            special.push_back(tmp);
        }*/
        my_price = price;
        string rest = "";
        for(int i = 0; i < needs.size();i++){
            rest += needs[i];
        }

        return shopping(rest, special);
    }

    int shopping(string rest,vector<vector<int>>& special){
        if(dp[rest] != 0)
            return dp[rest];
        int val = 0;

        for(int k = 0;k < rest.size();k++)
            val += my_price[k]*rest[k];
        
        for(int i = 0; i < special.size();i++){
            int j = 0;
            for(j = 0; j < rest.size();j++){
                if(rest[j] - special[i][j] < 0)
                    break;                
            }

            //val = min(val, shopping(rest, i+1, special)); 

            if(j == rest.size()){
                string new_rest = rest;
            
                for(int k = 0; k < new_rest.size();k++)
                    new_rest[k] -= special[i][k];
                val = min(val, shopping(new_rest, special) + special[i][special[i].size()-1]); 
                          
            } 
            
        }
        
        dp[rest] = val;
/*        cout<<"[";
        for(int i = 0; i < rest.size(); i++)
            cout<<(int)rest[i]<<" ";
        cout<<"] dp:"<<dp[rest]<<endl;*/
        return dp[rest];
    }
};

int main()
{
    Solution a;
    vector<int> price = {2,3,4};
    //vector<int> price = {2,2};
    //vector<int> price = {0,0,0};
    vector<vector<int>> special = {{1,1,0,4},{2,2,1,9},{0,1,1,6},{0,2,0,4},{1,1,1,7}};
    //vector<vector<int>> special = {{1,1,1},{1,1,2},{1,1,3}};
    vector<int> needs = {10,10,10};
    //vector<int> needs = {10,10};
    cout<<a.shoppingOffers(price, special, needs);
    return 0;
}