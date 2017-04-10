//
//  main.cpp
//  pat30
//
//  Created by Sr on 2017/3/17.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int path [501][501];
int cost [501][501];
int dist[501];
int total_cost[501];
int N,M,S,D;
string path_record[501];

string num2str(int i)
{
    stringstream ss;
    ss<<i;
    return ss.str();
}

int find_min(int *visit)
{
    int min=100000,min_index=100000;
    for(int i=0;i<N;i++)
        if(visit[i]==0&&dist[i]<min&&dist[i]>0)
        {
            min=dist[i];
            min_index=i;
        }
    return min_index;
}

void check()
{
    int visit[501]={0};
    int j;
    visit[S]=1;
    dist[S]=0;
    j=S;
    path_record[j]+=num2str(S);
    while(1)
    {
        for(int i=0;i<N;i++)
            if(path[j][i]&&(dist[j]+path[j][i]<dist[i]||dist[i]==0))
            {
                dist[i]=dist[j]+path[j][i];
                total_cost[i]=total_cost[j]+cost[j][i];
                path_record[i]="";
                path_record[i].append(path_record[j]);
                path_record[i]+=' '+num2str(i);
            }
            else if(dist[j]+path[j][i]==dist[i]&&total_cost[i]>total_cost[j]+cost[j][i])
            {
                total_cost[i]=total_cost[j]+cost[j][i];
                path_record[i]="";
                path_record[i].append(path_record[j]);
                path_record[i]+=' '+num2str(i);
            }
        j=find_min(visit);
        if(j==100000)
            break;
        visit[j]=1;
    }
}

int main(int argc, const char * argv[]) {
    int c1,c2,distance,money;
    cin>>N>>M>>S>>D;
    for(int i=0;i<M;i++)
    {
        cin>>c1>>c2>>distance>>money;
        path[c2][c1]=path[c1][c2]=distance;
        cost[c2][c1]=cost[c1][c2]=money;
    }
    check();
    cout<<path_record[D]<<' '<<dist[D]<<' '<<total_cost[D];
    return 0;
}
