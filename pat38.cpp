//
//  main.cpp
//  pat38
//
//  Created by Sr on 2017/3/18.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int cmp(string a,string b)
{
    return a+b < b+a;
}

int main(int argc, const char * argv[]) {
    int n,flag=0;
    string *a;
    string b="";
    cin>>n;
    a=new string[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
        b+=a[i];
    for(int i=0;b[i]!='\0';i++)
        if(b[i]!='0'||flag==1)
        {
            flag=1;
            cout<<b[i];
        }
    if(!flag)
        cout<<0;
    return 0;
}
