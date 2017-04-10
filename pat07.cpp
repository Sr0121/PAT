//
//  main.cpp
//  pat07
//
//  Created by Sr on 2017/3/5.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,i,front_max=0,rear_max=0,sum_max=-1,sum=0,front=0;
    int *a;
    cin>>n;
    a=new int[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum>sum_max)
        {
            front_max=front;
            sum_max=sum;
            rear_max=i;
        }
        if(sum<0)
        {
            sum=0;
            front=i+1;
        }
    }
    if(sum_max==-1)//注意 4 -1 0 0 -1的特例
    {
        rear_max=n-1;
        sum_max=0;
    }
    cout<<sum_max<<' '<<a[front_max]<<' '<<a[rear_max];
    return 0;
}
