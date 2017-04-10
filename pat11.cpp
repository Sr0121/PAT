//
//  main.cpp
//  pat11
//
//  Created by Sr on 2017/3/5.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;
char CharTable[3] = {'W', 'T', 'L'};

int max(double a,double b,double c)
{
    if(a>b&&a>c)
        return 0;
    else if(b>c&&b>a)
        return 1;
    else
        return 2;
}

int main()
{
    int max_num[3];
    double total;
    double a[3][3];
    int i;
    for(i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin>>a[i][j];
    for(i=0;i<3;i++)
        max_num[i]=max(a[i][0],a[i][1],a[i][2]);
    for(i=0;i<3;i++)
        cout<<CharTable[max_num[i]]<<' ';
    total=(a[0][max_num[0]]*a[1][max_num[1]]*a[2][max_num[2]]*0.65-1)*2;
    printf("%.2f",total);
    return 0;
}
