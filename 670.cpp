#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digi;
        int index = 0;
        int result = 0;
        while(num > 0){
            int tmp = num % 10;
            digi.push_back(tmp);
            num = num/10;
        }
        int max_pos = find_max_pos(digi, digi.size() - 1);
        for(int i = digi.size() - 1; i >= 0; i--){          
            if(i == max_pos) {
                max_pos = find_max_pos(digi, i - 1);
            } else if(digi[i] < digi[max_pos]) {
                int tmp = digi[max_pos];
                digi[max_pos] = digi[i];
                digi[i] = tmp;
                break;               
            }
        }
        for(int i = digi.size() - 1; i >= 0; i--){
            //cout<<"d["<<i<<"]:"<<digi[i]<<",result:"<<result<<endl;
            result *= 10;
            result +=  digi[i];            
        }
        return result;
    }

    int find_max_pos(vector<int> digi, int end){
        int max_pos = 0;
        int max = 0;
        int i = 0;
        for(; i <= end;i++){
            if(digi[i] > max){
                max = digi[i];
                max_pos = i;
            }
        }
        //cout<<"find max pos:"<<max_pos<<","<<digi[max_pos]<<endl;
        return max_pos;
    }
};

int main()
{
    Solution a;
    int test = 999732;
    cout<<a.maximumSwap(test);
    return 0;
}