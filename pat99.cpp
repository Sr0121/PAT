//
//  main.cpp
//  pat99
//
//  Created by Sr on 2017/4/15.
//  Copyright © 2017年 Sr. All rights reserved.
//  请使用gcc编译

#include<stdio.h>
#include<stdlib.h>

typedef struct node *tree;
struct node {
    int key;
    int num_of_node;
    tree left;
    tree right;
};

tree create_tree(tree top);
void fill_num(tree top,int *a);
int print_tree(tree top);
void set_numofnode(tree top);
int num,NUMOFNODE;
tree whole_top;


int compinc(int *a, int *b)
{
    return *(int *)a -*(int *)b;
}

main()
{
    tree top;
    int n,*a,i;
    scanf("%d",&num);
    
    whole_top=top=(tree)malloc(sizeof(struct node));
    top->num_of_node=0;
    create_tree(top);
    
    a=(int *)malloc(num*sizeof(int));
    for(i=0;i<num;i++)
    {
        scanf("%d",a+i);
    }
    qsort(a,num,sizeof(a[0]),compinc);
    set_numofnode(top);
    fill_num(top,a);
    for(i=0;i<105;i++)
        print_tree(top);
}

tree create_tree(tree top)
{
    tree node1;
    tree queue[205];
    int front=0,rear=1,i=1,j=0;
    int LEFT,RIGHT;
    if(top!=NULL)
        queue[0]=top;
    while(i<=num){
        scanf("%d %d",&LEFT,&RIGHT);
        if(LEFT!=-1){
            node1=(tree)malloc(sizeof(struct node));
            node1->num_of_node=LEFT;
            queue[rear++]=node1;
        }
        else
            queue[rear++]=NULL;
        if(RIGHT!=-1){
            node1=(tree)malloc(sizeof(struct node));
            node1->num_of_node=RIGHT;
            queue[rear++]=node1;
        }
        else
            queue[rear++]=NULL;
        i++;
    }
    front=1;
    for(i=0;i<rear;i++)
    {
        if(queue[i]!=NULL)
        {queue[i]->left=queue[2*queue[i]->num_of_node+1];
            queue[i]->right=queue[2*queue[i]->num_of_node+2];
        }
    }
    return top;
    
}

void set_numofnode(tree top)
{
    if(top->left!=NULL)
        set_numofnode(top->left);
    top->num_of_node=NUMOFNODE;
    NUMOFNODE++;
    if(top->right==NULL)
        return;
    set_numofnode(top->right);
    
    return ;
}

void fill_num(tree top,int *a)
{
    top->key=a[top->num_of_node];
    if(top->left!=NULL)
        fill_num(top->left,a);
    if(top->right!=NULL)
        fill_num(top->right,a);
}

int print_tree(tree top)
{
    if(top==whole_top&&top->key!=-1)
    {
        printf("%d",top->key);
        top->key=-1;
        return 0;
    }
    if(top->key==-1)
    {
        if(top->left!=NULL)
            print_tree(top->left);
        if(top->right!=NULL)
            print_tree(top->right);
        if(top->left!=NULL&&top->left->key!=-1)
        {
            printf(" %d",top->left->key);
            top->left->key=-1;
        }
        if(top->right!=NULL&&top->right->key!=-1)
        {
            printf(" %d",top->right->key);
            top->right->key=-1;
        }
        return 0;
    }
    
    return 0;
}

