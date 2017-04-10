//
//  main.cpp
//  pat51
//
//  Created by Sr on 2017/4/4.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int m,n,k,num,size=0,flag;
    int *s;
    scanf("%d%d%d",&m,&n,&k);
    s=new int [m+1];
    for(int i=0;i<k;i++)
    {
        flag=0;
        size=0;
        int input=1;
        for(int j=1;j<=n;j++){
            scanf("%d",&num);
            if(flag!=1){
                while(s[size]!=num){
                    if(size==m||input>n)
                    {
                        flag=1;
                        break;
                    }
                    if(input<=n){
                        s[++size]=input;
                        input++;
                    }
                }
                if(s[size]==num)
                {
                    size--;
                }
            }
        }
        if(flag==1)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
