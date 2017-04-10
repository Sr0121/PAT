//
//  main.cpp
//  pat29
//
//  Created by Sr on 2017/3/15.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,m,o;
    long int *a,*b;
    int a1=0,a2=0;
    cin>>n;
    a=new long int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    b=new long int[m];
    for(int i=0;i<m;i++)
        cin>>b[i];
    o=(n+m-1)/2;
    for(int i=0;i<o;i++)
    {
        if(a1<n&&a2<m)
        {
            if(a[a1]<b[a2])
                a1++;
            else a2++;
        }
        else if(a1>=n)
            a2++;
        else if(a2>=m)
            a1++;
    }
    if(a1<n&&a2<m)
    {
        if(a[a1]<b[a2])
            cout<<a[a1];
        else cout<<b[a2];
    }
    else if(a1>=n)
        cout<<b[a2];
    else if(a2>=m)
        cout<<a[a1];
    
    return 0;
}
