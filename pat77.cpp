//
//  main.cpp
//  pat77
//
//  Created by Sr on 2017/4/12.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    string common,input;
    int n;
    scanf("%d",&n);
    getchar();
    getline(cin,input);
    common=input;
    for(int i=1;i<n;i++){
        getline(cin,input);
        int line1=(int)common.length()-1;
        int line2=(int)input.length()-1;
        int len=0;
        while(line1>=0&&line2>=0){
            if(common[line1]==input[line2])
            {
                len++;
                line1--;
                line2--;
            }
            else
                break;
        }
        common=common.substr(line1+1,(int)common.length()-line1);
        if(common.length()==0)
        {
            printf("nai\n");
            return 0;
        }
    }
    cout<<common<<endl;
    return 0;
}
