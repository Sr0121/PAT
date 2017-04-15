//
//  main.cpp
//  pat96
//
//  Created by Sr on 2017/4/15.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    vector<int> max;
    vector<int> cur;
    for(int i=2;i<sqrt(n);i++){
        int tmp=n;
        int tmp_i=i;
        cur.clear();
        while(tmp%tmp_i==0){
            cur.push_back(tmp_i);
            tmp/=tmp_i;
            tmp_i++;
        }
        if(max.size()<cur.size())
        {
            max.clear();
            for(int i=0;i<cur.size();i++){
                max.push_back(cur[i]);
            }
        }
    }
    
    if(max.size()>0){
        cout<<max.size()<<endl;
        for(int i=0;i<max.size();i++){
            if(i>0)
                cout<<'*';
            cout<<max[i];
        }
    }
    else
        cout<<1<<endl<<n;
    cout<<endl;
    return 0;
}
