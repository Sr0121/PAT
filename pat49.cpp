//
//  main.cpp
//  pat49
//
//  Created by Sr on 2017/4/3.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int m,i=1,sum=0;
    scanf("%d",&m);
    while(i<=m){
        if(m/i%10==1){
            sum+=i*(m/i/10)+m%i+1;
        }
        else if(m/i%10==0){
            sum+=i*(m/i/10);
        }
        else{
            sum+=i*(m/i/10+1);
        }
        i*=10;
    }
    printf("%d\n",sum);
    return 0;
}
