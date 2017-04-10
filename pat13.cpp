//
//  main.cpp
//  pat13
//
//  Created by Sr on 2017/3/6.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
using namespace std;

int all_one(int visit[],int N,int v)
{
    for(int i=1;i<=N;i++)
        if(i!=v&&visit[i]==0)
            return i;
    return -1;
}

void check(int N,int i,int map[1000][1000],int v)
{
    int cnt=0,rear=0,new_note,test=0,t;
    int visit[1000]={0};
    int queue[N];
    t=all_one(visit,N,v);
    while(t!=-1)
    {
        new_note=t;
        queue[rear++]=new_note;
        visit[new_note]=1;
        while(test<rear)
        {
            for(int i=1;i<=N;i++)
                if(i!=v&&map[queue[test]][i]&&visit[i]==0)
                {
                    queue[rear++]=i;
                    visit[i]=1;
                }
            test++;
        }
        t=all_one(visit,N,v);
        if(t!=-1)
            cnt++;
    }
    cout<<cnt<<endl;
}

int main(int argc, const char * argv[]) {
    int N,M,K;
    int v,w;
    int map[1000][1000]={0};
    cin>>N>>M>>K;
    for(int i=0;i<M;i++)
    {
        cin>>v>>w;
        map[v][w]=map[w][v]=1;
    }
    for(int i=0;i<K;i++)
    {
        cin>>v;
        check(N,i,map,v);
    }
    return 0;
}
