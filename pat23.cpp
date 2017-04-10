//
//  main.cpp
//  pat23
//
//  Created by Sr on 2017/3/13.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str1,str2;
    char a;
    int len,carry=0,num;
    cin>>str1;
    len=str1.length();
    for(int i=len-1;i>=0;i--)
    {
        a=str1[i];
        num=(a-'0')*2+carry;
        carry=num/10;
        num=num%10;
        a=num+'0';
        str2.push_back(a);
    }
    if(carry)
        str2.push_back('1');
    string str3(str2.rbegin(),str2.rend());
    sort(&str1[0],&str1[0]+str1.length());
    sort(&str2[0],&str2[0]+str2.length());
    if(str1==str2)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    cout<<str3<<endl;
    return 0;
}
