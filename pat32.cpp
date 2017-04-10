//
//  main.cpp
//  pat32
//
//  Created by Sr on 2017/3/18.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
using namespace std;

int check(int *address,int start1,int start2)
{
    int tmp;
    while(address[start1]!=-1)
    {
        tmp=address[start1];
        address[start1]=-100;
        start1=tmp;
    }
    while(address[start2]!=-1&&address[start2]!=-100)
    {
        tmp=address[start2];
        address[start2]=-100;
        start2=tmp;
    }
    if(address[start2]==-1)
        return -1;
    else return start2;
}

int main(int argc, const char * argv[]) {
    int address[100000];
    int start1,start2,N;
    scanf("%d %d %d",&start1,&start2,&N);
    for(int i=0;i<N;i++)
    {
        int s,d;
        char n;
        scanf("%d %c %d",&s,&n,&d);
        address[s]=d;
    }
    int suffix=check(address,start1,start2);
    if(suffix!=-1)
        printf("%05d",suffix);
    else printf("%d",suffix);
    return 0;
}
