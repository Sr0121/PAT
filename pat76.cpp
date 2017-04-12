//
//  main.cpp
//  pat76
//
//  Created by Sr on 2017/4/12.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
int cnt=0;
int level=1;
int *visit;
int m,n;

int check_finish(){//判断是否已经全部都已转发了，不加则超时
    for(int i=1;i<=m;i++)
        if(visit[i]==0)
            return 1;
    return 0;
}

void bfs(int q,vector<int> *info,int n){
    for(int i=0;i<info[q].size();i++){
        if(visit[info[q][i]]==0){
            visit[info[q][i]]=1;
            cnt++;
        }
        level++;
        if(level<=n)
            bfs(info[q][i],info,n);
        level--;
        if(check_finish()==0)
            return;
    }
}

int main(int argc, const char * argv[]) {
    cin>>m>>n;
    vector<int >info[m+1];
    for(int i=0;i<m;i++){
        int num;
        cin>>num;
        for(int j=0;j<num;j++)
        {
            int f;
            scanf("%d",&f);
            info[f].push_back(i+1);
        }
    }
    int query;
    visit=new int[m+1];
    memset(visit,0,(m+1)*sizeof(visit[0]));
    scanf("%d",&query);
    for(int i=0;i<query;i++){
        int find;
        scanf("%d",&find);
        visit[find]=1;
        bfs(find,info,n);
        printf("%d\n",cnt);
        memset(visit,0,(m+1)*sizeof(visit[0]));
        cnt=0;
    }
    return 0;
}
