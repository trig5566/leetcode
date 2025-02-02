#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> shift_tot;
    int n = 0;
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        n = s.size();
        shift_tot = vector<int>(n+1,0);
        for(int i = 0;i < shifts.size();i++){
            shift_update(shifts[i][0],shifts[i][1],shifts[i][2]);
        }
        shift_final(s);
        return s;
    }

    void shift_update(int start,int end, int dir){
        if(dir){
            shift_tot[start]++;
            shift_tot[end+1]--;
        }else{
            shift_tot[start]--;
            shift_tot[end+1]++;
        }
    }

    void shift_final(string &s){
        int up = 0 ;
        for(int i = 0;i < n;i++){
            up += shift_tot[i];
            shift_tot[i] = up;
        }
        for(int i = 0;i < n;i++){
            int shift = (shift_tot[i]%26+26)%26;
            s[i] = 'a' + (s[i]-'a'+shift)%26;
        }
    }

};

int main()
{
    Solution a;
    //vector<vector<int>>shifts = {{0,1,0},{1,2,1},{0,2,1}};
    //string s = "abc";
    string s = "rdquwrrcezvxbnibmgwokgcbrwyvcdklvkgeeszvtkhasieanagzirekqq";
    vector<vector<int>>shifts = {{14,15,0},{28,32,0},{32,47,0},{46,56,0},{37,52,1},{2,22,1},{52,54,1},{22,51,0},
    {29,33,0},{19,45,1},{36,36,0},{57,57,0},{0,43,1},{36,57,1},{52,53,1},{0,39,0},{37,45,1},{7,52,1},{47,55,0},
    {41,42,1},{24,32,0},{17,23,1},{2,48,1},{27,39,1},{43,55,1},{40,55,1},{44,47,0},{29,36,1},{16,50,1},{50,52,0},
    {21,23,0},{52,56,0},{10,16,1},{8,42,0},{23,41,1},{19,48,1},{18,40,1},{16,41,1},{38,51,1},{25,36,0},{2,9,0},
    {7,31,0},{16,27,0},{42,54,0},{27,50,0},{25,40,0},{11,14,0},{35,49,0},{28,35,1},{26,53,0},{4,55,1},{41,54,0},{6,7,1}
    ,{39,50,0},{53,57,0},{11,37,1},{2,49,0},{14,26,0},{52,52,1},{46,49,1},{13,17,0},{35,43,0},{17,49,1},{46,57,1},
    {20,33,0},{54,55,1},{29,31,0},{27,30,1},{37,47,0},{40,47,1},{3,27,1},{54,56,1},{52,56,0},{36,36,1},{54,54,0},
    {6,11,0},{28,30,1},{24,27,0},{22,53,1},{45,48,1},{11,39,0},{6,46,0},{53,57,0},{2,9,0},{55,57,1},{39,43,1},{42,46,0},
    {2,48,1},{7,20,1},{27,54,1},{54,55,1},{31,53,1},{54,54,1},{5,9,0},{33,48,0},{14,17,1},{46,50,1},{2,6,1},{54,55,1},{34,43,1}};
    cout<<"Answer: "<<a.shiftingLetters(s,shifts);
}