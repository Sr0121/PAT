//
//  main.cpp
//  pat83
//
//  Created by Sr on 2017/4/14.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

struct info{
    string name;
    string ID;
    int grade;
    bool operator < (const struct info &x) const{
        return grade>x.grade;
    }
};

int main(int argc, const char * argv[]) {
    struct info *info;
    int n,flag=0;
    cin>>n;
    info=new struct info[n];
    for(int i=0;i<n;i++){
        cin>>info[i].name>>info[i].ID>>info[i].grade;
    }
    int grade1,grade2;
    cin>>grade1>>grade2;
    sort(info,info+n);
    for(int i=0;i<n;i++){
        if(info[i].grade<=grade2){
            if(info[i].grade>=grade1)
            {
                cout<<info[i].name<<" "<<info[i].ID<<endl;
                flag=1;
            }
            else break;
        }
    }
    if(flag==0)
        cout<<"NONE"<<endl;
    return 0;
}
