#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
int main()
{
	int n ,i,size,j;
	cin >> n ;
	string v;
	stack<char> s ;
	getline(cin,v) ;
	for(i=0;i<n;i++)
	{
		//v.clear() ;
          getline(cin,v) ;
          size = v.size() ;
         // cout << size ;
             for(j=0;j<size;j++)
             {
          	   if(v[j]=='(' || v[j]=='[')
          	   {
          		  s.push(v[j]) ;
          	   }
          	   else if(v[j]==')')
          	   {
          	   	 if(s.size()==0 || s.top()!='(')
          	   		break ;
          	     else
          	   		s.pop() ;
          	   }
          	   else if(v[j]==']')
          	   {
          	   	 if(s.size()==0 || s.top()!='[')
          	   		 break ;
          	      else
          	   		s.pop() ;
          	   }
             }
            if(j<size || s.size()>0)
            {
                 cout << "No" << endl ;
            }
            else
            {
            	cout << "Yes" << endl ;
            }
            while(s.size()>0)
            {
           	 s.pop() ;
            }
	}
	return 0 ;
}