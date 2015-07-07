#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std ; 


int main()
{
    int n,c,s,sum,t,i,first,last,mass[15];
    double average,balnce;
    t=0;
    while(scanf("%d %d",&c,&s)==2)
    {
        balnce=0;
        t++;
        sum=0;
        for(i=0;i<15;i++)
            mass[i]=100000000;
        for(i=0;i<s;i++)
        {
            scanf("%d",&mass[i]);
            sum+=mass[i];
        }
        average=(sum*1.0)/c;
     
        for(i=s;i<2*c;i++)
            mass[i]=0;
        sort(mass,mass+2*c);
        printf("Set #%d\n",t);
        for(i=0;i<c;i++)
        {
            first=mass[i];
            last=mass[2*c-i-1];
            if(first==0&&last!=0)
                printf(" %d: %d\n",i,last);
            else if(first==0&&last==0)
                printf(" %d:\n",i);
            else
                printf(" %d: %d %d\n",i,first,last);
            balnce+=abs(((first*1.0+last*1.0)-average))*1.0;   
        }
        printf("IMBALANCE = %0.5f\n\n",balnce);    
    }   
    return 0;
}