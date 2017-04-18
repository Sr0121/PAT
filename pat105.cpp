//
//  main.cpp
//  pat105
//
//  Created by Sr on 2017/4/17.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int out[105][105]={0};

bool cmp(int &a,int &b)
{
    return a>b;
}

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    vector<int> s(n);
    for(int i=0;i<n;i++)
        cin>>s[i];
    int l,w;
    l=sqrt(n);
    if(n%l==0)
    {
        w=n/l;
        if(l<w)
            l++;
    }
    while(n%l!=0)
        l++;
    w=n/l;
    sort(s.begin(),s.end(),cmp);
    int x=0,y=0;
    int direct=0;
    for(int i=0;i<n;i++)
    {
        out[x][y]=s[i];
        if(direct==0&&(out[x][y+1]!=0||y+1>=w))
        {
            direct=1;
        }
        else if(direct==1&&(out[x+1][y]!=0||x+1>=l))
        {
            direct=2;
        }
        else if(direct==2&&(out[x][y-1]!=0||y-1<0))
        {
            direct=3;
        }
        else if(direct==3&&(out[x-1][y]!=0||x-1<0))
        {
            direct=0;
        }
        switch (direct) {
            case 0:
                y++;
                break;
            case 1:
                x++;
                break;
            case 2:
                y--;
                break;
            default:
                x--;
                break;
        }
    }
    for(int x=0,y=0;y<l;x++){
        if(x==0)
            cout<<out[y][x];
        else
            cout<<" "<<out[y][x];
        if(x==w-1)
        {
            x=-1;
            y++;
            cout<<endl;
        }
    }
    return 0;
}
