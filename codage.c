#include "codage.h"
#include "tree.h"
#include "analyse.h"
#include <stdlib.h>
#include <stdio.h>


void sort_int(int *t, int l){
    int i,j,c,b;
    for(i=0;i<l-1;i++){
        for(j=i+1;j<l;j++){
            if ( *(t+2*i) > *(t+2*j)  ) {
                c = *(t+2*i);
                b= *(t+2*i+1);
                *(t+2*i) = *(t+2*j);
                *(t+2*i+1) = *(t+2*j+1);
                *(t+2*j) = c;
                *(t+2*j+1) = b;
            }
        }
    }
}

void sort_node(Node **n,int l,int k){
    Node* c;
    int i,j;
    for(i=k;i<l-1;i++){
        for(j=i+1;j<l;j++){
            if ( (*(n+i))->f > (*(n+j))->f) {
                c = *(n+i);                
                *(n+i) = *(n+j);                
                *(n+j) = c;
                
            }
        }
    }
}

Tree* create_table(char* t, int l){
    
    int*a=analyse_freq(t,l);
    int*u=(int*) malloc(sizeof(int)*2*26);
    for(int i=0;i<26;i++){
        *(u+2*i)=*(a+i);
        *(u+2*i+1)=i+97;
    }
    sort_int(u,26);
    Node**n=(Node**)malloc(sizeof(Node*)*26);
    for(int i=0;i<26;i++){
        *(n+i)=create_node(*(u+2*i+1),*(u+2*i));
    }
    int k=0;
    Node*f;
 
    while (k<25){
        f=create_node_2(*(n+k),*(n+k+1));
        k=k+1;
        *(n+k)=f;
        sort_node(n,26,k);
    }
    Tree*h=create_tree(*(n+25));
    return(h);

}


int* init_code(Tree* t){
    Node**l=(Node**)malloc(sizeof(Node*)*128*2);
    int* d=malloc(sizeof(long)*26);
    *(l)=t->root->left;
    *(l+1)=t->root->right;
    (*(l))->code=2;
    (*(l+1))->code=3;
    *(d+((*(l))->l)-97)=(*(l))->code;
    *(d+((*(l+1))->l)-97)=(*(l+1))->code;
    int deb=0;
    int fin=2;
    while(*(l+deb)!=NULL){
        if ((*(l+deb))->left!=NULL){
            *(l+fin)=(*(l+deb))->left;
            (*(l+fin))->code=(*(l+deb))->code*2;
            *(d+((*(l+fin))->l)-97)=(*(l+fin))->code;
            fin+=1;
        }
        if ((*(l+deb))->right!=NULL){
            *(l+fin)=(*(l+deb))->right;
            (*(l+fin))->code=((*(l+deb))->code*2)+1;
            *(d+((*(l+fin))->l)-97)=(*(l+fin))->code;          
            fin+=1;
        }    
       
        deb=deb+1;
       
    }
    return(d);
}


void print_code(int* d,char c){
    dec_to_bin(*(d+c-97));
}

void print_codage(char*s,int l){
    Tree* p=create_table(s,l);
    int* d=init_code(p);
    printf("Le codage de Huffman de ");
    for(int i=0;i<l;i++){
        printf("%c",*(s+i));
    }
    printf(" est : \n");
    for(int i=0;i<l;i++){
        print_code(d,*(s+i));
        printf(" ");
    }
    printf("\n");
}



