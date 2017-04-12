//
//  main.cpp
//  pat75
//
//  Created by Sr on 2017/4/12.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int *total;
int all_class;

struct info{
    int id;
    int score[6];
    int list;
    int sum;
    int question;
    
    void set_score(){
        list=1;
        for(int i=1;i<=all_class;i++)
            score[i]=-2;
    }
    
    void set_sum(){
        sum=0;
        for(int i=1;i<=all_class;i++)
        {
            if(score[i]>=0)
                list=0;
            if(score[i]>=0)
                sum+=score[i];
            if(score[i]==total[i-1])
                question++;
        }
        
    }
    
    bool operator <(const struct info &x)const{
        if(list!=x.list)
            return list<x.list;
        if(sum!=x.sum)
            return sum>x.sum;
        else if(question!=x.question)
            return question>x.question;
        else return id<x.id;
    }
};

int main(int argc, const char * argv[]) {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    all_class=m;
    total=new int[m];
    for(int i=0;i<m;i++)
        scanf("%d",&total[i]);
    struct info *new_info;
    new_info=new struct info[n];
    for(int i=0;i<n;i++)
    {
        new_info[i].id=i+1;
        new_info[i].set_score();
    }
    for(int i=0;i<k;i++){
        int id,num_class,score;
        scanf("%d%d%d",&id,&num_class,&score);
        if(new_info[id-1].score[num_class]<score)
            new_info[id-1].score[num_class]=score;
    }
    for(int i=0;i<n;i++)
        new_info[i].set_sum();
    
    sort(new_info,new_info+n);
    
    int count_num=0,last_score=-1;
    for(int i=0;i<n&&new_info[i].list==0;i++){
        if(new_info[i].sum!=last_score)
        {
            count_num=i;
            last_score=new_info[i].sum;
        }
        printf("%d %05d %d",count_num+1,new_info[i].id,new_info[i].sum);
        for(int j=1;j<=all_class;j++)
        {
            if(new_info[i].score[j]>=0)
                printf(" %d",new_info[i].score[j]);
            if(new_info[i].score[j]==-1)
                printf(" 0");
            if(new_info[i].score[j]==-2)
                printf(" -");
        }
        printf("\n");
    }
    return 0;
}
