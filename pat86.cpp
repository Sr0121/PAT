//
//  main.cpp
//  pat86
//
//  Created by Sr on 2017/4/15.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STRING_LEN 5
#define MAX_SIZE 31

struct node
{
    int element;
    struct node *left,*right;
} ;

typedef struct node *tree;
tree top=NULL,ntop=NULL;
tree stack[MAX_SIZE];
void printtree(tree d);

main()
{
    int n,i,a,rear,poped=0;
    char str[STRING_LEN];
    tree d,pre,now;
    rear=-1;
    
    scanf("%d",&n);
    for(i=0;i<2*n;i++)
    {
        scanf("%s",str);
        if(!strcmp(str,"Push"))
        {
            scanf("%d",&a);
            d=(tree)malloc(sizeof(struct node));
            d->element=a;
            d->left=NULL;
            d->right=NULL;
            if(top==NULL)
            {
                top=d;
            }
            rear++;
            if(poped==1)
            {
                pre=stack[rear];
            }
            stack[rear]=d;
            if(poped==1)
            {
                pre->right=stack[rear];
            }
            else
                if(rear!=0)
                {
                    stack[rear-1]->left=stack[rear];
                }
            poped=0;
        }
        
        if(!strcmp(str,"Pop"))
        {
            rear--;
            poped=1;
        }
    }
    printtree(top);
}

void printtree(tree d)
{
    if(d==NULL)
        return;
    if(d->left==NULL&&d->right==NULL&&d!=top)
    {
        printf("%d ",d->element);
        return ;
    }
    printtree(d->left);
    printtree(d->right);
    if(d!=top)
        printf("%d ",d->element);
    if(d==top)
        printf("%d",d->element);
    return; 
}




