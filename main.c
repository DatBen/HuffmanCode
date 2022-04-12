#include "codage.h"
#include <stdio.h>
#include <stdlib.h>
#include "analyse.h"
#include "tree.h"


void main(void){ 
    printf("entrez la taille du texte à coder : ");
    int num;
    scanf("%d",&num);
    printf("entrez le texte à coder : ");
    char* s=malloc(sizeof(char)*(num+1));
    for(int i=0;i<num+1;i++){
        scanf("%c",s+i);
    }
    print_codage(s,num+1);  
}