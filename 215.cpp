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
        int mid = (l+r)/2;
        int l_begin = l;
        int r_begin = r;
        int mid_index = 0;
        if((nums[l] >= nums[mid] && nums[l] <= nums[r])||(nums[l] >= nums[r] && nums[l] <= nums[mid]))
            swap(nums[l],nums[r]);
        else if((nums[mid] >= nums[r] && nums[mid] <= nums[l])||(nums[mid] >= nums[l] && nums[mid] <= nums[l]))
            swap(nums[mid],nums[r]);
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
            return;
        else if(k < l)
            bin_sort(nums,l_begin,l-1,k);
        else
            bin_sort(nums,l+1,r_begin,k);
    }
};