/************************************************************
   Author : atyam
************************************************************/

#include <bits/stdc++.h>
using namespace std ;


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
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repi(i,a,b) for(i=a;i>=b;i--)
#define repdf(i,a,b,d) for(i=a;i<=b;i+=d)
#define repdb(i,a,b,d) for(i=a;i>=b;i-=d)
#define TC() int t;cin>>t;while(t--)

#define dfs_white 0
#define dfs_grey 1 
#define dfs_black 2

/* Global variables*/
std::map<char,set<char> > input_graph ;
std::map<char,int> numbering;
std::map<int,char> naming;
std::vector<int> colors;
std::vector<int> dfs_num;
std::vector<int> dfs_low;
std::vector<bool> in_stack;
std::vector<vector<char> > result;
stack<int> stronglyconnected_nodes ;
std::vector<vector<int> > adjacency_list;
int dfs_current_num ;

/*Functions used*/
int number(char c)
{
	map<char,int>::iterator it = numbering.find(c) ;
	if(it==numbering.end())
	{
		int size = numbering.size() ;
		numbering.insert(pair<char,int>(c,size)) ;
		naming.insert(pair<int,char>(size,c)) ;
		return size ;
	}
	else
	{
		return it->second ;
	}
}

void addedge(char src,char dest)
{
	map<char,set<char> >::iterator it = input_graph.find(src) ;
	if(it==input_graph.end())
	{
		set<char> neighbour ;
		neighbour.insert(dest) ;
		input_graph.insert(pair<char,set<char> >(src,neighbour)) ;
	}
	else
	{
		it->second.insert(dest) ;
	}
}

void dfs(int parent,int current)
{
	if(colors[current]!=dfs_white)
	{
		return ;
	}
	dfs_num[current] = dfs_low[current] = dfs_current_num++ ;
	colors[current] = dfs_grey ;
	in_stack[current] = true ;
	stronglyconnected_nodes.push(current) ;
	for(std::vector<int>::iterator it = adjacency_list[current].begin();it!=adjacency_list[current].end();it++)
	{
		int pakkadi = *it ;
		if(colors[pakkadi]==dfs_white)
		{
			dfs(current,pakkadi) ;
			dfs_low[current] = min(dfs_low[current],dfs_low[pakkadi]) ;
		}
		else if(in_stack[pakkadi])
		{
			dfs_low[current] = min(dfs_low[current],dfs_num[pakkadi]) ;
		}
	}
	colors[current] = dfs_grey ;
	if(dfs_low[current]==dfs_num[current])
	{
		std::vector<char> stronglyconnected_components;
		while(1)
		{
			int top = stronglyconnected_nodes.top() ;
			stronglyconnected_components.PB(naming[top]) ;
			in_stack[top] = false ;
			stronglyconnected_nodes.pop() ;
			if(top==current)
				break ;
		}
		result.PB(stronglyconnected_components) ;
	}
	
}


int main()
{
	char c1,c2,c3,c4,c5 ;
    char ans ;
	int test = 0 ;
	while(1)
	{
		dfs_current_num = 0 ;
		colors.clear() ;
		in_stack.clear() ;
		dfs_num.clear() ;
		dfs_low.clear() ;
		input_graph.clear() ;
		numbering.clear() ;
		naming.clear() ;
		result.clear() ;
		adjacency_list.clear() ;
		while(!stronglyconnected_nodes.empty())
		  stronglyconnected_nodes.pop() ;
		test++ ;
		int n ;
		cin >> n ;
		if(n==0)
			break ;
		for(int i=0;i<n;i++)
		{
			cin >> c1 >> c2 >> c3 >> c4 >> c5 >> ans ;
			number(c1) ;
			number(c2) ;
			number(c3) ;
			number(c4) ;
			number(c5) ;
			number(ans) ;
			if(c1!=ans)
			{
				addedge(ans,c1) ;
			}
			if(c2!=ans)
			{
                addedge(ans,c2) ;
			}
			if(c3!=ans)
			{
                addedge(ans,c3) ;
			}
			if(c4!=ans)
			{
                addedge(ans,c4) ;
			}
			if(c5!=ans)
			{
                addedge(ans,c5) ;
			}
		}
        int number_of_nodes = numbering.size() ;
        adjacency_list.resize(number_of_nodes) ;
        for(map<char, set<char> >::iterator gi = input_graph.begin(); gi != input_graph.end(); gi++)
        {
            int from = number(gi->first);
            for (set<char>::iterator ni = gi->second.begin(); ni != gi->second.end(); ni++)
            {
                int to = number(*ni);
                adjacency_list[from].push_back(to);
            }
        }
        colors.resize(number_of_nodes) ;
        dfs_low.resize(number_of_nodes) ;
        in_stack.resize(number_of_nodes) ;
        dfs_num.resize(number_of_nodes) ;
        std::fill(colors.begin(),colors.end(),dfs_white) ;
        std::fill(dfs_num.begin(),dfs_num.end(),-1) ;
        std::fill(dfs_low.begin(),dfs_low.end(),-1) ;
        std::fill(in_stack.begin(),in_stack.end(),false) ;
        for(int i=0; i<number_of_nodes;i++)
        {
        	dfs(-1,i) ;
        }
        for(vector<vector<char> >::iterator ri = result.begin(); ri != result.end(); ri++)
        {
          sort(ri->begin(),ri->end());
        }
        sort(result.begin(),result.end());
        if(test != 1)
        {
            cout << endl;
        }
        for(vector<vector<char> >::iterator ri = result.begin(); ri != result.end(); ri++)
        {
            for(unsigned si = 0; si < ri->size(); si++)
            {
                if(si != 0)
                {
                    cout << " ";
                }
                cout << (*ri)[si];
            }
            cout << endl;
        }
    }
  return 0 ;
}

