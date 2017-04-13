//
//  main.cpp
//  pat79
//
//  Created by Sr on 2017/4/13.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    double p,r;
    cin>>n>>p>>r;
    vector<vector<int> > chain(n);
    for(int i=0;i<n;i++)
    {
        int s;
        scanf("%d",&s);
        chain[i].push_back(s);
        if(s>0)
        for(int j=0;j<s;j++){
            int k;
            scanf("%d",&k);
            chain[i].push_back(k);
        }
        else
        {
            int k;
            scanf("%d",&k);
            chain[i].push_back(k);
        }
    }
    int *q;
    q=new int[n];
    q[0]=0;
    int rear=0,level=0,next_level=0;
    double sum=0;
    for(int i=0;i<n;i++){
        if(i>level)
        {
            p=(1+r/100)*p;
            level=next_level;
        }
        if(chain[q[i]][0]==0){
            sum+=(double)chain[q[i]][1]*p;
        }
        else{
            for(int j=1;j<=chain[q[i]][0];j++)
            {
                q[++rear]=chain[q[i]][j];
            }
            next_level=rear;
        }
    }
    printf("%.1lf\n",sum);
    return 0;
}
