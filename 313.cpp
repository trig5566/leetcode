#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
//#include <math>


using namespace std;


class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> su = vector<int>(n,INT_MAX);//superugly number
        int index_n = primes.size();
        vector<int> indx = vector<int>(index_n,0);
        su[0] = 1;
        for(int i = 1; i < n;i++){
            long mini = INT_MAX;
            for(int j = 0; j < index_n; j++){
                mini = min(mini,(long)su[indx[j]]*primes[j]);
            }
            su[i] = (int)mini;
            for(int j = 0; j < index_n; j++){
                if(mini == (long)su[indx[j]]*primes[j])
                    indx[j]++;
            }
        }
        return su[n-1];
    }
};


int main()
{
    int n = 5911;
    vector<int> prime = {2,7,13,19};
    Solution a;
    cout << a.nthSuperUglyNumber(n,prime);
}