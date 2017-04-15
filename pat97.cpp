//
//  main.cpp
//  pat97
//
//  Created by Sr on 2017/4/15.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct info{
    int n;
    int next;
};

int main(int argc, const char * argv[]) {
    int start,n;
    cin>>start>>n;
    map<int,int> dic;
    vector<int> s1,s2;
    struct info s[100001];
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        s[a].n=b;
        s[a].next=c;
    }
    while(start!=-1){
        int tmp=s[start].n;
        if(tmp<0)
            tmp=-tmp;
        if(dic.find(tmp)==dic.end()){
            dic[tmp]=1;
            s1.push_back(start);
        }
        else{
            s2.push_back(start);
        }
        start=s[start].next;
    }
    for(int i=0;i<s1.size();i++)
    {
        if(i<s1.size()-1)
            printf("%05d %d %05d\n",s1[i],s[s1[i]].n,s1[i+1]);
        else
            printf("%05d %d -1\n",s1[i],s[s1[i]].n);
    }
    for(int i=0;i<s2.size();i++)
    {
        if(i<s2.size()-1)
            printf("%05d %d %05d\n",s2[i],s[s2[i]].n,s2[i+1]);
        else
            printf("%05d %d -1\n",s2[i],s[s2[i]].n);
    }
    return 0;
}
