#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std ;

typedef struct array
{
 public:
	string name;
	int base_address,element_size,num_dimension ;
	vector<int> lower_bounds ;
	vector<int> upper_bounds ;
	vector<int> constants ;
}array;

int main()
{
	int num_arrays,num_references,i,j,k ;
	scanf("%d%d",&num_arrays,&num_references) ;
	array *arrays = new array[num_arrays] ;
	for(i=0;i<num_arrays;i++)
	{
		cin >> arrays[i].name ;
		cin >> arrays[i].base_address ;
		cin >> arrays[i].element_size ;
		cin >> arrays[i].num_dimension ;
		for(j=0;j<arrays[i].num_dimension;j++)
		{
		   int lower_bound,upper_bound ;
		   cin >> lower_bound ;
		   cin >> upper_bound ;
		   arrays[i].lower_bounds.push_back(lower_bound) ;
		   arrays[i].upper_bounds.push_back(upper_bound) ;
		   arrays[i].constants.push_back(0) ;
		}
		arrays[i].constants.push_back(0) ;
        arrays[i].constants[arrays[i].num_dimension] = arrays[i].element_size;
        for(j = arrays[i].num_dimension -1 ;j > 0; j--)
        {
            arrays[i].constants[j] = arrays[i].constants[j+1]*(arrays[i].upper_bounds[j]-arrays[i].lower_bounds[j]+1);
        }
        arrays[i].constants[0] = arrays[i].base_address;
        for(j = 1; j <= arrays[i].num_dimension; j++)
        {
            arrays[i].constants[0] -= arrays[i].constants[j] * arrays[i].lower_bounds[j - 1];
        }
	}
	for(i=0;i<num_references; i++)
    {
        string array_name;
        cin >> array_name;
        for(j = 0; j < num_arrays; j++)
        {
            if(arrays[j].name == array_name)
            {
                cout << arrays[j].name;
                cout << "[";
                int result = arrays[j].constants[0];
                for(k = 0; k < arrays[j].num_dimension; k++)
                {
                    if (k != 0)
                    {
                        cout << ", ";
                    }
                    int reference_index;
                    cin >> reference_index;
                    cout << reference_index;
                    result += reference_index * arrays[j].constants[k + 1];
                }
                cout << "] = ";
                cout << result << endl;
            }
        }
    }
    delete[] arrays;
	return 0 ;
}
