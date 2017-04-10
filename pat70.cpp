//
//  main.cpp
//  pat70
//
//  Created by Sr on 2017/4/10.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct info{
    double total;
    double total_price;
    double price;
    bool operator < (const struct info &x) const{
        return price>x.price;
    }
};

int main(int argc, const char * argv[]) {
    int n;
    double m;
    double sum=0;
    scanf("%d%lf",&n,&m);
    struct info *node;
    node=new struct info[n];
    for(int i=0;i<n;i++)
        scanf("%lf",&node[i].total);
    for(int i=0;i<n;i++)
    {
        scanf("%lf",&node[i].total_price);
        node[i].price=(double)node[i].total_price/node[i].total;
    }
    sort(node,node+n);
    for(int i=0;i<n;i++){
        if(m-node[i].total<=0){
            sum+=m*node[i].price;
            break;
        }
        else{
            sum+=node[i].total_price;
            m-=node[i].total;
        }
    }
    printf("%0.2lf\n",sum);
    return 0;
}
