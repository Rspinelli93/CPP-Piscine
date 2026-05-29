#include "iter.hpp"

int main( void )
{
	int arr[7];

	for(int i = 0; i < 7; i++)
		arr[i] = i + 1;
	
	::iter(arr, 7, ::print<int>);
	
	std::cout << "\n";

	const int *c_arr = const_cast<const int*>(arr);

	::iter(c_arr, 7, ::print<const int>);
}