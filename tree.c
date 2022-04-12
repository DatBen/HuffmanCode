#include "tree.h"
#include <stdio.h>
#include <stdlib.h>


Node* create_node(int l, int f){
    Node* n=(Node*) malloc(sizeof(Node));
    n->l=l;
    n->f=f;
    n->left=NULL;
    n->right=NULL;
    
    return n;
}

Node* create_node_2(Node* left, Node* right){
    Node* n=(Node*) malloc(sizeof(Node));
    (n)->left=left;
    (n)->right=right;
    (n)->l=-1;
    (n)->f=(left->f)+(right->f);
    return n;
}

Tree* create_tree(Node* n){
    Tree* t=(Tree*) malloc(sizeof(Tree));
    (t)->root=n;
    return t;
}


void print_tree(Tree* t){
    Node* n=t->root;
    printf("[");
    if (n->left!=NULL){
        print_node(n->left);
    }
    printf(",");
     if (n->right!=NULL){
        print_node(n->right);
    }
    printf("]\n");

}

void print_node(Node* n){
    if (n->l>=0){
        printf("%c:%d ",(char)n->l,n->f);
    }    
    printf("[");
    if (n->left!=NULL){
        print_node(n->left);
    }    
    printf(",");
    if (n->right!=NULL){
        print_node(n->right);
    } 
    printf("]");
}

void print_tree_code(Tree* t){
    Node* n=t->root;
    printf("[");
    if (n->left!=NULL){
        print_node_code(n->left);
    }
    printf(",");
     if (n->right!=NULL){
        print_node_code(n->right);
    }
    printf("]\n");

}

void print_node_code(Node* n){
    if (n->l>=0){
        printf("%c=%ld ",(char)n->l,n->code);
    }    
    printf("[");
    if (n->left!=NULL){
        print_node_code(n->left);
    }    
    printf(",");
    if (n->right!=NULL){
        print_node_code(n->right);
    } 
    printf("]");
}

void dec_to_bin(long a){
    int tab[10], i;   
    for(i=0; a > 0; i++)  
    {  
        tab[i] = a%2;  
        a = a/2;  
    }    
    for(i=i-2; i >= 0; i--)  
    {  
        printf("%d",tab[i]);  
    }  
}




