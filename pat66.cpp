//
//  main.cpp
//  pat66
//
//  Created by Sr on 2017/4/8.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#define height(T) ((T==NULL)?0:T->height)

using namespace std;
typedef struct node *tree;

struct node{
    int element;
    tree left;
    tree right;
    int height;
};

tree r_rotate(tree T){
    tree tmp=T->left;
    T->left=tmp->right;
    tmp->right=T;
    return tmp;
}

tree l_rotate(tree T){
    tree tmp=T->right;
    T->right=tmp->left;
    tmp->left=T;
    return tmp;
}

void set_h(tree T){
    if(T==NULL)
        return;
    if(T->left==NULL&&T->right==NULL)
        T->height=1;
    else if(T->left==NULL)
        T->height=T->right->height+1;
    else if(T->right==NULL)
        T->height=T->left->height+1;
    else if(T->left->height>T->right->height)
        T->height=T->left->height+1;
    else
        T->height=T->right->height+1;
}

tree insert(tree T,int n){
    if(T==NULL)
    {
        tree new_node;
        new_node=new struct node[1];
        new_node->element=n;
        new_node->left=NULL;
        new_node->right=NULL;
        new_node->height=1;
        return new_node;
    }
    else if(n<T->element)
        T->left=insert(T->left,n);
    else if(n>T->element)
        T->right=insert(T->right,n);
    if(height(T->left)-height(T->right)>1)
    {
        if(height(T->left->left)>height(T->left->right))
            T=r_rotate(T);
        else{
            T->left=l_rotate(T->left);
            T=r_rotate(T);
        }
    }
    else if(height(T->right)-height(T->left)>1)
    {
        if(height(T->right->right)>height(T->right->left))
            T=l_rotate(T);
        else{
            T->right=r_rotate(T->right);
            T=l_rotate(T);
        }
    }
    set_h(T->left);
    set_h(T->right);
    set_h(T);
    return T;
}

int main(int argc, const char * argv[]) {
    int n,p;
    tree T=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&p);
        T=insert(T,p);
    }
    printf("%d\n",T->element);
    return 0;
}
