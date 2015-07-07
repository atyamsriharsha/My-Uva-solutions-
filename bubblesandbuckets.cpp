#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std ;
std::vector<int> v;
unsigned long long swaps ;
void merge(int p,int q,int r)
{
	int i,k ;
	int len1 = q-p+1 ;
	int len2 = r-q ;
	std::vector<int> left ;
	std::vector<int> right;
	for(i=0;i<len1;i++)
	{
		left.push_back(v[p+i]) ;
	}
	for(i=0;i<len2;i++)
	{
		right.push_back(v[q+i+1]) ;
	}
	left.push_back(999999999 + 10) ;
	right.push_back(999999999 + 10) ;
	size_t x =0,y = 0 ;
	for(k = p; k <= r; k++) 
	{
        if(left[x] <= right[y]) 
        {
        	 v[k] = left[x++];
        }
        else 
        {
            v[k] = right [y++];
            swaps += len1 - x;
        }
    }

}

void merge_sort(int p,int r)
{
	if(p<r)
	{
		int q = (int)floor((p+r)/2) ;
		merge_sort(p,q) ;
		merge_sort(q+1,r) ;
		merge(p,q,r) ;
	}
}

int main(int argc, char const *argv[])
{
	int n,temp,i ;
	while(1)
	{
		cin >> n ;
		swaps = 0 ;
		if(n==0)
			break ;
		v.clear();
		for(i=0;i<n;i++)
		{
            cin >> temp ;
            v.push_back(temp) ;
		}
		merge_sort(0,n-1) ;
		if(swaps%2!=0)
			cout << "Marcelo" << endl ;
		else
			cout << "Carlos" << endl;
		//cout << swaps << endl ; 
	}
 	
 	return 0;
 } 