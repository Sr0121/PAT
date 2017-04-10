//
//  main.cpp
//  pat57
//
//  Created by Sr on 2017/4/6.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>//类哈希
using namespace std;
int bucket[501][200];
int cnt[501];

int bucket_sort(int size){
    int count_num=0;
    int i;
    for(i=0;i<501;i++){
        count_num+=cnt[i];
        if(count_num>=(size+2)/2)
            break;
    }
    count_num-=cnt[i];
    for (int j = 0; j <= 200; j++) {
        count_num+=bucket[i][j];
        if(count_num>=(size+2)/2)
            return i*200+j;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    int stack[100001];
    int size=-1;
    int num,mid;
    char input[11];
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%s",input);
        if(input[1]=='o'){
            if(size<0)
                printf("Invalid\n");
            else
            {
                bucket[stack[size]/200][stack[size]%200]--;
                cnt[stack[size]/200]--;
                printf("%d\n",stack[size--]);
            }
        }
        else if(input[1]=='e'){
            if(size<0)
                printf("Invalid\n");
            else
            {
                mid=bucket_sort(size);
                printf("%d\n",mid);
            }
        }
        else if(input[1]=='u'){
            scanf("%d",&stack[++size]);
            bucket[stack[size]/200][stack[size]%200]++;
            cnt[stack[size]/200]++;
        }
    }
    return 0;
}
