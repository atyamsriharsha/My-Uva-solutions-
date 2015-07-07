#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <queue>
using namespace std ;


class vertex
{
public:
	char id ;
	bool counted ;
	std::vector<vertex*> adj;
	vertex(char id):id(id){counted = false ;}
};

typedef map<char,vertex*> vmap ;
typedef pair<char,vertex*> vpair;
queue<vertex*> q ;

class graph
{
public:
	graph(){}
	~graph();
	vertex* addvertex(char v) ;
	void addedge(char begin,char end,bool directed) ;
	vertex* firstvertex() ;
	int countsubgraphs() ;
private:
	vertex* getvertex(char v) ;
	vmap vertexmap ;
	std::vector<vertex*> allvertexes;
};

graph::~graph()
{
	for(int i=0;i<allvertexes.size();i++)
	{
		delete allvertexes[i] ;
	}
}

vertex* graph::addvertex(char v)
{
	vertex* newv = new vertex(v) ;
	allvertexes.push_back(newv) ;
	vertexmap.insert(vpair(v,newv)) ;
	return newv ;
}

void graph::addedge(char begin,char end,bool directed=false)
{
	vertex* v = getvertex(begin) ;
	vertex* w = getvertex(end) ;
	v->adj.push_back(w) ;
	if(!directed)
	{
		w->adj.push_back(v) ;
	}
}

vertex* graph::getvertex(char v)
{
	vmap::iterator it = vertexmap.find(v) ;
	if(it == vertexmap.end())
	{
		return addvertex(v) ;
	}
	return (*it).second ;
}

vertex* graph::firstvertex()
{
	return allvertexes[0] ;
}

int graph::countsubgraphs()
{
	int sum = 0 ;
	vertex* temp ;
	for(int i=0;i<allvertexes.size();i++)
	{
		if(allvertexes[i]->counted==false)
		{
			++sum ;
			q.push(allvertexes[i]) ;
			while(!q.empty())
			{
				temp = q.front() ;
				q.pop() ;
				temp->counted = true ;
				for(int j=0;j<temp->adj.size();j++)
				{
					if(temp->adj[j]->counted == false)
					{
						temp->adj[j]->counted = true ;
						q.push(temp->adj[j]) ;
					}
				}
			}
		}
	}
	return sum ;
}

void trimspaces(string& str)
{
	size_t startpos = str.find_first_not_of(" \t") ;
	size_t endpos = str.find_last_not_of(" \t") ;
	if(( string::npos == startpos ) || ( string::npos == endpos))
    {
        str = "";
    }
    else
        str = str.substr(startpos,endpos-startpos+1);
}

int main(void)
{
	int n;
	char c, d;
	char prev = 'a';
	int counter = 0;
	string input;
	cin >> n;
	getline(cin,input);
	getline(cin,input);
	while(n--) 
	{
		counter++;
		graph* g = new graph();
		getline(cin,input);
		trimspaces(input);
		for(char i = 'A';i<=input[0];i++)
			g->addvertex(i);
		while(getline(cin,input)) 
		{
			trimspaces(input);	
			if(input.size()==0) break;
			g->addedge(input[0],input[1]);
		}
		if(counter>1) cout << endl;
		cout << g->countsubgraphs() << endl;
		delete g;
	}		
	return 0;
}