//
//  main.cpp
//  pat45
//
//  Created by Sr on 2017/4/1.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,a,*s1,b,*s2,*s3;
    cin>>n>>a;
    s1=new int [a];
    for(int i=0;i<a;i++)
        cin>>s1[i];
    cin>>b;
    s2=new int [b];
    s3=new int [b];
    memset(s3, 0, sizeof(int)*b);
    for(int i=0;i<b;i++)
        cin>>s2[i];
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            if(j>0&&s3[j-1]>s3[j])
                s3[j]=s3[j-1];
            if(s2[j]==s1[i])
                s3[j]++;
        }
    }
    cout<<s3[b-1];
    return 0;
}
