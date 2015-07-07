#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <sstream>
#include <queue>
using namespace std ;
std::vector<int> best;
std::vector<int> taken;
int max1= 0 ;
int colored = 0 ;
class vertex
{
public:
	int id ;
	int color ;
	bool counted;
	std::vector<vertex*> adj;
	vertex(int id):id(id)
	{
		counted = false ;
		color = 0 ;
	}
};

typedef map<int,vertex*> vmap ;
typedef pair<int,vertex*> vpair ;
queue<vertex*> q ;

class graph
{
public:
	vertex* addvertex(int v) ;
	void addedge(int begin,int end) ;
	vertex* getvertex(int v) ;
	vmap vertexmap ;
	std::vector<vertex*> allvertexes;
	void apply(int n) ;
};

vertex* graph::addvertex(int v)
{
	vertex* newv= new vertex(v) ;
	allvertexes.push_back(newv) ;
	vertexmap.insert(vpair(v,newv)) ;
	return newv ;
}

void graph::addedge(int begin,int end)
{
	vertex* v= getvertex(begin) ;
	vertex* w= getvertex(end) ;
	v->adj.push_back(w) ;
	w->adj.push_back(v) ;
}

vertex* graph::getvertex(int v)
{
	vmap::iterator it = vertexmap.find(v) ;
	if(it==vertexmap.end())
	{
		return addvertex(v) ;
	} 
	return (*it).second ;
}
void graph::apply(int n)
{
	if(n==allvertexes.size())
	{
      if(colored > max1) 
      {
			max1 = colored;
			best.clear();
			for (int i = 0; i < taken.size(); i++)
				best.push_back(taken[i]);
		}
	}
	else
	{
		allvertexes[n]->color = 1 ;
		colored+=1 ;
		taken.push_back(allvertexes[n]->id) ;
		bool good = true ;
		for(int i=0;i<allvertexes[n]->adj.size();i++)
		{
			if(allvertexes[n]->adj[i]->color==1)
			{
				good = false ;
				break ;
			}
		}
		if(good)
		  apply(n+1);
		colored -= 1;
		taken.pop_back();
		allvertexes[n]->color = 2;
		apply(n+1);
	}
}

int main()
{
	int m,n,k,temp1,temp2 ,flag=0,count1,count2;
	cin >> m ;
	for(int i=0;i<m;i++)
	{
		best.clear() ;
		taken.clear() ;
		max1 = 0 ;
		colored = 0 ;
		int flag = 1 ;
		graph* g = new graph() ;
        cin >> n >> k ;
        for(int j=0;j<k;j++)
        {
            cin >> temp1 >> temp2 ;
            g->addedge(temp1,temp2) ;
        }
       /* for(std::vector<vertex*>::iterator it=g->allvertexes.begin();it != g->allvertexes.end();it++)
        {
        	cout << (*it)->id << endl ;
        }*/
       // sort(g->allvertexes.begin(),g->allvertexes.end(),comp);
       // cout << g->allvertexes[1]->id ;
       // for(int f=0;f<n;f++)
        //{
        //	sort(g->allvertexes[f]->adj.begin(),g->allvertexes[f]->adj.end()) ;
        //}
       /* for(int f=0;f<n;f++)
        {
        	for(std::vector<vertex*> ::iterator y=g->allvertexes[f]->adj.begin();y!= g->allvertexes[f]->adj.end();++y)
        	{
        		cout << (*y)->id << " " ;
        	}
        	cout << endl ;
        }*/
        
    /*    for(int k=0;k<n;k++)
        {
        	count1 = 1 ;
        	count2 = 0 ;
        	max1 = -1 ;
            q.push(g->allvertexes[k]) ;
            g->allvertexes[k]->color = 1 ;  
            while(!q.empty())
            {
            	vertex* arb = q.front() ;
            //	cout << q.front()->id << endl ;
            	q.pop() ;
            	for(int j=0;j<arb->adj.size();j++)
            	{
            		if(arb->adj[j]->color==0 && flag==0)
            		{
                      arb->adj[j]->color = 2 ;
                      count2++ ;
                      q.push(arb->adj[j]) ;
                      flag = 1  ;
                    }
                    else if(arb->adj[j]->color==0 && flag==1)
                    {
                    	arb->adj[j]->color = 1 ;
                    	count1++ ;
                        q.push(arb->adj[j]) ;
                        flag = 0 ;
                    }
            	}
            }
            if(count1>max1)
            {
            	result.clear() ;
            	max1 = count1 ; 
            	for(int l=0;l<g->allvertexes.size();l++)
            	{
                   if(g->allvertexes[l]->color==1)
                   {
                          result.push_back(g->allvertexes[l]->id) ;
                   }
            	}
            }
            for(std::vector<vertex*>::iterator it=g->allvertexes.begin();it != g->allvertexes.end();it++)
            {
        	   (*it)->color = 0  ;
            }
            // cout << count1 << " "<< count2 << endl ; 
        }*/
        g->apply(0) ;
        cout << max1  << endl ;
        for (int r= 0; r < best.size(); r++) {
			if (r > 0) cout << " ";
			cout << best[r];
		}
        cout << endl ;
        delete g ;
	}
	return 0 ;
}