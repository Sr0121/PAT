//
//  main.cpp
//  pat37
//
//  Created by Sr on 2017/3/19.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <algorithm>

int main(int argc, const char * argv[]) {
    long long *coupon,*value;
    int c1,c2;
    long long sum=0;
    int i;
    scanf("%d",&c1);
    coupon=new long long[c1];
    for(i=0;i<c1;i++)
        scanf("%lld",&coupon[i]);
    scanf("%d",&c2);
    value=new long long[c2];
    for(i=0;i<c2;i++)
        scanf("%lld",&value[i]);
    std::sort(value,value+c2);
    std::sort(coupon,coupon+c1);
    i=0;
    while(coupon[i]<0&&value[i]<0)
    {
        sum+=coupon[i]*value[i];
        i++;
    }
    int j=i;
    i=1;
    while(coupon[c1-i]>0&&value[c2-i]>0&&j<=c1-i&&j<=c2-i)//后面的数字不能比前面的小
    {
        sum+=coupon[c1-i]*value[c2-i];
        i++;
    }
    if(coupon[0]>0&&value[c2-1]<0)
        sum=coupon[0]*value[c2-1];
    else if(coupon[c1-1]<0&&value[0]>0)
        sum=coupon[c1-1]*value[0];
    printf("%lld",sum);
    return 0;
}
