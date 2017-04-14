//
//  main.cpp
//  pat82
//
//  Created by Sr on 2017/4/14.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
string a[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string b[] = {"Qian", "", "Shi", "Bai"};

int main(int argc, const char * argv[]) {
    string input;
    int start=0;
    int flag=0;
    cin>>input;
    if(input=="0")
        cout<<"ling"<<endl;
    else{
        int len=(int)input.size(),i=0;
        if(input[0]=='-')
        {
            cout<<"Fu";
            len--;
            start++;
            i++;
        }
        while(len>0){
            if(input[i]=='0'){
                i++;
                len--;
                while(len%4!=0)
                {
                    if(input[i]!='0'&&input[i]!='\0')
                    {
                        cout<<" ling";
                        break;
                    }
                    i++;
                    len--;
                }
                if(len==4&&flag==1)
                {
                    cout<<" Wan";
                    flag=0;
                }
                if(len==8&&flag==1)
                {
                    cout<<" Yi";
                    flag=0;
                }
            }
            else{
                if(start)
                    cout<<" "<<a[input[i]-'0'];
                else{
                    cout<<a[input[i]-'0'];
                    start=1;
                }
                flag=1;
                if(len%4!=1)
                    cout<<" "<<b[len%4];
                if(len==5)
                {
                    cout<<" Wan";
                    flag=0;
                }
                if(len==9)
                {
                    cout<<" Yi";
                    flag=0;
                }
                i++;
                len--;
            }
        }
        cout<<endl;}
    return 0;
}
