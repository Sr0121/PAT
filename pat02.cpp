#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int i,n,ex;
    int num=0;
    double ele;
    double a[1001]={0};
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>ex>>ele;
        a[ex]=ele;
    }
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>ex>>ele;
        a[ex]+=ele;
    }
    for(i=1000;i>=0;i--)
    {
        if(a[i]!=0)
            num++;
    }
    cout<<num;
    for(i=1000;i>=0;i--)
    {
        if(a[i]!=0)
            printf(" %d %.1f", i,a[i]);  
    }
}
