//
//  main.cpp
//  pat24
//
//  Created by Sr on 2017/3/13.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(int argc, const char * argv[]) {
    string str1,str2;
    int num,carry=0,time,j=0;
    int flag=0;
    cin>>str1>>time;
    str2+=str1;
    reverse(str2.begin(), str2.end());
    if(str2==str1)
        cout<<str1<<endl<<j<<endl;
    else
    {
        str2="";
        for(j=1;j<=time;j++)
        {
            for(int i=(int)str1.length()-1;i>=0;i--)
            {
                num=str1[i]-'0'+str1[str1.length()-1-i]-'0'+carry;
                carry=num/10;
                num=num%10;
                str2.push_back(num+'0');
            }
            if(carry)
            {
                str2.push_back('0'+carry);
                carry=0;
            }
            string str4(str2.rbegin(),str2.rend());
            if(str4==str2)
            {
                flag=1;
                break;
            }
            str1="";
            str1.append(str2);
            if(j!=time)
                str2="";
        }
        string str4(str2.rbegin(),str2.rend());
        cout<<str4<<endl;
        if(flag)
            cout<<j<<endl;
        else
            cout<<time<<endl;
    }
    return 0;
}
