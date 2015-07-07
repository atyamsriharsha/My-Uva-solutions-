#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{ 
    int t,fu;
    scanf("%d",&t);
    for(fu=0;fu<t;fu++)
    {


int carry,number,flag,left,right,n,d,i,len=0,k,h,a[1000],counter=0,flag1;
scanf("%d",&n);
number=n;
if(n==0)
  printf("1\n");
for(i=0; ; i++)
{
    h= pow(10,i);
    d = n % h;
   if(d==n)
    break;
   len++;
}
for(i=len-1;i>=0;i--)
{
    
    h   = n % 10;  
    a[i] =  h;
    n= n / 10;
    if(a[i]== 9)
       counter++;  
}

if(counter==len && number!=0)
{
         printf("1");
        for(i=1;i <= len-1;i++)
            printf("0");
         printf("1\n");

    }

else if( (len%2) == 0)
{
    //printf("even");
    k=len/2 -1;flag=1;
    while(flag!=0 && k>=0)
    {
        if(a[k]==a[len-1-k])
        {
            flag=1;
            k=k-1;
        }
        else
            flag=0;
    }
    //left= number / pow(10,len-k-1);
    if(k>=0)
    {
    left=0;


    for(i=0;i<=k;i++)
    {   
        d=pow(10,i);
        left = left + a[i]*d;
    }

    d=pow(10,k+1);
    right= number % d;
    //printf("left:%d right:%d %d",left,right,k);
    if(left > right )
    {
        for(i=0;i<=k;i++)
             {a[len-1-i]=a[i];}

    }
    i=1;carry=1;
    if(right > left)
        {
            while(carry==1)
            {
            if(a[len/2 - i] + 1 > 9)
            {
                a[len/2 -i]= (a[len/2 - i] + 1) % 10;
                //a[len-1-len/2 + i]= a[len/2 -i];
                carry=1;
                i++;

            }
            else
            {
               carry=0;
               a[len/2 -i]= (a[len/2 - i] + 1) % 10;
                //a[len-1-len/2 + i]= a[len/2 -i];
            }

            }
            for(i=0;i<=len/2 -1;i++)
                a[len-1-i]=a[i];

        }
    }
    if(k<0)
        {
            i=1;carry=1;
    
            while(carry==1)
            {
            if(a[len/2 - i] + 1 > 9)
            {
                a[len/2 -i]= (a[len/2 - i] + 1) % 10;
                //a[len-1-len/2 + i]= a[len/2 -i];
                carry=1;
                i++;

            }
            else
            {
               carry=0;
               a[len/2 -i]= (a[len/2 - i] + 1) % 10;
                //a[len-1-len/2 + i]= a[len/2 -i];
            }

            }
            for(i=0;i<=len/2 -1;i++)
                a[len-1-i]=a[i];


        }
        if(number!=0)
        {
        for(i=0;i<len;i++)
         printf("%d",a[i]);
      printf("\n");
         }

}
else if( len%2 ==1)
{
    //printf("odd\n");

k=len/2 -1;flag=1;
    while(flag!=0 && k>=0)
    {
        if(a[k]==a[len-1-k])
        {
            flag=1;
            k=k-1;
        }
        else
            flag=0;
    }
    //left= number / pow(10,len-k-1);
    left=0;
    if(k>=0)
    {
        for(i=0;i<=k;i++)
    {   
        d=pow(10,i);
        left = left + a[i]*d;
    }

    d=pow(10,k+1);
    right= number % d;
    //printf("left:%d right:%d %d",left,right,k);
    if(left > right )
    {
        for(i=0;i<=k;i++)
             {a[len-1-i]=a[i];}

    }
    i=0;carry=1;
    if(right > left)
        {
            while(carry==1)
            {
            if(a[len/2 - i] + 1 > 9)
            {
                 //printf("magic");
                a[len/2 -i]= (a[len/2 - i] + 1) % 10;
                //a[len-1-len/2 + i]= a[len/2 -i];
                carry=1;
                i++;

            }
            else
            {
               carry=0;
               a[len/2 -i]= (a[len/2 - i] + 1) % 10;
               //printf("%d",a[len/2 -i]);
                //a[len-1-len/2 + i]= a[len/2 -i];
            }

            }
            for(i=0;i<=len/2;i++)
            {   
                //printf("%d ", a[i]);
                a[len-1-i]=a[i];
            }
        }
    }
    if(k<0)
    { 
        //printf("fuc");
        i=0;carry=1;
    
            while(carry==1)
            {
            if(a[len/2 - i] + 1 > 9)
            {
                a[len/2 -i]= (a[len/2 - i] + 1) % 10;
                //a[len-1-len/2 + i]= a[len/2 -i];
                carry=1;
                i++;

            }
            else
            {
               carry=0;
               a[len/2 -i]= (a[len/2 - i] + 1) % 10;
                //a[len-1-len/2 + i]= a[len/2 -i];
            }

            }
            for(i=0;i<=len/2 -1;i++)
                a[len-1-i]=a[i];
    }
        if(number!=0)
        {
        for(i=0;i<len;i++)
         printf("%d",a[i]);
     printf("\n");
 }


}


}
return 0;
}