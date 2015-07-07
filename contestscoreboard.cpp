#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std ;

struct submit
{
public:
	int problem ;
	int time ;
	char result ;
};

struct team
{
public:
	int id ;
	int solved ;
	int time ;
	bool submission_made ;
	team():solved(0),time(0),submission_made(false){} 
};

bool thetruth(const team& a,const team& b)
{
	if(a.solved == b.solved)
	{
		if(a.time == b.time)
		{
			if(a.submission_made == b.submission_made)
			{
				return a.id < b.id ;
			}
			return a.submission_made ;
		}
		return a.time < b.time ;
	}
	return a.solved > b.solved ;
}

int main()
{
	int test,contestant,i,sz ;
	submit temp ;
	bool solved_already ;
	cin >> test ;
	cin.ignore(100,'\n') ;
	cin.ignore(100,'\n') ;
	while(test--)
	{
       team teams[101] ;
       std::vector<submit> contestants[101];
       for(i=0;i<101;i++)
       {
       	teams[i].id = i ;
       }
       while(cin.peek()!='\n' || cin.peek()!=-1)
       {
       	   cin >> contestant >> temp.problem >> temp.time >> temp.result ;
       	   cin.ignore(100,'\n') ;
       	   teams[contestant].submission_made = true ;
       	   if(temp.result=='C')
       	   {
       		    solved_already = false ;
       		    for(i=0,sz = contestants[contestant].size();i<sz ;i++)
       		    {
       			  if(contestants[contestant][i].problem == temp.problem && contestants[contestant][i].result == 'C') 
       			  {
                     solved_already = true;
                     break;
                  }
       		    }
       		    if(!solved_already)
       		    {
       		    	teams[contestant].time += temp.time;
                    teams[contestant].solved += 1;
                    for (int i = 0, sz = contestants[contestant].size(); i < sz; i++) 
                    {
                      if(contestants[contestant][i].problem == temp.problem && contestants[contestant][i].result == 'I') 
                      {
                           teams[contestant].time += 20;
                       }
                   }
       		    }
       	   }
       	    contestants[contestant].push_back(temp);
       }
       cin.ignore(100,'\n');
       sort(teams, teams + 101, thetruth);
       for(int i = 0; i < 101; i++) 
       {
          if(teams[i].submission_made == false)
            break;
           cout << teams[i].id << " " << teams[i].solved << " " << teams[i].time << endl;
       }
       if(test)
        cout << endl;
	}
	return 0 ;
}
