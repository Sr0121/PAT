//
//  main.cpp
//  pat59
//
//  Created by Sr on 2017/4/7.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
int prime=2;
int next_prime(int p);
bool is_prime(int n);

bool is_prime(int n){
    int max=sqrt(n);
    for(int i=2;i<=max;i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int next_prime(int p){
    while(1){
        if(is_prime(++p))
            return p;
    }
}

int main(int argc, const char * argv[]) {
    int s,count;
    scanf("%d",&s);
    printf("%d=",s);
    if(s==1)
    {
        printf("1\n");
        return 0;
    }
    while(s!=1){
        count=0;
        while(s%prime==0){
            s=s/prime;
            count++;
        }
        if(count>0)
        {
            if(count==1)
                printf("%d",prime);
            if(count>1)
                printf("%d^%d",prime,count);
            if(s>1)
                printf("*");
        }
        prime=next_prime(prime);
    }
    printf("\n");
    return 0;
}
