//
//  main.cpp
//  pat08
//
//  Created by Sr on 2017/3/5.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include<iostream>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int now=0,next,total=0;
    while(N--){
        cin>>next;
        if(next>now){
            total+=(next-now)*6+5;
        }
        else
            total+=(now-next)*4+5;
        now=next;
    }
    cout<<total;
    return 0;
}
