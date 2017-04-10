//
//  main.cpp
//  pat10
//
//  Created by Sr on 2017/3/5.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long int str2num(string s,long long radix,int len)
{
    int i;
    long long int sum=0;
    for(i=0;i<len;i++)
    {
        if(s[i]<='9')
            sum+=(s[i]-'0')*pow(radix,len-1-i);
        else
            sum+=(s[i]-'a'+10)*pow(radix,len-1-i);
    }
    return sum;
}

long long findLowRadix(string p)
{
    long long len=p.length();
    long long low=0;
    long long num=0;
    for(long long i=len-1;i>=0;i--)
    {
        if(p[i]>='a'&&p[i]<='z')
            num= p[i] - 'a' + 10;
        else if(p[i]>='0'&& p[i]<='9')
            num=p[i] - '0';
        if(num+1>low)
            low=num+1;
    }
    return low;
}

int compare(long long int a,string b,long long radix)
{
    long long dec_b;
    int l2=(int)b.length();
    dec_b=str2num(b,radix,l2);
    if (dec_b==a)
        return 0;
    if (dec_b>a)
        return 1;
    else
        return -1;
}

long long binarySearch(string p, long long int a,long long low,long long high)
{
    long long mid;
    int tmp;
    
    while(low<=high)
    {
        mid=(low+high)/2;
        tmp = compare(a,p,mid);
        if(tmp>0)
        {
            high = mid-1;
        }
        else if(tmp<0)
        {
            low = mid +1;
        }
        else
            return mid;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    string a,b,c;
    int l1,l2;
    int tag;
    long long radix;
    long long radix_n;
    long long low;
    long long dec_a;
    cin>>a>>b>>tag>>radix;
    if (a==b)
    {
        cout<<radix;
        return 0;
    }
    if(tag==2)
    {
        c=a;
        a=b;
        b=c;
    }
    l1=(int)a.length();
    l2=(int)b.length();
    dec_a=str2num(a,radix,l1);
    low=findLowRadix(b);
    radix_n=binarySearch(b, dec_a, low, 10000);
    if(radix_n!=-1)
        cout<<radix_n;
    else
        cout<<"Imposible";
    return 0;
}
