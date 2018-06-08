#include <smart_array.hpp>
#include <iostream>
#include <fstream>
#include <string>

std::string read ()
{
        std::ifstream stream;
        stream.open ("input.txt");
        if ( !stream ) {
                std::cerr << "Cannot find the input file.";
                std::cout << "\n";
        }
        std::string input;
        stream >> input;
        stream.close ();
        return input;
}

void write (std::string message)
{
        std::ofstream write;
        write.open ("output.txt", std::ofstream::app);
        if ( ! write.is_open() ) {
                std::cerr << "Cannot find the output file.";
                std::cout << "\n";
        }

        write << message; 
        write.close ();
}

void set_test () {
        Smart_array sa (5, 4);
        std::string input;
        input = read ();
        int a = input[0] - '0';
        int b = input[1] - '0';
        if ( sa.set (a, b) ) {
                write ("set_test passed successfully.\n");
        } else {
                write ("set_test failed.\n");
        }
}

void get_size_test ()
{
        Smart_array sa (14, 5);
        if ( sa.get_size () ) {
                std::string message = "get_size_test passed successfully.\n";
                write(message);
        } else {
                std::string message = "get_size_test failed.\n";
                write(message);
        }

}

void get_value_test ()
{
        int index = 0;
        int value = 1;
        Smart_array sa (5, value);
        if ( value == sa.get_value(index) ) {
                std::string message = "get_value_test passed successfully.\n";
                write(message);
        } else {
                std::string message = "get_value_test failed.\n";
                write(message);
        }
}

void resize_test ()
{
        Smart_array sa(8, 9);
        int size = 4;
        sa.resize(1);
        if ( size == sa.get_size() ) {
                std::string message = "resize_test passed successfully.\n";
                write(message);
        } else {
                std::string message = "resize_test failed.\n";
                write(message);
        }
}
        
int main ()
{
        set_test();
        get_size_test();
        get_value_test();
        resize_test();
        return 0;
}
