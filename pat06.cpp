//
//  main.cpp
//  pat06
//
//  Created by Sr on 2017/3/5.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct ID_record *info;

int earliest=240001,latest=-1;
string ear_ID,lat_ID;

struct ID_record {
    string ID;
    int in_time;
    int out_time;
    info next;
};

void check(info head)
{
    info current;
    current=head;
    while(current!=NULL)
    {
        if(earliest>current->in_time)
        {
            earliest=current->in_time;
            ear_ID=current->ID;
        }
        if(latest<current->out_time)
        {
            latest=current->out_time;
            lat_ID=current->ID;
        }
        current=current->next;
    }
}

int main(int argc, const char * argv[]) {
    int n,i,a,b,c;
    info head=NULL,current,last;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        current=new ID_record;
        cin>>current->ID;
        scanf("%d:%d:%d",&a,&b,&c);
        current->in_time=10000*a+100*b+c;
        scanf("%d:%d:%d",&a,&b,&c);
        current->out_time=10000*a+100*b+c;
        current->next=NULL;
        if(i==1)
            head=current;
        else
            last->next=current;
        last=current;
    }
    check(head);
    cout<<ear_ID<<' '<<lat_ID;
    return 0;
}
