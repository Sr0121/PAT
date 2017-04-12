//
//  main.cpp
//  pat74
//
//  Created by Sr on 2017/4/10.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
    int next;
    int element;
};


int main(int argc, const char * argv[]) {
    struct node list[100001];
    int start,num_input,l;
    scanf("%d%d%d",&start,&num_input,&l);
    for(int i=0;i<num_input;i++)
    {
        int s1;
        scanf("%d",&s1);
        scanf("%d%d",&list[s1].element,&list[s1].next);
    }
    
    vector<int> add,reverse;
    int tmp=start;
    while(tmp!=-1){
        add.push_back(tmp);
        tmp=list[tmp].next;
    }
    int cur=0;
    int len=(int)add.size();
    for(int i=0;i*l<len;i++){
        cur=i*l;
        if(cur+l>len)
            break;
        else{
            for(int j=l-1;j>=0;j--){
                reverse.push_back(add[cur+j]);
            }
            cur=cur+l;
        }
    }
    for(;cur<len;cur++){
        reverse.push_back(add[cur]);
    }
    for(int i=0;i<reverse.size()-1;i++){
        printf("%05d %d %05d\n",reverse[i],list[reverse[i]].element,reverse[i+1]);
    }
    printf("%05d %d -1\n",reverse[reverse.size()-1],list[reverse[reverse.size()-1]].element);
    return 0;
}
