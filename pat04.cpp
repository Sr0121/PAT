//
//  main.cpp
//  pat04
//
//  Created by Sr on 2017/4/13.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int m,n;
    cin>>m>>n;
    vector<vector<int> > chain(m+1);
    for(int i=0;i<n;i++)
    {
        int s,t;
        scanf("%d%d",&s,&t);
        for(int j=0;j<t;j++){
            int k;
            scanf("%d",&k);
            chain[s].push_back(k);
        }
       
    }
    int *q;
    q=new int[m];
    q[0]=1;
    int rear=0,level=0,next_level=0;
    int sum=0;
    for(int i=0;i<m;i++){
        if(i>level)
        {
            printf("%d ",sum);
            level=next_level;
            sum=0;
        }
        if(chain[q[i]].size()==0){
            sum++;
        }
        else{
            for(int j=0;j<chain[q[i]].size();j++)
            {
                q[++rear]=chain[q[i]][j];
            }
            next_level=rear;
        }
    }
    printf("%d\n",sum);
    return 0;
}
