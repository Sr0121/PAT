//
//  main.cpp
//  pat62
//
//  Created by Sr on 2017/4/7.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct info{
    char id[9];
    int Virtue_Grade;
    int Talent_Grade;
    int type;

    int set_info(int L,int H){
        scanf("%s %d %d",id,&Virtue_Grade,&Talent_Grade);
        if(Talent_Grade<L||Virtue_Grade<L)
            type=4;
        else if(Virtue_Grade>=H&&Talent_Grade>=H)
            type=0;
        else if(Talent_Grade<H&&Virtue_Grade>=H)
            type=1;
        else if(Talent_Grade<H&&Virtue_Grade<=H&&Talent_Grade<=Virtue_Grade)
            type=2;
        else if(Talent_Grade>=L&&Virtue_Grade>=L)
            type=3;
        else
            type=4;
        if(type!=4)
            return 1;
        else
            return 0;
    }
    
    bool operator < (const struct info &x) const{
        if(type!=x.type)
            return type<x.type;
        else if(Virtue_Grade+Talent_Grade!=x.Virtue_Grade+x.Talent_Grade)
            return Virtue_Grade+Talent_Grade>x.Virtue_Grade+x.Talent_Grade;
        else if(Virtue_Grade!=x.Virtue_Grade)
            return Virtue_Grade>x.Virtue_Grade;
        else
            return strcmp(id,x.id)<0;
    }
};

int main(int argc, const char * argv[]) {
    int num_of_people,L,H,count=0;
    struct info *node;
    scanf("%d%d%d",&num_of_people,&L,&H);
    node=new struct info[num_of_people];
    for(int i=0;i<num_of_people;i++)
        count+=node[i].set_info(L, H);
    sort(node,node+num_of_people);
    printf("%d\n",count);
    for(int i=0;i<count;i++){
        printf("%s %d %d\n",node[i].id,node[i].Virtue_Grade,node[i].Talent_Grade);
    }
    return 0;
}
