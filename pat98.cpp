//
//  main.cpp
//  pat98
//
//  Created by Sr on 2017/4/15.
//  Copyright © 2017年 Sr. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 101

int m;
int b[MAX_NUM];

int check(int a[], int b[])
{
    int i;
    for (i = 0; i < m; i++)
    {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}

void percdown(int a[], int i, int N)
{
    int child;
    int tmp;
    for (tmp = a[i]; 2*i < N-1 ; i = child)
    {
        child = 2 * i + 1;
        if (child + 1 < N && a[child + 1] > a[child])
            child++;
        if (tmp < a[child])
            a[i] = a[child];
        else
            break;
    }
    a[i] = tmp;
}

void heapsort(int a[], int N)
{
    int i,tmp;
    for (i = N / 2; i >= 0; i--)
    {
        percdown(a, i, N);
    }
    for (i = N - 1; i > 0; i--)
    {
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        percdown(a, 0, i);
        if (check(a, b))
            break;
    }
    if(check(a,b))
    {
        i--;
        tmp = a[0];
        a[0] = a[i];
        a[i] = tmp;
        percdown(a, 0, i);
        printf("Heap Sort\n");
        for (i = 0; i < m; i++)
        {
            i == m - 1 ? printf("%d", a[i]) : printf("%d ", a[i]);
        }
    }
}

void insertion(int a[], int N)
{
    int i, j,flag=0;
    int tmp;
    for (i = 1; i < N; i++)
    {
        tmp = a[i];
        for (j = i; a[j - 1] > tmp&&j > 0; j--)
            a[j] = a[j - 1];
        a[j] = tmp;
        if(check(a, b))
        {
            printf("Insertion Sort\n");
            break;
        }
    }
    if (check(a, b))
    {
        i++;
        tmp = a[i];
        for (j = i; a[j - 1] > tmp&&j > 0; j--)
            a[j] = a[j - 1];
        a[j] = tmp;
        for (i = 0; i < m; i++)
        {
            i == m - 1 ? printf("%d", a[i]) : printf("%d ", a[i]);
        }
    }
}

int main()
{
    int i;
    int a[MAX_NUM],c[MAX_NUM];
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d",&a[i]);
        c[i] = a[i];
    }	
    for (i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    insertion(a, m);
    heapsort(c, m);
    
    
    
    system("pause");
    return 0;
}
