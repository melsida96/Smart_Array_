#include "smart_array.hpp"
#include <iostream>



int main()
{

        Smart_array array(5, 17);
        array.set(0, 2);
        array.set(1, 9);
        array.set(2, 4);
        array.set(3, 8);
        array.set(4, 3);
	Smart_array other(5, 4);
	other = array;
	std::cout << "Array:" ;
	std::cout << other << std::endl;
	other.quick_sort(0,4);
	std::cout << "Sorted array:";
	std::cout << other << std::endl;
	//std::cout << other[1];
        return 0;


}
