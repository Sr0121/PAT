//
//  main.cpp
//  pat65
//
//  Created by Sr on 2017/4/8.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    long long a,b,c,sum;
    bool result;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld%lld%lld",&a,&b,&c);
        sum=a+b;
        if(a>0&&b>0&&sum<=0)
            result=true;
        else if(a<0&&b<0&&sum>=0)
            result=false;
        else if(sum>c)
            result=true;
        else
            result=false;
        cout<<"Case #"<<i+1<<": ";
        if(result)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
        
    return 0;
}
