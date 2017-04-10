//
//  main.cpp
//  pat69
//
//  Created by Sr on 2017/4/10.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int set(int n,int i){
    int a[4];
    a[0]=n%10;
    a[1]=n/10%10;
    a[2]=n/100%10;
    a[3]=n/1000;
    if(i)
        sort(a,a+4,cmp);
    else
        sort(a,a+4);
    n=a[3]*1000+a[2]*100+a[1]*10+a[0];
    return n;
}

int main(int argc, const char * argv[]) {
    int n,m,r=-1;
    scanf("%d",&n);
    while(r!=0&&r!=6174){
        n=set(n,0);
        m=set(n,1);
        r=n-m;
        printf("%04d - %04d = %04d\n",n,m,r);
        n=r;
    }
    return 0;
}
