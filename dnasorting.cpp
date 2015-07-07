#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std ;
struct input
{
	string s ;
	int index ;
}a[100 + 3];

int countmeasure(string p)
{
	int j,k,count=0 ;
	for(j=0;p[j];j++)
    {
        for(k=j+1;p[k];k++)
      	{
      		if(p[j]>p[k])
      		{
      			count++ ;
      		}
      	}
    }
    return count ;
}

bool istruth(input a,input b)
{
	return a.index < b.index ;
}
int main()
{
	int test,length,n,i=0,count=0,j,k,r ;
	cin >> test ;
	bool blank = false ;
	//cin.ignore(100,'\n') ;
	while(test--)
	{
      cin >> length >> n ;
      r=n ;
      //std::vector<input> v;
      while(n--)
      {
      	count = 0 ;
      	cin >> a[i].s ;
      	a[i].index = countmeasure(a[i].s) ;
      	i++ ;
      }
      stable_sort(a,a+r,istruth) ;
      if(blank) printf ("\n");
        blank = true; 
      for(i = 0; i < r; i++ )
            cout << a [i].s << endl;
	}
	return 0 ;
}