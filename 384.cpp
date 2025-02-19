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

using namespace std;

class Solution {
    public:
        vector<int> sh;
        int n;
        Solution(vector<int>& nums) {
            n = nums.size();
            sh = vector<int>(n,0);
            srand (time (NULL));
            for(int i = 0; i < n; i++){
                sh[i] = nums[i];
            }
        }
        
        vector<int> reset() {
            return sh;
        }
        
        vector<int> shuffle() {
            vector<int> index = rand_0_to_n(n);
            vector<int> result(n,0);
            for(int i = 0;i < n;i++){
                result[i] = sh[index[i]];
            }
            return result;
        }

        vector<int> rand_0_to_n(int n_) {
            vector<int> myrand(n_,0);
            
            for(int i = 0; i < n_;i++)
                myrand[i] = i;

            for(int i = n_; i > 0;i--){
                int x = rand()%i;
                swap(myrand[i-1],myrand[x]);  
            }               

            return myrand;
        }
    };
    
    /**
     * Your Solution object will be instantiated and called as such:
     * Solution* obj = new Solution(nums);
     * vector<int> param_1 = obj->reset();
     * vector<int> param_2 = obj->shuffle();
     */

int main()
{
    vector<int> test = {0,1,2};
    Solution* obj = new Solution(test);
    for(int j= 0; j < 10;j++){
        vector<int> result = obj->shuffle();
        for(int i : result){
            cout<<i<<",";
        }
        cout<<endl;
        result = obj->reset();
        for(int i : result){
            cout<<i<<",";
        }
        cout<<endl;
    }
    return 0;
}