//
//  main.cpp
//  pat61
//
//  Created by Sr on 2017/4/7.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
using namespace std;
string s[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main(int argc, const char * argv[]) {
    char s1[61],s2[61],s3[61],s4[61];
    int count=0;
    int p=-1;
    scanf("%s%s%s%s",s1,s2,s3,s4);
    for(int i=0;s1[i]!='\0'&&s2[i]!='\0';i++){
        if(count==0&&s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='G'){
            printf("%s ",s[s1[i]-'A'].c_str());
            count++;
        }
        else if(count==1&&((s1[i]>='A'&&s1[i]<='N')||(s1[i]>='0'&&s1[i]<='9'))&&s1[i]==s2[i]){
            if(s1[i]>='0'&&s1[i]<='9'){
                printf("%02d:",s1[i]-'0');
            }
            else {
                printf("%02d:",s1[i]-'A'+10);
            }
            break;
        }
    }
    for(int i=0;s3[i]!='\0'&&s4[i]!='\0';i++){
        if(s3[i]==s4[i]&&((s3[i]>='a'&&s3[i]<='z')||(s3[i]>='A'&&s3[i]<='Z'))){
            p=i;
            printf("%02d\n",i);
            break;
        }
    }
    if(p==-1) printf("00\n");
    return 0;
}
