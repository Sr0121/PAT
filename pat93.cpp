//
//  main.cpp
//  pat93
//
//  Created by Sr on 2017/4/16.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    cin>>s;
    int p=0,pa=0,pat=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='P')
            p++;
        else if(s[i]=='A')
            pa+=p;
        else if(s[i]=='T')
            pat+=pa;
        pat=pat%1000000007;
    }
    cout<<pat<<endl;
    return 0;
}
