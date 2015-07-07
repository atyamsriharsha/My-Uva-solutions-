#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;
int ans ;

bool comp(int i,int j)
{
	return i>j ;
}

class unionfind
{
public:
	unionfind(int size) ;
	bool issameset(int a,int b) ;
	int findset(int a) ;
	void unionset(int a,int b) ;
	int sizeofset(int a) ;
	int numofdisjointsets() ;
	int size ;
	std::vector<int> pset;
	std::vector<int> size_set;
	std::vector<int> rank;
};

unionfind::unionfind(int size)
{
	this->size = size ;
	size_set.assign(size,1) ;
	pset.assign(size,0) ;
	for(int i=0;i<size;i++)
	{
		pset[i] = i ;
	}
	rank.assign(size,0) ;
}

int unionfind::findset(int a)
{
	return pset[a]==a?a:(pset[a]=findset(pset[a])) ;
}

bool unionfind::issameset(int a,int b)
{
	return findset(a)==findset(b) ;
}

void unionfind::unionset(int a,int b)
{
	if(issameset(a,b))
		return ;
	size-- ;
	if(rank[findset(b)]>rank[findset(a)])
	{
	  size_set[findset(b)] +=size_set[findset(a)] ;
	  pset[findset(a)] =findset(b) ;
	}
	else if(rank[findset(a)] > rank[findset(b)])
	{
		size_set[findset(a)]+=size_set[findset(b)] ;
		pset[findset(b)] = findset(a) ;
	}
	else
	{
		rank[findset(b)]+=1 ;
	}

}

int main(void)
{
	int test,n,m,x,y,i ;
	cin >> test ;
	while(test--)
	{
	   ans = 1 ; 
       cin >> n ;
       cin >> m ;
       unionfind result(n) ;
       for(i=0;i<m;i++)
       {
            cin >> x ;
            cin >> y ;
          result.unionset(x-1,y-1) ;
       }
       sort(result.size_set.begin(),result.size_set.end(),comp) ;
       cout << ans << endl ;
	}
	return 0 ;
}