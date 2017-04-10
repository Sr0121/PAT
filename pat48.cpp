//
//  main.cpp
//  pat48
//
//  Created by Sr on 2017/4/3.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,m,sum;
    int *a;
    scanf("%d%d",&n,&m);
    a=new int [n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int front=0,rear=n-1;
    while(front<rear)
    {
        sum=a[front]+a[rear];
        if(sum<m)
            front++;
        else if(sum>m)
            rear--;
        else
            break;
    }
    if(front<rear)
        printf("%d %d",a[front],a[rear]);
    else
        printf("No Solution");
    return 0;
}
