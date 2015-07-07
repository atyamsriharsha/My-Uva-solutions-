#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;
bool is_dna(string s)
{
	if(s=="A" || s=="B" || s=="C" || s=="D")
		return true ;
}
bool theTruthIsOutThere(const pair<string,string> &a, const pair<string,string> &b) 
{
    return a.first < b.first;
}

int main()
{
	int m ;
	bool blank = true ;
	std::vector<string> v;
	std::vector<string> u;
	map<string,string> vmap ;
	string temp ;
	while(cin>>m)
	{
		v.clear() ;
		u.clear() ;
		vmap.clear() ;
		if(blank!=false)
			blank = false ;
		else
			cout << endl ;
       for(int i =0;i<m;i++)
       {
       	cin >> temp ;
       	v.push_back(temp) ;
       }
       for(int i = 0;i<m;i++)
       {
       	cin >> temp ;
       	u.push_back(temp) ;
       }
       bool ok  = true ;
       while(1)
       {
       	   bool changed = false ;
           for(int i=0;i<m;i++)
           {
           	bool dna1 = is_dna(v[i]) ;
           	bool dna2 = is_dna(u[i]) ;
           	if(dna1 && dna2)
           	{
                if(u[i]!=v[i])
                {
                	ok = false ;
                	break ;
                }
           	}
           	else if(!dna1 && dna2)
           	{
               if(vmap.find(v[i])==vmap.end())
               {
               	vmap[v[i]] = u[i] ;
               	changed = true ;
               }
               else
               {
               	if(vmap[v[i]]!=u[i])
               	{
               		ok = false ;
               		break ;
               	}
               }
           	}
           	else if(dna1 && !dna2)
           	{
           	   if(vmap.find(u[i])==vmap.end())
               {
               	vmap[u[i]] = v[i] ;
               	changed = true ;
               }
               else
               {
               	if(vmap[u[i]]!=v[i])
               	{
               		ok = false ;
               		break ;
               	}
               }
           	}
           	else if(!dna1 && !dna2)
           	{
           		if(v[i]!=u[i])
           		{
           			if(vmap.find(v[i]) == vmap.end() && vmap.find(u[i]) != vmap.end()) 
           			{
                        vmap[v[i]] = vmap[u[i]];
                        changed = true;
                    } 
                    else if(vmap.find(v[i]) != vmap.end() && vmap.find(u[i]) == vmap.end()) 
                    {
                        vmap[u[i]] = vmap[v[i]];
                        changed = true;
                    }
                    else if(vmap.find(v[i]) != vmap.end() && vmap.find(u[i]) != vmap.end()) 
                    {
                        if(vmap[v[i]] != vmap[u[i]]) 
                        {
                                ok = false;
                                break;
                        }
                    }
           		}
           	}
           }
           if(!changed) break;
       }
        if(ok) 
        {
            vector<pair<string,string> >result;
            for(map<string,string>::iterator it =vmap.begin(); it!= vmap.end(); it++) 
            {
                result.push_back(make_pair(it->first,it->second));
            }
            sort(result.begin(), result.end(), theTruthIsOutThere);
            cout << "YES" << endl;
            for(int i=0; i<result.size();i++) 
            {
                cout << result[i].first << " " << result[i].second << endl;
            }
        } 
        else 
        {
            cout << "NO" << endl;
        }
	}
	return 0 ;
}