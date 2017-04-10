//
//  main.cpp
//  pat40
//
//  Created by Sr on 2017/3/20.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

int main(int argc, const char * argv[]) {
    char s[1001];
    int max=0;
    int num=0;
    gets(s);
    for(int i=0;i<strlen(s);i++)
    {
        num=0;
        for(int j=0;i-j>=0&&(i+j)<strlen(s);j++)
        {
            if(s[i-j]==s[i+j])
               num++;
            else break;
        }
        num=num*2-1;
        if(num>max)
            max=num;
        num=0;
        for(int j=1;i-j+1>=0&&(i+j)<strlen(s);j++)
        {
            if(s[i-j+1]==s[i+j])
                num++;
            else break;
        }
        num*=2;
        if(num>max)
            max=num;
    }
    cout<<max;
    return 0;
}
