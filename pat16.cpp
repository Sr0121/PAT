//
//  main.cpp
//  pat16
//
//  Created by Sr on 2017/3/8.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


struct info{
    string id,time,state;
    bool operator < (const info &x) const
    {
        if (id==x.id)
            return time<x.time;
        else return id<x.id;
    }
}node[1001];


int calcu_money(string t1,string t2,int *charge)
{
    int time[25];
    int t1_h=(t1[6]-'0')*10+t1[7]-'0';
    int t1_m=(t1[9]-'0')*10+t1[10]-'0';
    int t2_h=(t2[6]-'0')*10+t2[7]-'0';
    int t2_m=(t2[9]-'0')*10+t2[10]-'0';
    int t1_d=(t1[3]-'0')*10+t1[4]-'0';
    int t2_d=(t2[3]-'0')*10+t2[4]-'0';
    int end_time=t2_d*1440+t2_h*60+t2_m;
    int begin_time=t1_d*1440+t1_h*60+t1_m;
    int total_money=0;
    charge[24]=0;
    charge[24]=end_time-begin_time;
    for(int i=0;i<25;i++)
        time[i]=60;
    if(t1_h<=t2_h)
    {
        time[t1_h]=60-t1_m;
        time[t2_h]=t2_m;
        if(t1_h==t2_h)
            time[t1_h]=t2_m-t1_m;
        for(int i=t1_h;i<=t2_h;i++)
            total_money+=time[i]*charge[i];
    }
    else{
        time[t2_h]=60-t2_m;
        time[t1_h]=t1_m;
        for(int i=t2_h;i<=t1_h;i++)
            total_money+=time[i]*charge[i];
        total_money=-total_money;
    }
    int extra_single_day=0;
    for(int i=0;i<24;i++)
        extra_single_day+=60*charge[i];
    total_money+=extra_single_day*(t2_d-t1_d);
    return total_money;
}


int main(int argc, const char * argv[]) {
    int charge[25]={0};
    for(int i=0;i<24;i++)
        cin>>charge[i];
    int input;
    int total_money=0,current_money;
    cin>>input;
    for(int i=0;i<input;i++)
        cin>>node[i].id>>node[i].time>>node[i].state;
    sort(node,node+input);
    string month(node[0].time.begin(), node[0].time.begin() + 2);
    string name="";
    for(int i=1;i<input;i++)
    {
        if(node[i-1].state=="on-line"&&node[i].state=="off-line"&&node[i].id==node[i-1].id)
        {
            if (node[i].id != name) {
                if (name != "")
                    printf("Total amount: $%d.%02d\n", total_money / 100, total_money % 100);
                total_money = 0;
                name = node[i].id;
                cout << name << " " << month << endl;
            }
            current_money=calcu_money(node[i-1].time,node[i].time,charge);
            total_money+=current_money;
            string on_line_time(node[i-1].time.begin()+3,node[i-1].time.end());
            string off_line_time(node[i].time.begin()+3,node[i].time.end());
            cout<<on_line_time<<' '<<off_line_time<<' '<<charge[24]<<" $"<<current_money/100;
            printf(".%02d\n",current_money%100);
        }
    }
    printf("Total amount: $%d.%02d\n", total_money / 100, total_money % 100);
    return 0;
}
