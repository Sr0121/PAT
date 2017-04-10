//
//  main.cpp
//  pat33
//
//  Created by Sr on 2017/3/18.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int C,D,D_avg,N;
struct gas_station *s;

struct gas_station{
    float price;
    int distance;
    bool operator < (const gas_station &x)const{
        if(distance==x.distance)
            return price<x.price;
        else return distance<x.distance;
    }
};

float check()
{
    float max_dis,current_dis=0,current_c=0;
    int i=0,j=0,last=0;
    float price;
    max_dis=C*D_avg;
    if(s[i].distance>0)
        return 0;
    while(current_dis<D)
    {
        current_c-=(float)(s[i].distance-s[last].distance)/D_avg;
        float min_price=100000;
        int min_index=-1,less=-1;
        for(j=i+1;s[i].distance+max_dis>=s[j].distance&&j<N;j++)
            if(s[j].price<min_price)
            {
                if(less==-1&&s[j].price<s[i].price)
                    less=j;
                min_index=j;
                min_price=s[j].price;
            }
        if(min_index==-1&&((s[i].distance+max_dis)>=D))
        {
            price+=(float)(D-current_dis)/D_avg*s[i].price;
            current_dis=D;
        }
        else if(min_index==-1)
            return -(current_dis+=max_dis);
        if(less==-1)
        {
            if((s[i].distance+max_dis)>=D)
            {
                price+=(float)(D-current_dis)/D_avg*s[i].price;
                current_dis=D;
            }
            else
            {
                current_dis+=(C-current_c)*D_avg;
                price+=(float)(C-current_c)*s[i].price;
                current_c=C;
            }
        }
        else
        {
            if(current_c<s[less].distance){
                current_c+=(float)(s[less].distance-current_dis)/D_avg;
                price+=(float)(s[less].distance-current_dis)/D_avg*s[i].price;
                current_dis=s[less].distance;
            }
        }
        last=i;
        if(less!=-1)
            i=less;
        else
            i=min_index;
    }
    return price;
}

int main(int argc, const char * argv[]) {
    float output;
    cin>>C>>D>>D_avg>>N;
    s=new struct gas_station[N];
    for(int i=0;i<N;i++)
        cin>>s[i].price>>s[i].distance;
    sort(s,s+N);
    output=check();
    if(output>0)
        printf("%.2f",output);
    else
    {
        if(output==-0)//output为0时，直接给负号会变成-0 = =
        printf("The maximum travel distance = 0.00");
        else
        printf("The maximum travel distance = %.2f",float(-output));
    }
    return 0;
}
