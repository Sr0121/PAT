//
//  main.cpp
//  pat68
//
//  Created by Sr on 2017/4/9.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int &a,int&b)
{
    return a>b;
}

int main(int argc, const char * argv[]) {
    int n,m;
    int *input;
    scanf("%d%d",&n,&m);
    vector<vector<int> > resolution(m+1);
    input=new int[n];
    for(int i=0;i<n;i++)
        scanf("%d",&input[i]);
    sort(input,input+n,cmp);
    resolution[0].push_back(0);
    for(int i=0;i<n;i++){
        for(int j=m-input[i];j>=0;j--){
            if(!resolution[j].empty())
            {
                vector<int> s_tmp(resolution[j]);
                resolution[j+input[i]]=s_tmp;
                resolution[j+input[i]].push_back(input[i]);
            }
        }
    }
    if(resolution[m].empty())
        printf("No Solution");
    else{
        printf("%d",resolution[m][resolution[m].size()-1]);
        for(int i=resolution[m].size()-2;i>0;i--)
            printf(" %d",resolution[m][i]);
    }
    printf("\n");
    return 0;
}
