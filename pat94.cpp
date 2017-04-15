//
//  main.cpp
//  pat94
//
//  Created by Sr on 2017/4/15.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,m;
    cin>>n>>m;
    vector<vector<int> > s(n+1);
    for(int i=0;i<m;i++){
        int node,t;
        cin>>node>>t;
        for(int j=0;j<t;j++){
            int k;
            cin>>k;
            s[node].push_back(k);
        }
    }
    int max=1,max_level=1;
    int level_index=0,next_level_index=0;
    int level=1,rear=0;;
    int *t;
    t=new int[n];
    t[0]=1;
    for(int i=0;i<n;i++){
        if(i>level_index){
            level++;
            int tmp=next_level_index-level_index;
            if(tmp>max){
                max=tmp;
                max_level=level;
            }
            level_index=next_level_index;
        }
        for(int j=0;j<s[t[i]].size();j++){
            t[++rear]=s[t[i]][j];
            next_level_index=rear;
        }
    }
    cout<<max<<' '<<max_level<<endl;
    return 0;
}
