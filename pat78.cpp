//
//  main.cpp
//  pat78
//
//  Created by Sr on 2017/4/12.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int min_prime(int n){
    if(n==1)
        return 2;
    for(int i=n;;i++)
    {
        int flag=0;
        for(int j=2;j<=sqrt(i);j++)
            if(i%j==0)
            {
                flag=1;
                break;
            }
        if(flag==0)
            return i;
    }
}

int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    n=min_prime(n);
    int *line;
    line=new int[n];
    memset(line,0,sizeof(line[0])*n);
    for(int i=0;i<m;i++){
        int input,flag=0;
        scanf("%d",&input);
        for(int j=0;j<n;j++){
            if(line[(input+j*j)%n]==0)
            {
                flag=1;
                line[(input+j*j)%n]=input;
                cout<<(input+j*j)%n;
                if(i<m-1)
                    cout<<" ";
                break;
            }
        }
        if(flag==0)
        {
            cout<<'-';
            if(i<m-1)
                cout<<" ";
        }
    }
    cout<<endl;
    return 0;
}
