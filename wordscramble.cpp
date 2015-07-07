#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
#define maxlength 10000
int main()
{
	int length ,c,i;
	char s[maxlength] ;
	while(scanf("%s",s)!=EOF)
	{
		length = strlen(s) ;
		//cout << length ;
		c = getchar() ;
		for(i=length-1;i>=0;i--)
		{
			printf("%c",s[i]);
		}
		putchar(c);
	}
	return 0 ;
}