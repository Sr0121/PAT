//
//  main.cpp
//  pat47
//
//  Created by Sr on 2017/4/3.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

typedef struct student{
    char name[5];
    bool operator < ( const struct student &x) const{
        return strcmp(name, x.name) < 0;
    }
}Student;


int main(int argc, const char * argv[]) {
    int m,n,c,num;
    Student info;
    scanf("%d%d",&m,&n);
    vector<vector<Student> > class_name(n+1);
    for(int i=0;i<m;i++){
        scanf("%s%d",info.name,&c);
        string st;
        for(int i=0;i<c;i++)
        {
            scanf("%d",&num);
            class_name[num].push_back(info);
        }
    }
    for(int i=1;i<=n;i++)
        sort(class_name[i].begin(),class_name[i].end());
    for(int i=1;i<=n;i++){
        printf("%d %lu\n",i,class_name[i].size());
        for(int j=0;j<class_name[i].size();j++)
            printf("%s\n",class_name[i][j].name);
    }
    return 0;
}
