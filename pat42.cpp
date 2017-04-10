//
//  main.cpp
//  pat42
//
//  Created by Sr on 2017/3/22.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

string num2str(int i)
{
    stringstream ss;
    ss<<i;
    return ss.str();
}

string card_type(int n)
{
    int i=(n-0.5)/13;
    string s;
    switch (i) {
        case 0:
            s+="S";
            break;
        case 1:
            s+="H";
            break;
        case 2:
            s+="C";
            break;
        case 3:
            s+="D";
            break;
        default:
            s+="J";
            break;
    }
    i=n%13;
    if(i==0)
        i=13;
    s+=num2str(i);
    return s;
}

int main(int argc, const char * argv[]) {
    int r;
    int shuffle[55];
    int card[55];
    int card_shuffled[55];
    cin>>r;
    for(int i=1;i<=54;i++)
    {
        cin>>shuffle[i];
        card[i]=i;
    }
    for(int j=0;j<r;j++)
    {
        for(int i=1;i<55;i++)
            card_shuffled[shuffle[i]]=card[i];
        for(int i=1;i<55;i++)
            card[i]=card_shuffled[i];
    }
    cout<<card_type(card[1]);
    for(int i=2;i<55;i++)
        cout<<' '<<card_type(card[i]);
    return 0;
}
