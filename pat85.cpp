//
//  main.cpp
//  pat85
//
//  Created by Sr on 2017/4/15.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,p;
    long long *s;
    int max=0;
    cin>>n>>p;
    s=new long long[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    sort(s,s+n);
    int l=0,r=0;
    while(l<n){
        while(r<n&&s[r]<=(long long)p*s[l]){
            r++;
        }
        if(max<r-l)
            max=r-l;
        l++;
    }
    cout<<max<<endl;
    return 0;
}
