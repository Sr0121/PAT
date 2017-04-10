//
//  main.cpp
//  pat64
//
//  Created by Sr on 2017/4/8.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int index_num,n;
void build_tree(int *s,int *t,int num){
    if(2*num+1<n)
        build_tree(s,t,2*num+1);
    t[num]=s[index_num++];
    if(2*num+2<n)
    build_tree(s,t,2*num+2);
}

int main(int argc, const char * argv[]) {
    int *s,*t;
    scanf("%d",&n);
    s=new int [n];
    t=new int [n];
    for(int i=0;i<n;i++)
        scanf("%d",&s[i]);
    sort(s,s+n);
    build_tree(s,t,0);
    printf("%d",t[0]);
    for(int i=1;i<n;i++)
        printf(" %d",t[i]);
    printf("\n");
    return 0;
}
