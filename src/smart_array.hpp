#include <iostream>
/**
 *@class Smart_array
 *@brief advanced version of integer type array 
 */
class Smart_array
{
	public:
                /**
                *@name Smart_array
                *@brief constructor of Smart_array class
                *@param size is an integer type number for the size of the array
                *@param def_value is an integer type number that is used as a default value for the elements of the array
                *@return The constructor doesn't return any value.
                 */
		Smart_array(int size, int def_value);

		/**
                 *@name Smart_array
                 *@brief copy constructor of Smart_array class
                 *@param array is a Smart_array type object for copying it to this
                 *@return copy constructor doesn't return any value
                 */
                Smart_array(const Smart_array&);
                
                /**
                 *@name ~Smart_array
                 *@brief destructor of Smart_array class
                 *@return The destructor doesn't return any value.
                 */
                ~Smart_array();
                
                /**
                 *
                 *@name set
                 *@brief sets the value of an element by its index
                 *@param index is the index of the element that is being modified
                 *@param value is the new value that is being assigned to the element
                 *@return set function doesn't return any value
                 */
		void set(int index, int value);

                /**
                 *@name get_size
                 *@brief gets the size of the array
                 *@return returns integer type value
                 */
		int get_size();

                /**
                 *@name get_value
                 *@brief gets the value of an element by its index
                 *@param index is the index of the element which should be returned
                 *@return returns integer type value
                 */
		int get_value(int index);
		
                /**
                 *@name resize
                 *@brief changes the size of the array
                 *@param size is the new size of the array
                 *@return doesn't return any value
                 */
                void resize(int size);

                /**
                 *@name operator =
                 *@brief overloading the assignment operator
                 *@param other is a Smart_array type constant object
                 *@return returns Smart_array type object
                 */
		Smart_array& operator = (const Smart_array& other);

                /**
                 *@name operator []
                 *@brief overloading the [] operator
                 *@param index is the array index of the returned element
                 *@return returns an integer type value by reference
                 */
		int& operator [] (int index);
		
                /**
                 *@name quick_sort
                 *@brief sorts the array using the quick sorting algorithm
                 *@param left is the index of the first element of the array
                 *@param right is the index of the last element of the array
                 *@return doesn't return any value
                 */
                void quick_sort(int left, int right);

                /**
                 *@name print
                 *@brief prints the array of the class to console
                 *@return doesnt return any value
                 */
                void print();

                /**
                 *@name operator <<
                 *@brief overloading the << operator
                 *@param out is an ostream type variable passed by reference
                 *@param sa is a Smart_array type object passed by reference
                 *@return returns ostream type variable
                 */
		friend std::ostream& operator << (std::ostream &out, const Smart_array &sa);
	
		private:
		int m_size;
		int* m_array;
                int m_def_value;

};

