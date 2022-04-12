#include <stdio.h>
#include <stdlib.h>
#include "analyse.h"
#include "tree.h"
#include "codage.h"



void main(void){
    printf("entrez la taille du texte : ");
    int num;
    scanf("%d",&num);
    char* s=malloc(sizeof(char)*(num+1));
    for(int i=0;i<num+1;i++){
        scanf("%c",s+i);
    }
    print_codage(s,num+1);  
   

    
    
}