//
//  main.cpp
//  pat19
//
//  Created by Sr on 12/03/2017.
//  Copyright © 2017 Sr. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int a[1001]={0};
int len=0;

int hexadecimal_conversion(long long n, int radix)
{
    int flag=0;
    int i=0;
    if(n==0)
    {
        a[0]=0;
        len=1;
    }
    while(n!=0)
    {
        a[len++]=n%radix;
        n=n/radix;
    }
    len=len-1;
    while(len-i>=i)
    {
        if(a[i]!=a[len-i])
        {flag=1;break;}
        i++;
    }
    return flag;
}

int main(int argc, const char * argv[]) {
    long long n;
    int radix;
    cin>>n>>radix;
    if(hexadecimal_conversion(n, radix))
    {
        cout<<"No"<<endl<<a[len];
        len--;
        for(;len>=0;len--)
        {
            cout<<" "<<a[len];
        }
    }
    else
    {
        cout<<"Yes"<<endl<<a[len];
        len--;
        for(;len>=0;len--)
        {
            cout<<" "<<a[len];
        }
    }
    return 0;
}
