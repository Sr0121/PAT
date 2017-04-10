//
//  main.cpp
//  pat41
//
//  Created by Sr on 2017/3/15.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int num;
    int index;
    bool operator <(const node &x) const
    {
        return num<x.num;
    }
};

int check(int min,struct node *info,int i)
{
    if(min==-1)
        return i;
    if(info[min].index>info[i].index)
        return i;
    return min;
}

int main(int argc, const char * argv[]) {
    int n,min=-1;
    struct node *info;
    cin>>n;
    info=new struct node[n];
    for(int i=0;i<n;i++)
    {
        cin>>info[i].num;
        info[i].index=i;
    }
    sort(info,info+n);
    if(n==1)
        cout<<info[0].num;
    else{
    for(int i=0;i<n;i++)
    {
        if(i==0&&info[i].num!=info[i+1].num)
            min=check(min,info,i);
        else if(i==n-1&&info[i-1].num!=info[i].num)
            min=check(min,info,i);
        else if(info[i-1].num!=info[i].num&&info[i].num!=info[i+1].num)
            min=check(min,info,i);
    }
        if(min==-1)
            cout<<"None";
        else cout<<info[min].num;
    }
    return 0;
}
