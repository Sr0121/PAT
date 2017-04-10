//
//  main.cpp
//  pat01
//
//  Created by Sr on 2017/4/10.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int a,b,sum,k=1000000;
    int flag=0;
    cin>>a;
    cin>>b;
    sum=a+b;
    if(sum==0)
    {
        cout<<0;
        return 0;
    }
    if(sum<0)
    {
        cout<<'-';
        sum=-sum;
    }
    while(k>0)
    {
        if(sum/k||flag)
        {
            if(sum/k>99||flag==0)
                cout<<sum/k;
            else if(sum/k>9)
                cout<<'0'<<sum/k;
            else cout<<"00"<<sum/k;
            flag=1;
        }
        sum=sum%k;
        if(k>1&&flag==1)
            cout<<',';
        k/=1000;
    }
    return 0;
}
