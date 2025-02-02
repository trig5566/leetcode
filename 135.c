#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int candy(int* ratings, int ratingsSize) {
    int total = 0;
    int i = 1;
    if(ratingsSize > 1 && ratings[0] > ratings[1])
        total += 2;
    else 
        total += 1;
    for(;i < ratingsSize-1;i++){
        if(ratings[i] < ratings[i-1] || ratings[i] < ratings[i+1]){
            total += 1;
        }else if(ratings[i] > ratings[i-1] || ratings[i] > ratings[i+1])
            total += 2;
    }
    if(ratings[i] > ratings[i-1])
        total += 2;
    else 
        total += 1;
    return total;
}

int main(){
    int test[] = {1,0,2};
    printf("%d\r\n",candy(test,3));
    return 0;
}