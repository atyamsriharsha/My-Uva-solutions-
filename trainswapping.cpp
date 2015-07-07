#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std ;
int main()
{
	int test,l,i,temp ,count,j;
	cin >> test ;
	std::vector<int> v;
	while(test--)
	{
	   v.clear() ;
       cin >> l ;
       for(i=0;i<l;i++)
       {
       	cin >> temp ;
       	v.push_back(temp) ;
       }
       count = 0 ;
       for(i=1;i<l;i++)
       {
       	 for(j=l-1;j>=i;j--)
       	 {
       		if(v[j-1]>v[j])
       		{
       			count++ ;
       			swap(v[j-1],v[j]) ;
       		}
       	 }
       }
       cout << "Optimal train swapping takes " << count << " swaps." << endl ;
	}
	return 0 ;
}
