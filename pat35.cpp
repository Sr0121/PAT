//
//  main.cpp
//  pat35
//
//  Created by Sr on 2017/3/19.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
using namespace std;
int cnt,*flag;

string modify(string s,int n)
{
    int len=(int)s.length();
    int f=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='1')
        {
            s[i]='@';
            f=1;
        }
        else if(s[i]=='0')
        {
            s[i]='%';
            f=1;
        }
        else if(s[i]=='l')
        {
            s[i]='L';
            f=1;
        }
        else if(s[i]=='O')
        {
            s[i]='o';
            f=1;
        }
    }
    if(f)
        cnt++;
    flag[n]=f;
    return s;
}

int main(int argc, const char * argv[]) {
    int n;
    string *id,*password;
    cin>>n;
    flag=new int [n];
    id=new string[n];
    password=new string[n];
    for(int i=0;i<n;i++)
        cin>>id[i]>>password[i];
    for(int i=0;i<n;i++)
        password[i]=modify(password[i],i);
    if(cnt==0)
    {
        if(n==1)
            printf("There is 1 account and no account is modified");
        else
            printf("There are %d accounts and no account is modified",n);
    }
    else
    {
        cout<<cnt<<endl;
        for(int i=0;i<n;i++)
        {
            if(flag[i])
                cout<<id[i]<<' '<<password[i]<<endl;
        }
    }
    return 0;
}
