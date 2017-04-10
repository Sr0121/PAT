//
//  main.cpp
//  pat36
//
//  Created by Sr on 2017/3/19.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct info{
    string name;
    string gender;
    string id;
    int grade;
    bool operator < (const info &x)const
    {
        if(gender==x.gender)
            return grade>x.grade;
        else return gender<x.gender;
    }
};

int main(int argc, const char * argv[]) {
    int n,s1=-1,s2=-1;
    struct info *info_stu;
    cin>>n;
    info_stu=new struct info[n];
    for(int i=0;i<n;i++)
        cin>>info_stu[i].name>>info_stu[i].gender>>info_stu[i].id>>info_stu[i].grade;
    sort(info_stu,info_stu+n);
    if(info_stu[0].gender[0]=='F')
    {
        cout<<info_stu[0].name<<' '<<info_stu[0].id;
        s1=info_stu[0].grade;
    }
    else cout<<"Absent";
    cout<<endl;
    if(info_stu[n-1].gender[0]=='M')
    {
        cout<<info_stu[n-1].name<<' '<<info_stu[n-1].id;
        s2=info_stu[n-1].grade;
    }
    else cout<<"Absent";
    cout<<endl;
    if(s1==-1||s2==-1)
        cout<<"NA";
    else cout<<s1-s2;
    cout<<endl;
    return 0;
}
