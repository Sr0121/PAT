//
//  main.cpp
//  pat81
//
//  Created by Sr on 2017/4/14.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return b==0 ? a : gcd(b, a%b);
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    int numerator=0,denominator=1;
    for(int i=0;i<n;i++){
        int in_n,in_d,g;
        scanf("%d/%d",&in_n,&in_d);
        g=gcd(denominator, in_d);
        numerator=numerator*in_d/g+in_n*denominator/g;
        denominator=denominator*in_d/g;
    }
    if(numerator%denominator==0)
    {
        printf("%d\n",numerator/denominator);
        return 0;
    }
    int g=gcd(numerator, denominator);
    numerator/=g;
    denominator/=g;
    if(numerator>denominator)
        printf("%d %d/%d\n",numerator/denominator,numerator%denominator,denominator);
    else
        printf("%d/%d\n",numerator%denominator,denominator);
    return 0;
}
