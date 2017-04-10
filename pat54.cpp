//
//  main.cpp
//  pat54
//
//  Created by Sr on 2017/4/4.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    map<int,int> color;
    int m,n,c,max=0;
    int s;
    scanf("%d %d",&m,&n);
    for(int i=0;i<m*n;i++){
        scanf("%d",&c);
        if(color.find(c)==color.end()){
            color[c]=1;
        }
        else color[c]++;
        if(color[c]>max)
        {
            max=color[c];
            s=c;
            if(max>m*n/2)
                break;
        }
    }
    printf("%d\n",s);
    return 0;
}
