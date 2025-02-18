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

using namespace std;

class Solution {
    public:
        
        vector<int> lexicalOrder(int n) {
            stack<int> st;
            vector<int> result;
            for(int i = min(n,9); i >= 1;i--)
                st.push(i);

            while(!st.empty()){
                int tmp = st.top();
                st.pop();
                result.push_back(tmp);
                if(tmp*10 <= n){
                    for(int i = min(tmp*10+9,n);i >= tmp*10;i--)
                        st.push(i);
                }
            }

            return result;
        }
};

int main()
{
    Solution a;
    vector<int> result = a.lexicalOrder(110);
    for(int i:result)
        cout<<i<<",";
    return 0;
}