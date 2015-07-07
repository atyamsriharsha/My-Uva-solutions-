#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
	double h,u,d,f ;
	while(1)
	{
		cin >> h >> u >> d >> f ;
		if(h==0)
		  return 0 ;
		int day = 1;  
        double up = u,height=0,reduce=u*f/100;    
        string result = "success on day ";  
        for(day = 1;; day++)  
        {  
            height = height + up;  
            if(height > h)  
               break;  
            height = height - d;  
            if(height<0)  
            {  
               result = "failure on day ";  
               break;  
            }  
            up = up - reduce;  
            if(up < 0)  
               up = 0;
        } 
        cout << result << day << endl ; 
	}
	return 0 ;
}