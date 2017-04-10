//
//  main.cpp
//  pat71
//
//  Created by Sr on 2017/4/10.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    string line;
    string word="";
    string out_put;
    int max_num=-1;
    getline(cin,line);
    map<string,int> dic;
    for(int i=0;line[i]!='\0';i++){
        while(isalpha(line[i])||isdigit(line[i]))
        {
            if(isalpha(line[i])&&isupper(line[i])){
                line[i]+=32;
            }
            word+=line[i];
            i++;
        }
        if(word!="")
        {
            dic[word]++;
            if(dic[word]>max_num)
            {
                out_put=word;
                max_num=dic[word];
            }
        }
        word="";
    }
    cout<<out_put<<' '<<dic[out_put]<<endl;
    return 0;
}
