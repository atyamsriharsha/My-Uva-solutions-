#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std ;
int main(int argc, char const *argv[])
{
	long long int n,count1=0,temp,flag ;
	cin >> n ;
	std::vector<long long int> v;
	for(long long int i=0;i<n;i++)
	{
		cin >> temp ;
		v.push_back(temp) ;
	}
	sort(v.begin(),v.end()) ;
	while(1)
	{
		flag = 0 ;
	 for(long long int i=v.size()-1;i>=0;i--)
	 {
		if(v[i]==v[i-1] )
		{
			v[i] = v[i] + 1 ;
            count1++ ;
            flag = 1; 
		}
	  }
	  if(flag==0)
	  	break ;
	}
	  cout << count1 ;
	return 0;
}