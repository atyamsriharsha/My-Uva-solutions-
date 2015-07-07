#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std ;
int count1 ;
typedef  pair<string,int>  p;
std::vector<p> v;
std::map<string,int> m;
bool thecomp(p a,p b)
{
  if(a.second == b.second)
  {
    return a.first < b.first ;
  }
  else
  {
    return a.second > b.second ;
  }
}

int main()
{
  int j ;
  string temp ;
  while(getline(cin,temp))
  {
    if(temp[0]=='0')
      break ;
    if(temp[0]=='1')
    {
      continue ;
    }
    v.clear() ;
    m.clear() ;
    count1 = 1 ;
    v.push_back(make_pair(temp,0)) ;
    while(getline(cin,temp))
    {
        if(temp[0]=='1')
          break ;
      if(temp[0]>='A' && temp[0]<='Z')
      {
        v.push_back(make_pair(temp,0)) ;
        count1++ ;
      }   
      else
      {
        int index = m[temp] ;
        if(index==0)
        {
          m[temp] = count1 ;
          v[count1-1].second++ ;
        }
        else if(index!=count1 && index>0) 
        {
          v[index-1].second-- ;
          m[temp] = -1  ;
        }
      }
    }
    sort(v.begin(),v.end(),thecomp) ;
    for(j =0 ;j< v.size();j++)
    {
      cout << v[j].first << " " << v[j].second << endl ;
    }
  }
  return 0;
}