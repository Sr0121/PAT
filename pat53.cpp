//
//  main.cpp
//  pat53
//
//  Created by Sr on 2017/4/5.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> ans;
vector<vector<int> > output;
int sum;

struct node{
    int element;
    vector<int> subtree;
};

void dfs(struct node *info,int n,int w){
    sum+=info[n].element;
    if(sum>=w&&info[n].subtree.size()!=0){
        sum-=info[n].element;
        return;
    }
    ans.push_back(info[n].element);
    if(sum==w){
        output.push_back(ans);
        ans.pop_back();
        sum-=info[n].element;
        return;
    }
    for(int i=0;i<info[n].subtree.size();i++){
        dfs(info,info[n].subtree[i],w);
    }
    sum-=info[n].element;
    ans.pop_back();
    return;
}

bool cmp (vector<int> i,vector<int> j) {
    return (i>j);
}

int main(int argc, const char * argv[]) {
    int m,n,w,time,son,node_num;
    struct node *info;
    scanf("%d%d%d",&m,&n,&w);
    info=new struct node [m];
    for(int i=0;i<m;i++)
        scanf("%d",&info[i].element);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&node_num,&time);
        for(int j=0;j<time;j++)
        {
            scanf("%d",&son);
            info[node_num].subtree.push_back(son);
        }
    }
    dfs(info,0,w);
    sort(output.begin(),output.end(),cmp);
    for(int i=0;i<output.size();i++){
        printf("%d",output[i][0]);
        for(int j=1;j<output[i].size();j++)
            printf(" %d",output[i][j]);
        printf("\n");
    }
    return 0;
}
