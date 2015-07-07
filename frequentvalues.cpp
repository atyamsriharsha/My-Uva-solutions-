#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std ;
#define limit 200010 
int starting_indexes[limit],ending_indexes[limit],values[limit] ;

int getmiddle(int a,int b)
{
   return (b+a)/2 ; 
}
class node
{
public:
	node(){}
	~node(){}
	int start,end,middle ;
	int frequency ;
}nodes[limit*4];

void construct(int _start,int _end,int index)
{
   int _middle = getmiddle(_start,_end) ;
   nodes[index].start = _start ;
   nodes[index].end = _end ;
   nodes[index].middle = _middle ;
   int z = values[nodes[index].middle] ;
   if(_start==_end)
   {
      nodes[index].frequency = 1 ; 
    //  return nodes[index].frequency ;
   }
   else
   {
     construct(_start,_middle,2*index+1) ;
     construct(_middle+1,_end,2*index+2) ;
     nodes[index].frequency = max(nodes[2*index+1].frequency,nodes[2*index+2].frequency) ;
     nodes[index].frequency = max(nodes[index].frequency,min(ending_indexes[z],nodes[index].end)-max(starting_indexes[z],nodes[index].start)+1) ;
   }
  // return nodes[index].frequency ;
}

int getquery(int _start,int _end,int index)
{
  if(_start>nodes[index].end || _end < nodes[index].start)
  {
    return 0 ; 
  }
  if(_start<= nodes[index].start && _end>=nodes[index].end)
  {
     return nodes[index].frequency ; 
  } 
  int z = max(getquery(2*index+1, _start, _end), getquery(2*index+2, _start, _end));

  return max(z, min(ending_indexes[values[nodes[index].middle]], _end) - max(starting_indexes[values[nodes[index].middle]], _start) + 1);

}

int main(void)
{
   int n,q,s,e ;
   int reference = 200005 ;
   while(cin>>n)
   	{
   	  if(n==0)
   	  { 
   	     break ; 
   	  } 
      cin >> q ;
      for(int i=0;i<n;i++)
      { 
          cin >> values[i] ;
          values[i] = values[i] + 100000 ;
          if(values[i]!=reference)
          { 
            starting_indexes[values[i]]= i ; 
            ending_indexes[reference] = i- 1 ;    
          }         	
          reference = values[i] ;
      }
     ending_indexes[values[n-1]] = n-1 ;
     construct(0,n-1,0) ;
     for(int i=0;i<q;i++)
     {
         cin >> s >> e ;
         cout << getquery(--s,--e,0) << endl ;
     }
   	}

}