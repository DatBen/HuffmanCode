#ifndef TREE
#define TREE


typedef struct node 
{
    int l;
    int f;
    long code;
    struct node* left;
    struct node* right;
}Node;



typedef struct tree 
{
    Node* root;
}Tree;


Node* create_node(int l, int f);
Tree* create_tree(Node* n);
Node* create_node_2(Node* left, Node* right);
void print_tree(Tree* t);
void print_node(Node* n);
void print_tree_code(Tree *t);
void print_node_code(Node*n);
void dec_to_bin(long a);


#endif