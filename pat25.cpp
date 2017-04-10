//
//  main.cpp
//  pat25
//
//  Created by Sr on 2017/3/14.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct info{
    string id;
    int score;
    int place;
    int local_rank;
    int final_rank;
    bool operator < (const info &x) const
    {
        if(score==x.score)
            return id<x.id;
        else return score>x.score;
    }
};


int main(int argc, const char * argv[]) {
    int time,num=0;
    struct info info[30001];
    cin>>time;
    for(int i=1;i<=time;i++)
    {
        int local_j;
        cin>>local_j;
        int local_num=num;
        for(int j=1;j<=local_j;j++)
        {
            cin>>info[num].id>>info[num].score;
            info[num].place=i;
            num++;
        }
        sort(&info[local_num],&info[local_num]+local_j);
        for(int j=0;j<local_j;j++)
        {
            if(j>0&&info[j+local_num].score==info[j+local_num-1].score)
                info[j+local_num].local_rank=info[j+local_num-1].local_rank;
            else
                info[j+local_num].local_rank=j+1;
        }
    }
    sort(&info[0],&info[0]+num);
    cout<<num<<endl;
    for(int j=0;j<num;j++)
    {
        if(j>0&&info[j].score==info[j-1].score)
            info[j].final_rank=info[j-1].final_rank;
        else
            info[j].final_rank=j+1;
    }
    for(int i=0;i<num;i++)
    {
        cout<<info[i].id<<" "<<info[i].final_rank<<" "<<info[i].place<<" "<<info[i].local_rank<<endl;
    }
    return 0;
}
