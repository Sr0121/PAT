//
//  main.cpp
//  pat92
//
//  Created by Sr on 2017/4/15.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    map<char,int> dic;
    int miss=0;
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<s1.length();i++){
        if(dic.find(s1[i])==dic.end())
            dic[s1[i]]=1;
        else
            dic[s1[i]]++;
    }
    for(int i=0;i<s2.length();i++){
        if(dic.find(s2[i])==dic.end())
        {
            miss++;
        }
        else{
            dic[s2[i]]--;
            if(dic[s2[i]]<0)
                miss++;
        }
    }
    if(miss>0){
        cout<<"No"<<" "<<miss<<endl;
    }
    else
        cout<<"Yes"<<" "<<s1.length()-s2.length()<<endl;
    return 0;
}
