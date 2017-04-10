//
//  main.cpp
//  pat20
//
//  Created by Sr on 12/03/2017.
//  Copyright © 2017 Sr. All rights reserved.
//

#include <iostream>
using namespace std;

typedef struct point *tree;

struct point{
    int i;
    tree left;
    tree right;
};

int check(int n,int *s,int len)
{
    for(int i=1;i<=len;i++)
        if(s[i]==n)
            return i;
    return -1;
}

tree create_tree(int *inorder,int *postorder,int left,int right,int len)
{
    if(right==0||left==10000)
        return NULL;
    tree head;
    head=new struct point[1];
    head->i=postorder[right];
    head->left=NULL;
    head->right=NULL;
    int index=check(head->i,inorder,len);
    int max=0,min=10000,left_in=10000,right_in=0;
    for(int i=left;i<=right;i++)
    {
        int tmp;
        tmp=check(postorder[i],inorder,len);
        if(tmp>right_in)
            right_in=tmp;
        if(tmp<left_in)
            left_in=tmp;
    }
    for(int i=left_in;i<=index-1;i++)
    {
        int tmp;
        tmp=check(inorder[i],postorder,len);
        if(tmp>max)
            max=tmp;
    }
    for(int i=index+1;i<=right_in;i++)
    {
        int tmp;
        tmp=check(inorder[i],postorder,len);
        if(tmp<min)
            min=tmp;
    }
    head->left=create_tree(inorder, postorder, left, max, len);
    head->right=create_tree(inorder, postorder, min, right-1, len);
    return head;
}

int main(int argc, const char * argv[]) {
    int n;
    int *postorder,*inorder;
    cin>>n;
    tree head;
    postorder=new int[n+1];
    inorder=new int[n+1];
    for(int i=1;i<=n;i++)
        cin>>postorder[i];
    for(int i=1;i<=n;i++)
        cin>>inorder[i];
    head=create_tree(inorder,postorder,1,n,n);
    tree queue[40];
    int front=0,rear=0;
    queue[0]=head;
    while(front<=rear)
    {
        if(queue[front]->left)
            queue[++rear]=queue[front]->left;
        if(queue[front]->right)
            queue[++rear]=queue[front]->right;
        front++;
    }
    cout<<queue[0]->i;
    for(int i=1;i<n;i++)
        cout<<' '<<queue[i]->i;
    return 0;
}
