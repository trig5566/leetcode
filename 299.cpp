#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int secret_count[10] = {0};
        int guess_count[10] = {0};
        int a_count = 0;
        int b_count = 0;
        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i])
                a_count++;
            else {
                secret_count[secret[i]-'0']++;
                guess_count[guess[i]-'0']++;
            }
        }
        for(int i = 0; i < 10; i++){
            b_count += min(secret_count[i], guess_count[i]);
        }
        return to_string(a_count) + "A" + to_string(b_count) + "B";
    }
};

int main()
{
    Solution a;
    cout << a.getHint("12341234","24131234");
}