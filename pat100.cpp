//
//  main.cpp
//  pat100
//
//  Created by Sr on 2017/4/15.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int find_mars(string *mars, string str)
{
    int i;
    for (i = 0; i < 25 && mars[i] != str; i++);
    return i;
}

int main(int argc, const char * argv[]) {
    string mars[25] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
        "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
    int n;
    cin>>n;
    getchar();
    for(int i=0;i<n;i++){
        string s;
        getline(cin,s);
        if(s[0]>='0'&&s[0]<='9'){
            int len=(int)s.length();
            int n=0;
            int flag=0;
            for(int i=0;i<len;i++){
                n*=10;
                n+=(s[i]-'0');
            }
            if(n/13>0)
            {
                cout<<mars[n/13+12];
                flag=1;
            }
            if(!(flag==1&&n%13==0))
            {
                if(flag==1)
                    cout<<' ';
                cout<<mars[n%13];
            }
        }
        else{
            int len=(int)s.length();
            int n=0;
            if(len>4){
                n=13*(find_mars(mars, s.substr(0,3))-12);
                n+=find_mars(mars, s.substr(4,len-4));
            }
            else
            {
                n+=find_mars(mars, s.substr(0,len));
                if(n>12){
                    n=13*(n-12);
                }
            }
            cout<<n;
        }
        cout<<endl;
    }
    return 0;
}
