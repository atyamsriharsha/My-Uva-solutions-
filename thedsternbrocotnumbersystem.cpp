#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std ;


int main()
{
	int m,n ;
	int a,b,c,d,e,f ;
	while(1)
	{
		cin >> m >> n ;
		if(m==1 && n==1)
			break ;
		a = 0,b=1,c=1,d=0,f=1,e=1 ;
		while(1)
		{
			if(e==m && f==n)
			{
				break ;
			}
			if(e*n > f*m) 
			{
                cout << "L" ;
                b = e, d = f;
            } 
            else 
            {
                cout << "R" ;
                a = e, c = f;
            }
            e = a + b; 
            f = c + d;
		}
		cout << endl ;
	}
	return 0 ;
}