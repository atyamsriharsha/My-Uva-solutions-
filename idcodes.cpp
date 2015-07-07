#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std; 
int main()
{
	char s[54] ;
	int l ;
	while(gets(s))
	{
		l = strlen(s) ;
		if(s[0]=='#')
			return 0 ;
		if(next_permutation(s,s+l)!=0)
		{
			puts(s) ;
		}
		else
		{
			cout << "No Successor" << endl ;
		}
		
	}
	return 0 ;
}