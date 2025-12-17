#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> result;
        int start = 1;
        result.push_back(start);
        int count = k;
        int new_start = start + count + 1;
        for(int i = 1; i < n; i++){
            if(start + count <= n){
                if(count != 0){
                    result.push_back(start + count);
                    start = start + count;
                    count = count > 0 ?-(count-1):-(count+1);                   
                } else {
                    if(new_start <= n){
                        start = new_start;
                        result.push_back(start);
                        count = k;
                        new_start = start + count + 1;
                    } else 
                        return result;
                }
            } else {
                count = n - start;
                i--;
            }
        }
        return result;
    }
};


int main()
{
    Solution a;
    vector<int> result = a.constructArray(2, 1);
    for(int i: result)
        cout<<i<<" "<<endl;
    return 0;
}