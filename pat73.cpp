//
//  main.cpp
//  pat73
//
//  Created by Sr on 2017/4/10.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string num;
    string fraction;
    int exp=0;
    int flag=1;
    string out_put="";
    cin>>num;
    for(int i=0;num[i]!='\0';i++){
        if(num[i]=='E'){
            i++;
            if(num[i]=='-')
                flag=-1;
            i++;
            while(num[i]!='\0'){
                exp+=(num[i]-'0');
                exp*=10;
                i++;
            }
        }
        else
            fraction+=num[i];
    }
    exp/=10;
    exp*=flag;
    if(fraction[0]=='-')
        out_put+='-';
    if(exp<0)
    {
        out_put+="0.";
        for(int i=exp;i<-1;i++)
            out_put+='0';
        for(int i=1;fraction[i]!='\0';i++){
            if(fraction[i]=='.')
                continue;
            out_put+=fraction[i];
        }
    }
    else if(exp>0){
        int i;
        for(i=1;fraction[i]!='\0';i++){
            if(fraction[i]=='.')
                continue;
            out_put+=fraction[i];
            if(i==exp+2&&fraction[i+1]!='\0')
            {
                out_put+='.';
            }
        }
        for(;i<exp+3;i++){
            out_put+='0';
        }
    }
    else
        for(int i=1;fraction[i]!='\0';i++)
            out_put+=fraction[i];
    cout<<out_put<<endl;
    return 0;
}
