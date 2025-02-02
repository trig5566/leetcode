#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

bool isIsomorphic(char* s, char* t) {
    uint8_t s_table[256] = {0};
    uint8_t t_table[256] = {0};
        if(s == NULL)
        return true;
    for(int i = 0;s[i] != '\0' ;i++){
        uint8_t ind_s= s[i];
        uint8_t ind_t= t[i];
        if(s_table[ind_s] == 0 && t_table[ind_t] == 0){
            s_table[ind_s] = t[i];
            t_table[ind_t] = s[i];
        }else if(s_table[ind_s] != t[i] || t_table[ind_t] != s[i]){
            return false;
        }
    }
    return true;
}

int main(){
    char s[2] = {0};
    s = NULL;
    s[1] = NULL;
    char t[2];
    t[1] = NULL;
    t[2] = 'c';
    printf("%d",isIsomorphic(s,t));
    return 0;
}