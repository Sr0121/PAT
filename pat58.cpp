//
//  main.cpp
//  pat58
//
//  Created by Sr on 2017/4/6.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int a1,a2,a3;
    int b1,b2,b3;
    int c1,c2,c3;
    int ca1,ca2;
    scanf("%d.%d.%d",&a1,&a2,&a3);
    scanf("%d.%d.%d",&b1,&b2,&b3);
    c3=(a3+b3)%29;
    ca2=(a3+b3)/29;
    c2=(a2+b2+ca2)%17;
    ca1=(a2+b2+ca2)/17;
    c1=(a1+b1+ca1);
    printf("%d.%d.%d\n",c1,c2,c3);
    return 0;
}
