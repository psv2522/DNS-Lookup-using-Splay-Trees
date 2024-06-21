typedef struct node{
    char site[20], ipaddress[20];
    struct node *left, *right, *parent;
}node;

typedef node* st;

void init_st(st *root);//Init fxn

void InsertNode(st* root, char* data, char* mean);//Simple insert+Splay

void Search(st* root, char* data);//Simple search+Splay

void Delete(st* root, char* data);//Simple delete

//Rotations
void zig(st* root, node* key);//Right rotation

void zag(st* root, node* key);//Left rotation

void zig_zig(st* root, node* key);

void zag_zag(st* root, node* key);

void zig_zag(st* root, node* key);

void zag_zig(st* root, node* key);

void Splay(st* root, node* key);//Decide rotations

void preorder(st key, int *n);//Preorder traversal