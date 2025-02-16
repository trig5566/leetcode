#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Solution {
    public:
        int kthSmallest(vector<vector<int>>& matrix, int k) {
            int n = matrix.size();
            int left = matrix[0][0];
            int right = matrix[n-1][n-1];
            int mid;
            while(left < right){
                int count = 0;
                mid = left+(right-left)/2;
                for(int i = 0;i < n;i++){
                    count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                }
                if(count < k){
                    left = mid+1;                   
                } else {
                    right = mid;
                }
            }
            return left;
        }
};

int main()
{
    vector<vector<int>> test = {{1,5,9},{10,11,13},{12,13,15}};
    int k = 6;
    Solution a;
    cout<<a.kthSmallest(test, 6);
    return 0 ;
}