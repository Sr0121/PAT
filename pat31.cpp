//
//  main.cpp
//  pat31
//
//  Created by Sr on 2017/3/17.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    string str1;
    cin>>str1;
    int len=(int)str1.length();
    int n1=(len+2)/3;
    int n2=len-2*n1+2;
    for(int i=0;i<n1-1;i++)
    {
        cout<<str1[i];
        for(int j=0;j<n2-2;j++)
        {
            cout<<' ';
        }
        cout<<str1[len-1-i]<<endl;
    }
    string str2(str1.begin()+n1-1,str1.begin()+n1+n2-1);
    cout<<str2<<endl;
    return 0;
}
