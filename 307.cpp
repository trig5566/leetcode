#include <iostream>
#include <vector>
#include <set>

using namespace std;

class NumArray {
public:
    vector<int> segs;
    int n = 0;
    NumArray(vector<int>& nums) {
        if(nums.size())
            n = nums.size();
        segs = vector<int>(4*n,0);
        build_tree(nums,0,0,n-1);
    }
    
    void build_tree(vector<int>& nums, int pos, int low, int high){
        if(low == high){
            segs[pos] = nums[low];
            cout<<"segs["<<pos<<"]:"<<segs[pos]<<endl;
        } else {
            int mid = (low+high)/2;
            build_tree(nums,2*pos+1,low,mid);
            build_tree(nums,2*pos+2,mid+1,high);
            segs[pos] = segs[2*pos+1] + segs[2*pos+2];
            cout<<"segs["<<pos<<"]:"<<segs[pos]<<endl;
        }

    }

    void update_util(int pos,int index, int low, int high,int value){
        if(index < low || index > high)
            return;
        if(low == high){
            if(low == index)
                segs[pos] = value;
            return;
        }
        int mid = (low+high)/2;
        update_util(2*pos+1,index,low,mid,value);
        update_util(2*pos+2,index,mid+1,high,value);
        segs[pos] = segs[2*pos+1]+segs[2*pos+2];
        cout<<"segs["<<pos<<"]:"<<segs[pos]<<endl;
    }

    int sum_util(int pos,int t_low,int t_high,int low,int high){
        if(t_low <= low && high <= t_high){
            return segs[pos];
        }else if(t_low > high || t_high < low){
            return 0;
        }
        int mid = low + (high-low)/2;
        return sum_util(2*pos+1,t_low,t_high,low,mid)+sum_util(2*pos+2,t_low,t_high,mid+1,high);
    }

    void update(int index, int val) {
        update_util(0,index,0,n-1,val);
    }
    
    int sumRange(int left, int right) {
        return sum_util(0,left,right,0,n-1);
    }
};

int main(){
    vector<int> test = {9,-8};
    NumArray a(test);
    //a.update(0,3);
    cout<<a.sumRange(1,1)<<endl;
    cout<<a.sumRange(0,1)<<endl;
    cout<<a.sumRange(0,0)<<endl;
}