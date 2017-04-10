//
//  main.cpp
//  pat50
//
//  Created by Sr on 2017/4/3.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

int main(int argc, const char * argv[]) {
    char s1[10001],s2[10001];
    gets(s1);
    gets(s2);
    int len=strlen(s1);
    for(int i=0;i<len;i++)
        if(strchr(s2, s1[i])==NULL)
            printf("%c",s1[i]);
    return 0;
}
