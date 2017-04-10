//
//  main.cpp
//  pat55
//
//  Created by Sr on 2017/4/4.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct info{
    char name[9];
    int age;
    int asset;
    bool operator < (const struct info &x)const{
        if(asset!=x.asset)
            return asset>x.asset;
        else if(age!=x.age)
            return age<x.age;
        else return strcmp(name,x.name)<0;
    }
};

void check(struct info *info,int num,int min,int max,int m,int time){
    int out_num=0;
    for(int i=0;i<m;i++){
        if(info[i].age>=min&&info[i].age<=max){
            printf("%s %d %d\n",info[i].name,info[i].age,info[i].asset);
            out_num++;
            if(out_num==num)
                return;
        }
    }
    if(out_num==0)
        printf("None\n");
}

int main(int argc, const char * argv[]) {
    struct info info[100001];
    int m,n;
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++){
        scanf("%s%d%d",info[i].name,&info[i].age,&info[i].asset);
    }
    sort(info,info+m);
    int num,min,max;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&num,&min,&max);
        printf("Case #%d:\n",i+1);
        check(info,num,min,max,m,i);
    }
    return 0;
}
