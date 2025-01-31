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
                if(nums[l] < nums[mid_index] && nums[r] > nums[mid_index]){ 
                    swap(nums[l],nums[r]);
            }
                if(nums[l] >= nums[mid_index])
                    l++;
                if(nums[r] <= nums[mid_index])
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

int main()
{
    vector<int> test = {3,2,3,1,2,4,5,5,6};
    int target = 4;
    Solution a;
    cout<<a.findKthLargest(test,target)<<endl;
    for(int i = 0; i < test.size();i++){
        cout<<test[i]<<" ";
    }
}