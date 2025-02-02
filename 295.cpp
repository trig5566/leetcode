#include <iostream>
#include <vector>
#include <set>

using namespace std;

class MedianFinder {
public:
    multiset<int> S;
    multiset<int>::iterator mid;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(S.size() == 0){
            S.insert(num);
            mid = S.begin();
        } else {
            S.insert(num);
            if((S.size() % 2 == 1)){
                if((*mid > num))
                    mid--;
            } else if(S.size() % 2 == 0) {
                if((*mid <= num))
                    mid++;
            }
        }
    }
    
    double findMedian() {
        if(S.size() % 2 == 0) {
            // If the size is even, return the average of the two middle elements
            auto midP = mid; 
            midP--;  // Move to the second middle element
            return (double)(*mid + *midP) / 2;
        } 
        else {
            // If the size is odd, return the middle element
            return *mid;
        }       
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */