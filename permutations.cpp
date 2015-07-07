#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std ;

unsigned long long res[20] ;
int main()
{
	int test,length,i,next ;
	string s ;
	unsigned long long n,temp =1 ;
	res[0] = 1 ;
	for(i=1;i<20;i++)
	{
		temp = temp*i ;
		res[i] = temp ;
	}
	cin >> test ;
	while(test--)
	{
		cin >> s >> n ;
		n++ ;
		//length = s.length() ;
		std::sort(s.begin(),s.end());
		for(i=0,length=s.size();i<length;i++)
		{
			next = 0 ;
			while(res[s.size()-1]<n)
			{
				n = n - res[s.size()-1] ;
				next++ ;
			}
			cout << s[next] ;
            s.erase(s.begin()+next) ;
		}
		cout << endl ;
	}
	return 0 ;
}