#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std ;
 
int main ()
{
    int k;
    bool blank = false;
    while(scanf("%d", &k) && k) 
    {
        if(blank)
           printf ("\n");
        blank = true;
        int x[13],a,b,c,d,e,f;
        for(int i = 0;i<k;i++)
            scanf("%d",&x[i]);
        for(a = 0;k-a>5;a++)
        {
            for(b = a + 1; k - b > 4; b++) 
            {
                for(c = b + 1; k - c > 3; c++ ) 
                {
                    for(d = c + 1; k - d > 2; d++) 
                    {
                        for(e = d + 1; k - e > 1; e++) 
                        {
                            for(f = e + 1; k - f > 0; f++)
                            {
                                cout << " "<< x[a] << " "<< x[b] << " "<< x[c]<< " " << x[d]<< " " << x[e]<< " " << x[f] << endl ;
                            }
                        }
                    }
                }
            }
        }
    }
	return 0 ;
}