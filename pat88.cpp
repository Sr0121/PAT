//
//  main.cpp
//  pat88
//
//  Created by Sr on 2017/4/15.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
using namespace std;

long long gcd(long long a,long long b){
    return (b==0)?a:gcd(b,a%b);
}

void output(long long a,long long b){
    if(a==0)
    {
        cout<<"0";
        return;
    }
    else{
        int flag=0;
        long long i1;
        if(a<0)
        {
            flag=1;
            a=-a;
        }
        long long g=gcd(a,b);
        i1=a/b;
        a=a%b;
        if(g){
            a/=g;
            b/=g;
        }
        if(i1==0)
        {
            if(flag)
                cout<<"(-";
            cout<<a<<'/'<<b;
            if(flag)
                cout<<')';
        }
        else if(a==0){
            if(flag)
                cout<<"(-";
            cout<<i1;
            if(flag)
                cout<<')';
        }
        else {
            if(flag)
                cout<<"(-";
            cout<<i1<<' '<<a<<'/'<<b;
            if(flag)
                cout<<')';
        }
    }
}

int main(int argc, const char * argv[]) {
    long long a,b,c,d;
    scanf("%lld/%lld %lld/%lld",&a,&b,&c,&d);
    output(a,b);
    cout<<" + ";
    output(c,d);
    cout<<" = ";
    output(a*d+b*c,b*d);
    cout<<endl;
    output(a,b);
    cout<<" - ";
    output(c,d);
    cout<<" = ";
    output(a*d-b*c,b*d);
    cout<<endl;
    output(a,b);
    cout<<" * ";
    output(c,d);
    cout<<" = ";
    output(a*c,b*d);
    cout<<endl;
    output(a,b);
    cout<<" / ";
    output(c,d);
    cout<<" = ";
    if(c==0)
        cout<<"Inf";
    else {
        if((a<0&&c<0)||(a>0&&c<0)){
            a=-a;
            c=-c;
        }
        output(a*d,b*c);
    }
    cout<<endl;
    return 0;
}
