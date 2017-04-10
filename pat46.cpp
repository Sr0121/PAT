//
//  main.cpp
//  pat46
//
//  Created by Sr on 2017/4/2.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,*a,*b,sum=0,sum2;
    int s,d;
    scanf("%d",&n);
    a=new int [n];
    b=new int [n+1];
    b[0]=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
        b[i+1]=sum;
    }
    int times;
    scanf("%d",&times);
    for(int i=0;i<times;i++){
        scanf("%d %d",&s,&d);
        if(d<s){
            int tmp;
            tmp=s;
            s=d;
            d=tmp;
        }
        sum2=b[d-1]-b[s-1];
        if(sum2>sum-sum2)
            sum2=sum-sum2;
        printf("%d\n",sum2);
    }
    return 0;
}
