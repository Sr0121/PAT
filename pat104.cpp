//
//  main.cpp
//  pat104
//
//  Created by Sr on 2017/4/17.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    vector<double> s;
    for(int i=0;i<n;i++){
        double a;
        cin>>a;
        s.push_back(a);
    }
    double sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=s[i]*(i+1)*(n-i);//高精度写在前面
    }
    printf("%.2lf\n",sum);
    return 0;
}
