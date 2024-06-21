#include"string.h"
#include<stdio.h>
#include<stdlib.h>
#include"st.h"

void init_st(st* root){
    *root = NULL;
    return;
}


void zig(st* root, node* key){
    
    node *p = key, *q = key->parent, *temp = NULL;

    temp = p->right;
    p->parent = q->parent;
    if(q->parent){
        if(q->parent->left == q){
            q->parent->left = p;
        }
        else{
            q->parent->right = p;
        }
    }
    q->parent = p;
    p->right = q;
    q->left = temp;
    if(temp){
        temp->parent = q;
    }
    if(p->parent == NULL){
        *root = p;
    }
    return;
}


void zag(st* root, node* key){
    
    node *p = key, *q = key->parent, *temp = NULL;

    temp = p->left;
    p->parent = q->parent;
    if(q->parent){
        if(q->parent->left == q){
            q->parent->left = p;
        }
        else{
            q->parent->right = p;
        }
    }
    q->parent = p;
    p->left = q;
    q->right = temp;
    if(temp){
        temp->parent = q;
    }
    if(p->parent == NULL){
        *root = p;
    }
    return;
}


void zig_zig(st* root, node* key){

    zig(root, key->parent);
    zig(root, key);
	
	return;

}


void zag_zag(st* root, node* key){

    zag(root, key->parent);
    zag(root, key);

	return;

}

void zig_zag(st* root, node* key){

    zig(root, key);
    zag(root, key);
    
	return;

}

void zag_zig(st* root, node* key){
    zag(root, key);

    zig(root, key);
	return;
}


void Splay(st* root, node* key){


	while (key->parent != NULL) {
		if (key->parent->parent != NULL) {
			if (key->parent->left == key) {
				if (key->parent->parent->left == key->parent) {
                    //printf("\nCall to zig_zig function\n");
					zig_zig(root, key);
				} else {
                    //printf("\nCall to zig_zag function\n");
					zig_zag(root, key);
				}
			} else {
				if (key->parent->parent->left == key->parent) {
                    //printf("\nCall to zag_zig function\n");
					zag_zig(root, key);
				} else {
                    //printf("\nCall to zag_zag function\n");
					zag_zag(root, key);
				}
			}
		} 
        else if (key->parent != NULL) {
			if (key->parent->left == key) {
                //printf("\nCall to zig function\n");
				zig(root, key);
			} else {
                //printf("\nCall to zag function\n");
				zag(root, key);
			}
		}
	}
	return;
}

void InsertNode(st* root, char* data, char* ip){

    st nn = (st)malloc(sizeof(node));
    nn->left = NULL;
    nn->right = NULL;
    nn->parent = NULL;
    strcpy(nn->site, data);
    strcpy(nn->ipaddress, ip);

    if(!(*root)){
        *root = nn;
        return;
    }

    node *p = NULL, *q = NULL;
    p = *root;
    while(p){
        q = p;
        if(strcmp(p->site, data) > 0)
            p = p->left;
        else if(strcmp(p->site, data) < 0)
            p = p->right;
        else 
            return;
    }
    
    nn->parent = q;
    if(strcmp(q->site, data) > 0){
        q->left = nn;
    }
    else{
        q->right = nn;
    }
    Splay(root, nn);
    return;
}


void Search(st* root, char* data){
    int count = 1;
    node* p = *root;
    if(!p){
        printf("No Details Found !!!\n");
        return;
    }
    while (p != NULL){
        if(strcmp(p->site, data) == 0){
            printf("URL : %s    ipaddress : %s\n", p->site, p->ipaddress);
            printf("Total number of Comparisions : %d\n", count);
            Splay(root, p);
            return;
        }
        else if(strcmp(p->site, data) > 0 ){
            count++;
            p = p->left;
        }
        else if(strcmp(p->site, data) < 0 ){
            count++;
            p = p->right;
        }
    }
    printf("No Details Found !!!\n");
    return;
}


void Delete(st* root, char* data){
    node* p = *root;
    if(!p){
        printf("No Details Found !!!\n");
        return;
    }

    while (p != NULL){

        if(strcmp(p->site, data) == 0){

            Splay(root, p);

            node *del = NULL;

            if(p->left == NULL){
                del = p;
                p = p->right;
                p->parent = NULL;
            }
            else{
                node *q = p->left;

                while (q->right != NULL){
                    q = q->right;
                }

                Splay(&(p->left), q);

                del = p;
                p = p->left;
                p->parent = NULL;
                p->right = del->right;
                del->right->parent = p;
            }
            *root = p;
            free(del);
            return;
        }
        else if(strcmp(p->site, data) > 0 ){
            p = p->left;
        }
        else if(strcmp(p->site, data) < 0 ){
            p = p->right;
        }
    }

    printf("No Details Found !!!\n");
    return;
}


void preorder(node *key, int *n){
	if(!key)
		return;
    printf("| %-3d |  %-16s     |  %-16s      |\n", (*n)++, key->site, key->ipaddress);
	preorder(key-> left, n);
	preorder(key-> right, n);
	return;
}