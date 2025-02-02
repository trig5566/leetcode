#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>

using namespace std;



class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<unsigned int> bitrecord = vector<unsigned int>(n,0);
        for(int i = 0; i< n;i++){
            for(int j = 0; j < words[i].size();j++){
                bitrecord[i] |= (1<<(words[i][j]-'a'));
            }
        }
        int max = 0;
        for(int i = 0;i < n;i++){
            for(int j = i+1;j < n;j++){
                if(!(bitrecord[i] & bitrecord[j])){
                    if(max < words[i].size()*words[j].size())
                        max = words[i].size()*words[j].size();
                }
            }
        }
        return max;
    }
};


int main(){

}