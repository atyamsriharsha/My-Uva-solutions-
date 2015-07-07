/************************************************************
   Author : atyam
************************************************************/

#include <bits/stdc++.h>
using namespace std ;

typedef long long ll ;
typedef pair<int,int> pii ;
typedef vector<pii> vii ;

int main()
{
   int length,ref =1,v ;
   std::vector<int> value;
   std::vector<int> table;
   std::vector<int> active_sequence_ends;
   std::vector<int> active_sequence_indices;
   while(cin>>v)
   {
       value.push_back(v) ;
   }
   length = value.size() ;
   table.resize(length) ;
   table[0] = -1 ;
   active_sequence_ends.push_back(value[0]);
   active_sequence_indices.push_back(0) ;
   for(int i=1;i<length;i++)
   {
      int index= lower_bound(active_sequence_ends.begin(),active_sequence_ends.end(),value[i]) -active_sequence_ends.begin() ;
      if(index==active_sequence_ends.size())
      {
      	table[i] = active_sequence_indices[active_sequence_indices.size()-1] ;
      	active_sequence_ends.push_back(value[i]) ;
      	active_sequence_indices.push_back(i) ;
      } 
      else
      {
      	if(index==0)
      	{
      		table[i] = -1 ;
      	}
      	else
      	{
      		table[i] = active_sequence_indices[index-1] ;
      	}
      	active_sequence_indices[index] = i ;
      	active_sequence_ends[index] = value[i] ;
      }
   }
    cout << active_sequence_ends.size() << endl;
    cout << "-" << endl;
    int index = active_sequence_indices[active_sequence_indices.size() - 1];
    list<int> result;
    while(index != -1)
    {
        result.push_front(value[index]);
        index = table[index];
    }
    for(list<int>::iterator i = result.begin(); i != result.end(); i++)
    {
        cout << *i << endl;
    }
  return 0 ;
}