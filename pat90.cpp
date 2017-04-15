//
//  main.cpp
//  pat90
//
//  Created by Sr on 2017/4/15.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,start=-1;
    double p,r;
    cin>>n>>p>>r;
    vector<vector<int> > chain(n);
    for(int i=0;i<n;i++)
    {
        int s;
        scanf("%d",&s);
        if(s==-1)
            start=i;
        else
            chain[s].push_back(i);
    }
    int *q;
    q=new int[n];
    q[0]=start;
    int rear=0,level=0,next_level=0;
    int sum=0;
    if(n==1)
    {
        printf("%.2lf 1\n",p);
        return 0;
    }
    for(int i=0;i<n;i++){
        if(i>level)
        {
            p=(1+r/100)*p;
            sum=next_level-level;
            level=next_level;
        }
        for(int j=0;j<chain[q[i]].size();j++)
        {
            q[++rear]=chain[q[i]][j];
        }
        next_level=rear;
    }
    printf("%.2lf %d\n",p,sum);
    return 0;
}
