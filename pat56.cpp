//
//  main.cpp
//  pat56
//
//  Created by Sr on 2017/4/5.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
using namespace std;

void find_max(int *check,int *rank,int *s,int p,int g)
{
    if(p==1)
    {
        rank[check[0]]=1;
        return;
    }
    int index=0;
    int max=0;
    int max_index=-1;
    int ran=(p+g-1)/g+1;
    for(int i=0;i<p;i=i+g){
        max=0;
        max_index=-1;
        for(int j=i;j<i+g&&j<p;j++){
            if(s[check[j]]>max){
                max=s[check[j]];
                max_index=check[j];
            }
            rank[check[j]]=ran;
        }
        check[index++]=max_index;
    }
    find_max(check,rank,s,index,g);
    return;
}

int main(int argc, const char * argv[]) {
    int p,g;
    int s[1001];
    int check[1001];
    int rank[1001];
    scanf("%d%d",&p,&g);
    for(int i=0;i<p;i++)
        scanf("%d",&s[i]);
    for(int i=0;i<p;i++)
        scanf("%d",&check[i]);
    find_max(check,rank,s,p,g);
    printf("%d",rank[0]);
    for(int i=1;i<p;i++)
        printf(" %d",rank[i]);
    printf("\n");
    return 0;
}
