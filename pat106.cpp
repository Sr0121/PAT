//
//  main.cpp
//  pat106
//
//  Created by Sr on 2017/4/30.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int> >chain;

void dfs(int cur,int level,int &min,int &count)
{
    if(chain[cur].size()==0)
    {
        if(level<min)
        {
            min=level;
            count=1;
        }
        else if(level==min)
        {
            count++;
        }
        return;
    }
    for(int i=0;i<chain[cur].size();i++)
    {
        dfs(chain[cur][i],level+1,min,count);
    }
}

int main()
{
    int n;
    double p,r;
    int min=100000;
    int count=0;
    cin>>n>>p>>r;
    chain.resize(n);
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int rt;
            cin>>rt;
            chain[i].push_back(rt);
        }
    }
    dfs(0,0,min,count);
    double res=p*pow((1+r/100),min);
    printf("%.4lf %d\n",res,count);
}
