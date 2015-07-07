/************************************************************
   Author : atyam
************************************************************/

#include <bits/stdc++.h>
using namespace std ;
#define ll long long

/*debugging*/

#define out1(x)cout<<#x<<" is "<<x<<endl
#define out2(x,y)cout<<#x<<" is "<<x<<" "<<#y <<" is "<<y<<endl
#define out3(x,y,z)cout<<#x<<" is "<<x<<" "<<#y<<" is "<<y<<" "<<#z<<" is "<<z<<endl;
#define out4(a,b,c,d)cout<<#a<<" is "<<a<<" "<<#b<<"  is "<<b<<" "<<#c<<" is "<<c<<" "<<#d<<" is "<<d<<endl;
#define show(i,a,n) for(i=0;i<n;i++)cout<<a[i]<<" ";cout<<endl;
#define sz(a) cout<<"size of "<<#a<<" is "<<a.size()
#define exectime() cout<<"execution time "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<endl;

/*standard values*/

#define INF 1e18
#define PI 3.14159265359
#define MAX 1000006


/*Frequent functions*/
#define all(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pu putchar
#define gu getchar
#define FastIn std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

/*loops and initialisation*/

#define init(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repi(i,a,b) for(i=a;i>=b;i--)
#define repdf(i,a,b,d) for(i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(i=a;i>=b;i-=d)
#define TC() int t;cin>>t;while(t--)
#define vi vector<int> v
#define vc vector<char> v

std::map<string,int>visited;
std::map<string,vector<string> >graph;

int bfs(string a,string b)
{
	queue<string> s ;
	s.push(a) ;
	visited[a] = 0 ;
	while(!s.empty())
	{
		string top = s.front() ;
		s.pop() ;
		if(top==b)
			return visited[top] ;
		int total_size =graph[top].size() ;
		for(int i=0;i<total_size;i++)
		{
			if(!visited.count(graph[top][i]))
			{
               visited[graph[top][i]]= visited[top]+1;
               s.push(graph[top][i]);
            }
		} 
	}
} 

int main()
{
	int test ;
	cin >> test ;
	string temp,input,ref ;
	getchar() ;
	while(test--)
	{
		while(1)
		{
			cin >> temp ;
			if(temp=="*")
				break ;
			graph[temp] ;
			std::map<string,vector<string> >::const_iterator it;
			for(it=graph.begin();it!=graph.end();it++)
			{
				bool flag1 = 0 ;
			    int count1 = 0 ;
				ref = (*it).first ;
				if(ref.size()==temp.size())
				{
					for(int i=0;i<temp.size();i++)
					{
						if(ref[i]!=temp[i])
							count1++ ;
						if(count1>1)
						{
							flag1 = 1 ;
							break ;
						}
					}
					if(flag1==0)
					{
						graph[ref].PB(temp) ;
						graph[temp].PB(ref) ;
					}
				}
			}
		}
		string from,to,input ;
		size_t pos ;
		getline(cin,input) ;
		getline(cin,input) ;
		while(input!="")
		{
			pos = input.find(" ") ;
			from = input.substr(0,pos) ;
			to  = input.substr(pos+1,input.size()) ;
			visited.clear() ;
			cout << from << " " << to << " " ;
			cout << bfs(from,to) << endl ;
			if(!getline(cin,input))
				break ;
		}
		if(test!=0)
			cout << endl ;
	}
  return 0 ;
}