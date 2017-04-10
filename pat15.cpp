//
//  main.cpp
//  pat15
//
//  Created by Sr on 2017/3/8.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

int reverse(int key, int radix) {
    int rever = 0;
    while (key) {
        rever = rever * radix + key % radix;
        key /= radix;
    }
    return rever;
}

int is_prime(int num)
{
    if(num<=1)
        return 1;
    int divisor=2;
    while(divisor<=sqrt(num))
    {
        if(num%divisor==0)
            return 1;
        divisor++;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int flag=0;
    int num;
    cin>>num;
    while(num>0)
    {
        int radix;
        cin>>radix;
        flag=is_prime(num);
        if(!flag)
        {
            num=reverse(num, radix);
            flag=is_prime(num);
        }
        if(!flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        flag=0;
        num=0;
        cin>>num;
    }
    return 0;
}
