//
//  main.cpp
//  pat102
//
//  Created by Sr on 2017/4/16.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> queue;
struct node{
    int element;
    int left;
    int right;
};

void in_order(vector<struct node> T,int root){
    if(T[root].right!=-1)
        in_order(T, T[root].right);
    queue.push_back(root);
    if(T[root].left!=-1)
        in_order(T, T[root].left);
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    vector<struct node> T(n);
    vector<int> root(n);
    for(int i=0;i<n;i++){
        T[i].element=i;
        char l,r;
        cin>>l>>r;
        if(l!='-')
        {
            T[i].left=l-'0';
            root[T[i].left]=1;
        }
        else
            T[i].left=-1;
        if(r!='-')
        {
            T[i].right=r-'0';
            root[T[i].right]=1;
        }
        else
            T[i].right=-1;
    }
    int r=-1;
    for(int i=0;i<n;i++)
        if(root[i]!=1){
            r=i;
            break;
        }
    queue.push_back(r);
    for(int i=0;i<n;i++){
        if(T[queue[i]].right!=-1){
            queue.push_back(T[T[queue[i]].right].element);
        }
        if(T[queue[i]].left!=-1){
            queue.push_back(T[T[queue[i]].left].element);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i>0)
            cout<<' ';
        cout<<queue[i];
    }
    cout<<endl;
    queue.clear();
    in_order(T,r);
    for(int i=0;i<n;i++)
    {
        if(i>0)
            cout<<' ';
        cout<<queue[i];
    }
    cout<<endl;
    return 0;
}
