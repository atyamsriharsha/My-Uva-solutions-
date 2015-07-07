#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std ;
struct array
{
	int in ;
	string num ;
}a[100000];

bool comp(array x, array y)
{
	return x.in < y.in ? 1:0 ;
}
int main()
{
	int test,i ;
	cin >> test ;
	getchar();
	bool blank = false ;
	while(test--)
	{
		char input[100000] ;
		gets(input) ;
		gets(input) ;
		char *pch = strtok(input," ");
		int index = 0 ;
		while(pch!=NULL)
		{
           a[index].in = atoi(pch) ;
           pch = strtok(NULL," ") ;
           index++ ;
		}
		gets(input) ;
		index = 0 ;
		pch = strtok(input," ");
		while(pch!=NULL)
		{
			a[index].num = pch ;
			pch = strtok(NULL," ") ;
			index++ ;
		}
		sort(a,a+index,comp) ;
		if(blank)cout << endl ;
			blank = true ;
        for(i=0;i<index;i++)
        {
        	cout << a[i].num << endl ;

        }
	}
	return 0 ;
}