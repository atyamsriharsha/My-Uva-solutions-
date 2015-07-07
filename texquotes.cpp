#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <string.h>
using namespace std ;
int main()
{
	char s[10000] ;
	bool flag = true ;
	while(gets(s))
	{
		int length = strlen(s),i ;
		for(i=0;i<length ;i++)
		{
			if(s[i]=='"')
			{
				if(flag)
				 printf("``");
				else
					printf("''");
				flag = !flag ;
			}	
			else 
			{
				printf("%c",s[i]);
			}
		}
    	printf("\n");
    }
	return 0 ;
}