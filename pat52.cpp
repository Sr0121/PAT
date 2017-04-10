//
//  main.cpp
//  pat52
//
//  Created by Sr on 2017/4/4.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
typedef struct info *node;

struct info{
    int add;
    int element;
    int next;
    bool operator < (const struct info &x)const{
        return element<x.element;
    }
};

int main(int argc, const char * argv[]) {
    int num,start,addr,num_of_ele=0;
    struct info info[100001];
    struct info info2[100001];
    scanf("%d%d",&num,&start);
    if(start==-1)//很坑
    {
        printf("0 -1\n");
        return 0;
    }
    for(int i=0;i<num;i++){
        scanf("%d",&addr);
        info[addr].add=addr;
        scanf("%d%d",&info[addr].element,&info[addr].next);
    }
    for(int i=start;i!=-1;i=info[i].next)
        info2[num_of_ele++]=info[i];
    sort(info2,info2+num_of_ele);
    printf("%d %05d\n",num_of_ele,info2[0].add);
    for(int i=0;i<num_of_ele;i++)
    {
        if(i!=num_of_ele-1)
            printf("%05d %d %05d\n",info2[i].add,info2[i].element,info2[i+1].add);
        else
            printf("%05d %d -1\n",info2[i].add,info2[i].element);
    }
    return 0;
}
