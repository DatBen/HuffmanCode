#include "analyse.h"
#include <stdlib.h>

int* analyse_freq(char* t, int l){
    int* s=(int*) malloc(sizeof(int)*25);
    int a;
    for(int i=0; i<25;i++){
        s[i]=0;
    }
    for(int i=0; i<l;i++){
        a=((int) *(t+i))-97;
        s[a]+=1;
    }
    return s;
}