#include "smart_array.hpp"
#include <iostream>
#include <cassert>

Smart_array::Smart_array(int size, int def_value)
        :m_size(size), m_def_value(def_value)
{
        m_array = new int [m_size];
        for (int i = 0; i < m_size; ++i) {
                *(m_array + i) = m_def_value;
        }
}

Smart_array::Smart_array(const Smart_array& array)
{
        m_size = array.m_size;
        m_def_value = array.m_def_value;
        int* m_array[m_size];
        for (int i =0; i < m_size; ++i) {
                *m_array[i] = array.m_array[i];
        }
}

Smart_array::~Smart_array()
{
	delete[] m_array;
}

void Smart_array::set(int index, int value)
{
        if ( index < 0 && index >= m_size ) {
		std::cout << "The index is out of range." << std::endl;
	}
        m_array[index] = value;
}

int Smart_array::get_size ()
{
        return m_size;
}

int Smart_array::get_value(int index)
{
         if ( index < 0 && index >= m_size ) {
                std::cout << "The index is out of range." << std::endl;
        }
        return m_array[index];
}

void Smart_array::quick_sort(int left, int right)
{
	int middle = (left + right) / 2;
	int pivot = m_array[middle];
	int i = left;
	int j = right;
	while (i <= j) {
		while (m_array[i] < pivot) {
			++i;
		}
		while (m_array[j] > pivot) {
			--j;
		}
		if ( i <= j ) {
			int tmp = m_array[i];
			m_array[i] = m_array[j];
			m_array[j] = tmp;
			++i;
			--j;
		}
	}
	if ( left < j ) {
            quick_sort(left, j);

	}
      	if ( i < right ) {
	    quick_sort(i, right);
	}
}

Smart_array& Smart_array:: operator = (const Smart_array& other) 
{
	if ( this != other ) {
		if ( other.m_size != m_size ) {
			delete [] m_array;
			m_size = other.m_size;
			m_array = new int[m_size];
		}
		for (int i = 0; i < m_size; ++i) {
                        m_array[i] = other.m_array[i];
		} 
	}
	return *this;	
}

int& Smart_array:: operator [] (int index)
{
	return m_array[index];
}

void Smart_array::resize(int size)
{
        int* new_array;
        if ( m_size == size ) {

                return;
        } else if ( m_size > size ) {
                m_size = size;
                new_array = new int[m_size];
                for (int i = 0; i < size; ++i) {
                        new_array[i] = m_array[i];
                }
        } else {
                new_array = new int[size];
                for (int i = 0; i < m_size; ++i) {
                        new_array[i] = m_array[i];
                }
                for (int i = m_size; i < size; ++i) {
                        new_array[i] = m_def_value;
                }
                m_size = size;
             }
        delete [] m_array;
        m_array = new_array;
}

 std::ostream& operator << (std::ostream &out, const Smart_array  &sa) 
{
	for (int i = 0; i < sa.m_size; ++i) {
		out << sa.m_array [i];
	}
	return out;
}

void Smart_array::print()
{
        for (int i = 0; i < m_size; ++i) {
                std::cout << m_array[i] << " ";
                std::cout << std::endl;
        }
}
