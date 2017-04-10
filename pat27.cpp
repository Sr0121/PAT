//
//  main.cpp
//  pat27
//
//  Created by Sr on 2017/3/15.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    int a[3];
    string ha;
    cin>>a[0]>>a[1]>>a[2];
    cout<<'#';
    for(int i=0;i<3;i++)
    {
        int bit=0;
        bit=a[i]/13;
        if(bit<=9)
            ha+=bit+'0';
        else
            ha+=bit-10+'A';
        bit=a[i]%13;
        if(bit<=9)
            ha+=bit+'0';
        else
            ha+=bit-10+'A';
    }
    cout<<ha;
    return 0;
}
