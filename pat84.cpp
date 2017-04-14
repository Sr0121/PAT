//
//  main.cpp
//  pat84
//
//  Created by Sr on 2017/4/14.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    map<char,int> dic;
    string dic_out;
    string s1,s2;
    int i1=0,i2=0;
    cin>>s1>>s2;
    while(i1<s1.size()){
        if(s1[i1]!=s2[i2]){
            if(islower(s1[i1]))
                s1[i1]-=32;
            if(dic.find(s1[i1])==dic.end())
            {
                dic[s1[i1]]=1;
                dic_out.push_back(s1[i1]);
            }
            i1++;
        }
        else{
            i1++;
            i2++;
        }
    }
    cout<<dic_out<<endl;
    return 0;
}
