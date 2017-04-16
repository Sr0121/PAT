//
//  main.cpp
//  pat101
//
//  Created by Sr on 2017/4/16.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    int *s;
    int s1[100001]={0};
    vector<int> out;
    s=new int [n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    int max=s[0]-1,min=s[n-1]+1;
    for(int i=n-1;i>=0;i--){
        if(s[i]<min){
            s1[i]=1;
            min=s[i];
        }
    }
    for(int i=0;i<n;i++){
        if(s[i]>max){
            if(s1[i]==1){
                out.push_back(s[i]);
            }
            max=s[i];
        }
    }
    cout<<out.size()<<endl;
    for(int i=0;i<out.size();i++){
        if(i>0)
            cout<<' ';
        cout<<out[i];
    }
    cout<<endl;
    return 0;
}
