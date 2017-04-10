//
//  main.cpp
//  pat44
//
//  Created by Sr on 2017/3/31.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int n,m,front=1,rear=0,sum=0,flag=0;
    scanf("%d %d",&n,&m);
    int min=100000,cnt=0;
    int a[100002],b[100002],c[100002];
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    while(front<=n)
    {
        if(sum<m)
        {
            if(rear<n){
                rear++;
                sum+=a[rear];
            }
            else
                break;
        }
        else if(sum>m)
        {
            if(sum<min)
            {
                cnt=1;
                b[cnt]=front;
                c[cnt]=rear;
                min=sum;
            }
            else if(sum==min)
            {
                cnt++;
                b[cnt]=front;
                c[cnt]=rear;
            }
            if(front<n){
                sum-=a[front];
                front++;
            }
            else
                break;
        }
        else if(sum==m)
        {
            flag=1;
            printf("%d-%d\n",front,rear);
            if(rear<n){
                rear++;
                sum+=a[rear];
            }
            else{
                front++;
                if(front<=n)
                    sum-=a[front];
            }
        }
    }
    if(flag==0)
    {
        for(int i=1;i<=cnt;i++)
        {
            printf("%d-%d\n",b[i],c[i]);
        }
    }
    return 0;
}
