#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
#define arr(i) nums[(2*i+1)%(n|1)]
   void wiggleSort(vector<int>& nums) {
    
    int n = nums.size();
    if(n <= 1)
        return;
    int k__ = n/2;
    findKthLargest(nums,k__+1);
    int mid = *(nums.begin() + n/2); 
    int i=0; 
    int j=0;
    int k=n-1;
   // cout<<"mid:"<<mid<<endl;
    while(j <= k){
        if(arr(j) > mid){
            swap(arr(j++),arr(i++));
        }else if(arr(j) < mid){
            swap(arr(j),arr(k--));
        }else
            j++;
        //print_k(nums);
    }
    
}
    void print_k(vector<int>& nums){
        int n = nums.size();
        for(int i = 0;i < n;i++){
            cout<<arr(i)<<" ";
        }
        cout<<endl;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        bin_sort(nums,0,n-1,k-1);
        return nums[k-1];
    }
    void bin_sort(vector<int>& nums,int l,int r,int k){
        int l_begin = 0;
        int r_begin = 0;
        int mid_index = 0;
        while(1){
            l_begin = l;
            r_begin = r;
            mid_index = r;
            r = r-1;
            while(l <= r){
                if(nums[l] > nums[mid_index] && nums[r] < nums[mid_index])
                    swap(nums[l],nums[r]);
                if(nums[l] <= nums[mid_index])
                    l++;
                if(nums[r] >= nums[mid_index])
                    r--;
            }   
            swap(nums[l],nums[mid_index]);
        
            if(l == k)
                break;
            else if(k < l){
                r = l-1;
                l = l_begin;
            } else {
                l = l+1;
                r = r_begin;
            }
        }
    }
};

int main(){
    vector<int> test = {3,3,3,2,2,2,3,2,1,1,2,1,2,3,3,3,1,2};
    Solution a;
    a.wiggleSort(test);
    for(int i = 0; i < test.size();i++){
        cout<<test[i]<<" ";
    }
}