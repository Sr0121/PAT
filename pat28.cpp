//
//  main.cpp
//  pat28
//
//  Created by Sr on 2017/3/15.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

struct info{
    int id;
    char name[20];
    int grade;
};

bool cmp1(const struct info &a,const struct info &b)
{
    return a.id<b.id;
}

bool cmp2(const info &a,const info &b)
{
    if(strcmp(a.name,b.name)==0)
    {
        return a.id<b.id;
    }
    else return strcmp(a.name, b.name)<0;
}

bool cmp3(const info &a,const info &b)
{
    if(a.grade==b.grade)
    {
        return a.id<b.id;
    }
    else
        return a.grade<b.grade;
}

int main(int argc, const char * argv[]) {
    int N,C;
    struct info *info;
    cin>>N>>C;
    info=new struct info[N];
    for(int i=0;i<N;i++)
        scanf("%d%s%d",&info[i].id,info[i].name,&info[i].grade);
    switch (C) {
        case 1:sort(info, info+N, cmp1);
            break;
        case 2:sort(info, info+N, cmp2);
            break;
        case 3:sort(info, info+N, cmp3);
            break;
    }
    for(int i=0;i<N;i++)
        printf("%06d %s %d\n",info[i].id,info[i].name,info[i].grade);
    return 0;
}

//cin,cout没有scanf和printf快
//sort是经过优化的qsort
