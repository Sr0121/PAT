//
//  main.cpp
//  pat63
//
//  Created by Sr on 2017/4/8.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,k,q,s1,s2;
    double ans;
    int input;
    map<int,int> check;
    scanf("%d",&n);
    vector<vector<int> > num(n);
    for(int i=0;i<n;i++){
        check.clear();
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            scanf("%d",&input);
            if(check.find(input)==check.end()){
                check[input]=1;
                num[i].push_back(input);
            }
        }
        sort(num[i].begin(),num[i].end());
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int c1=0,c2=0;
        int nc=0,nt=0;
        scanf("%d%d",&s1,&s2);
        s1--;
        s2--;
       
        while(c1<num[s1].size()&&c2<num[s2].size()){
            if(num[s1][c1]==num[s2][c2]){
                nt++;
                nc++;
                c1++;
                c2++;
            }
            else if(num[s1][c1]>num[s2][c2]){
                nt++;
                c2++;
            }
            else if(num[s1][c1]<num[s2][c2]){
                nt++;
                c1++;
            }
        }
        if(c1<num[s1].size())
            nt+=num[s1].size()-c1;
        if(c2<num[s2].size())
            nt+=num[s2].size()-c2;
        ans=(double)nc/nt;
        ans*=100;
        printf("%0.1f%%\n",ans);
    }
    return 0;
}
