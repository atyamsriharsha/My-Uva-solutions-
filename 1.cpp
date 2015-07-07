#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std ;

int main()
{
	long long int n,k,w,i,temp,sum=0 ;
	cin >> k >> n >> w ;
	for(i=0;i<w;i++)
	{
		temp = (i+1)*k ;
        sum = sum + temp ;
	}
	//cout << sum ;
	//cout << k ;
	if(sum > n)
	{
		cout << sum-n ;
	}
	else
	{
		cout << "0" ;
	}
	return 0;
}