#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int maxProfit(int* prices, int pricesSize) {
    int bef = 0;
    int profit = 0;
    if(pricesSize <= 1)
        return 0;
    bef = prices[0];

    for(int i = 1;i < pricesSize;i++){
        if(bef < prices[i]){
            profit += (prices[i]-bef);
        }
        bef = prices[i];
    }

    return profit;
}

void vApplicationGetTimerTaskMemory( int **ppxTimerTaskTCBBuffer, 
 int **ppxTimerTaskStackBuffer,
 uint32_t *pulTimerTaskStackSize )
{ 
 /* If the buffers to be provided to the Idle task are declared inside this
 function then they must be declared static - otherwise they will be allocated on
 the stack and hence would not exists after this function exits. */
 static int xTimerTaskTCB; 
 static int uxTimerTaskStack[ 5 ]; 
 /* Pass out a pointer to the StaticTask_t structure in which the Idle task's
 state will be stored. */
 *ppxTimerTaskTCBBuffer = &xTimerTaskTCB; 
 /* Pass out the array that will be used as the Idle task's stack. */
 *ppxTimerTaskStackBuffer = uxTimerTaskStack; 
 /* Pass out the stack size of the array pointed to by *ppxIdleTaskStackBuffer.
 Note the stack size is a count of StackType_t */
 *pulTimerTaskStackSize = sizeof(uxTimerTaskStack) / sizeof(*uxTimerTaskStack); 
} 

int main(){
    int *tcb[4];
    int *stack[4];
    uint32_t size = 0;
    uint8_t test[8] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    for(int i = 0;i < 4;i++){
        vApplicationGetTimerTaskMemory(&tcb[i],&stack[i],&size);
        printf("size:%d p:%p\r\n",size,stack);
    }
    printf("%lld\r\n",*((int64_t*)test));
    return 0;
}