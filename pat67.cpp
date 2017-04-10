//
//  main.cpp
//  pat67
//
//  Created by Sr on 2017/4/8.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,s[100001]={0};
    int mark[100001]={0};
    int count=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&s[i]);
        if(s[i]==i||s[i]==0)
            mark[i]=1;
    }
    for(int i=0;i<n;i++){
        if(mark[i]==1)
            continue;
        int tmp=s[i];
        mark[i]=1;
        int local_count=0;
        while(1){//数圈圈
            mark[tmp]=1;
            if(tmp==0)
                break;
            else if(tmp==i)
            {
                local_count+=2;
                break;
            }
            local_count++;
            tmp=s[tmp];
        }
        count+=local_count;
    }
    printf("%d\n",count);
    return 0;
}
