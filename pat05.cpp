//
//  main.cpp
//  pat05
//
//  Created by Sr on 2017/3/5.
//  Copyright © 2017年 Sr. All rights reserved.
//


#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void print(int n)
{
    switch (n) {
        case 1:
            cout<<"one";
            break;
        case 2:
            cout<<"two";
            break;
        case 3:
            cout<<"three";
            break;
        case 4:
            cout<<"four";
            break;
        case 5:
            cout<<"five";
            break;
        case 6:
            cout<<"six";
            break;
        case 7:
            cout<<"seven";
            break;
        case 8:
            cout<<"eight";
            break;
        case 9:
            cout<<"nine";
            break;
        default:
            cout<<"zero";
            break;
    }
}

int main(int argc, const char * argv[]) {
    int sum=0,i=0;
    string n,str;
    int l=0;
    cin>>n;
    while(n[i]!='\0')
    {
        sum+=n[i]-'0';
        i++;
    }
    str=to_string(sum);//数字转化为字符串
    while(str[l]!='\0')
    {
        print(str[l]-'0');
        l++;
        if(str[l]!='\0')
            cout<<' ';
    }
    return 0;
}
