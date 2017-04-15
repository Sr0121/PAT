//来自ds同组成员陈诗翰

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

struct TIME
{
    int h,m,s;
    friend bool operator < (TIME a,TIME b)
    {
        if (a.h==b.h && a.m==b.m) return a.s<b.s;
        if (a.h==b.h) return a.m<b.m;
        return a.h<b.h;
    }
    
    friend bool operator == (TIME a,TIME b)
    {
        return (a.h==b.h && a.m==b.m && a.s==b.s);
    }
    
    friend TIME operator - (TIME a,TIME b)
    {
        TIME c;
        c.h = a.h - b.h;
        c.m = a.m - b.m;
        c.s = a.s - b.s;
        if (c.s<0)
        {
            c.s+=60;
            c.m--;
        }
        if (c.m<0)
        {
            c.m+=60;
            c.h--;
        }
        return c;
    }
    
    friend TIME operator + (TIME a,TIME b)
    {
        TIME c;
        c.h = a.h + b.h;
        c.m = a.m + b.m;
        c.s = a.s + b.s;
        if (c.s>=60)
        {
            c.s-=60;
            c.m++;
        }
        if (c.m>=60)
        {
            c.m-=60;
            c.h++;
        }
        return c;
    }
    
    void read()
    {
        char ss[10];
        scanf("%s",ss);
        h = (ss[0]-'0')*10 + ss[1]-'0';
        m = (ss[3]-'0')*10 + ss[4]-'0';
        s = (ss[6]-'0')*10 + ss[7]-'0';
    }
    
    void print()
    {
        printf("%02d:%02d:%02d\n",h,m,s);
    }
}query;

struct event
{
    string num;
    TIME T;
    int type;
    bool ok;
    friend bool operator < (event a,event b)
    {
        return a.T<b.T;
    }
}E[100010];

map<string,int> mp;
map<string,TIME> sum;
vector<string> ans;

int N,K;

int main()
{
    scanf("%d%d",&N,&K);
    char tmp[10];
    for (int i=1;i<=N;i++)
    {
        scanf("%s",tmp);
        E[i].num = string(tmp);
        mp[E[i].num] = 0;
        sum[E[i].num] = (TIME){0,0,0};
        E[i].T.read();
        E[i].ok = true;
        scanf("%s",tmp);
        if (tmp[0]=='i') E[i].type = 1;
        else E[i].type = 2;
    }
    E[0].type = 2;
    
    sort(E+1,E+N+1);
    
    /*
     for (int i=1;i<=N;i++)
     //if (E[i].ok)
     {
     cout<<E[i].num<<' ';
     E[i].T.print();
     printf("%d\n",E[i].type);
     }puts("FF");*/
    
    
    for (int i = 1;i <= N; i++)
    {
        bool flag = false;
        if (E[mp[E[i].num]].type == E[i].type) //1x 1    2 2x
        {
            if (E[i].type == 1)
            {
                E[mp[E[i].num]].ok = false;
                //mp[E[i].num] = i;
                flag = true;
            }
            else
            {
                E[i].ok = false;
            }
        }
        else flag = true;//mp[E[i].num] = i;
        if (E[i].ok && E[i].type==2)
        {
            //puts("AAAAAAA");
            //E[i].T.print();
            //E[mp[E[i].num]].T.print();
            TIME delta = E[i].T - E[mp[E[i].num]].T;
            //delta.print();
            sum[E[i].num] = sum[E[i].num] + delta;
        }
        if (flag) mp[E[i].num] = i;
    }
    
    for (int i = 1;i <= N; i++)
    {
        if (E[mp[E[i].num]].type == 1)
        {
            //printf("%d\n!",mp[E[i].num]);
            E[mp[E[i].num]].ok = false;
        }
    }
    
    /*
     for (int i=1;i<=N;i++)
     if (E[i].ok)
     {
     cout<<E[i].num<<' ';
     E[i].T.print();
     printf("%d\n",E[i].type);
     }*/
    
    int now = 1,cnt = 0;
    for (int i = 1;i <= K;i++)
    {
        query.read();
        while((now <= N) && !(query<E[now].T))
        {
            if (E[now].ok)
            {
                if (E[now].type==1) cnt++;
                else cnt--;
            }
            now++;
        }
        //printf("%d\n",now);
        printf("%d\n",cnt);
    }
    TIME MAXT = (TIME){0,0,0};
    for (int i = 1;i <= N;i++)
    {
        //sum[E[i].num].print();
        if (MAXT<sum[E[i].num])
        {
            ans.clear();
            MAXT = sum[E[i].num];
            ans.push_back(E[i].num);
        }
        else if (MAXT == sum[E[i].num]) ans.push_back(E[i].num);
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    for (int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
    MAXT.print();
}
