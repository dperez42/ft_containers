 //clang++ -Werror -Wall -Wextra -fsanitize=address mainVectorStack.cpp
#include <iostream>
#include <string>
#include <deque>
# include <sys/stat.h> 
# include <sys/types.h>
# include <iostream>
# include <string>
# include <fstream>
# include <vector>
#include <stack>
# include <fstream>
# include <string>
#include <map>
#include "vector.hpp"
#include "stack.hpp"
# define NORMAL "\033[0;37m"
# define UNDERLINE "\033[4m"
# define BOLD_RED "\033[1;31m"
# define BOLD_GREEN "\033[1;32m"

using namespace ft;

template <class T>
void show_stlvector(std::vector<T> &stl_vector)
{
    typename std::vector<T>::const_iterator stl_it;
    
    std::cout << "[";
    for (stl_it = stl_vector.begin();  stl_it != stl_vector.end(); stl_it++)
    {
        std::cout << *stl_it;
        if (stl_it + 1 != stl_vector.end())
            std::cout << ", ";
    }
    std::cout << "] ";
    std::cout<< "Empty       : " << stl_vector.empty();
    std::cout << " Size        : " << stl_vector.size();
    std::cout << " Max size    : " << stl_vector.max_size();
    std::cout << " Capacity    : " << stl_vector.capacity();
    std::cout << std::endl;
}
template <class T>
void show_ftvector(ft::vector<T> &ft_vector)
{
    typename ft::vector<T>::iterator it;
    it = ft_vector.begin();
    unsigned long i;
    std::cout << "[";
    for (i = 0; i < ft_vector.size(); i++)
    {
        std::cout << ft_vector.at(i);
        if (i + 1 < ft_vector.size())
            std::cout << ", ";
    }
        std::cout << "] ";
    std::cout<< "Empty       : " << ft_vector.empty();
    std::cout << " Size        : " << ft_vector.size();
    std::cout << " Max size    : " << ft_vector.max_size();
    std::cout << " Capacity    : " << ft_vector.capacity();
    std::cout << std::endl;
    /*
    for (stl_it = ft_vector.begin();  stl_it != ft_vector.end(); stl_it++)
    {
        std::cout << *stl_it;
        if (stl_it + 1 != ft_vector.end())
            std::cout << ", ";
    }
    */
}

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

template <class T>
std::string equal(const T& t1, const T& t2)
{
    return (t1 == t2 ? "✔" : "✘");
}

template <class T>
bool equalbool(const T& t1, const T& t2)
{
    return (t1 == t2 ? true : false);
}

bool printBoolResult(std::fstream& fs, bool stl_bool, bool ft_bool)
{
    fs << "\nBool result : \n";
    fs << " - STL : " << (stl_bool ? "true" : "false") << std::endl;
    fs << " - FT  : " << (ft_bool ? "true" : "false") << std::endl;

    return (stl_bool == ft_bool);
}

template <class T> std::string equalContent(
    const std::vector<T> & stl_vector,
    const ft::vector<T> & ft_vector
)
{
    typename ft::vector<T>::const_iterator ft_it;
    typename std::vector<T>::const_iterator stl_it;
    if (ft_vector.size() != stl_vector.size())
        return ("✘");
    stl_it = stl_vector.begin();
    for(ft_it = ft_vector.begin(); ft_it != ft_vector.end(); ft_it++)
    {
        if (*ft_it != *stl_it)
            return ("✘");
        stl_it++;
    }
    return ("✔");
}

template <class T> bool printVectorAttributes(
    std::fstream& fs,
    std::vector<T>& stl_vector,
    ft::vector<T>& ft_vector
)
{
    /* STL Values */
    std::string stl_empty = ((stl_vector.empty() == 1) ? "true" : "false");
    size_t stl_size = stl_vector.size();
    size_t stl_max_size = stl_vector.max_size();
    size_t stl_capacity = stl_vector.capacity();

    /* FT Values */
    std::string ft_empty = ((ft_vector.empty() == 1) ? "true" : "false");
    size_t ft_size = ft_vector.size();
    size_t ft_max_size = ft_vector.max_size();
    size_t ft_capacity = ft_vector.capacity();

    /* FT Result compare values */
    bool empty = equalbool(ft_empty, stl_empty);
    bool size = equalbool(ft_size, stl_size);
    bool max_size = equalbool(ft_max_size, stl_max_size);
    bool capacity = equalbool(ft_capacity, stl_capacity);
    std::string content = equalContent(stl_vector, ft_vector);
    
    fs << "\n══════════════════════════════════════════════════════════════\n";
    fs << "Vectors attributes : \n";
    fs << "STL : \n";
    fs << "Empty       : " << stl_empty  << std::endl;
    fs << "Size        : " << stl_size  << std::endl;
    fs << "Max size    : " << stl_max_size  << std::endl;
    fs << "Capacity    : " << stl_capacity  << std::endl;
    fs << "Content     : [";
    
    typename std::vector<T>::const_iterator stl_it;
    for (stl_it = stl_vector.begin();  stl_it != stl_vector.end(); stl_it++)
    {
        fs << *stl_it;
        if (stl_it + 1 != stl_vector.end())
            fs << ", ";
    }
    fs << "]\n";

    fs << std::endl;

    fs << "FT : \n";
    fs << "Empty    [" << equal(ft_empty, stl_empty) << "]: " << ft_empty  << std::endl;
    fs << "Size     [" << equal(ft_size, stl_size) << "]: " << ft_size  << std::endl;
    fs << "Max size [" << equal(ft_max_size, stl_max_size) << "]: " << ft_max_size  << std::endl;
    fs << "Capacity [" << equal(ft_capacity, stl_capacity) << "]: " << ft_capacity  << std::endl;

    fs << "Content  [" << content << "]: [";

    typename ft::vector<T>::const_iterator ft_it;
    for(ft_it = ft_vector.begin(); ft_it != ft_vector.end(); ft_it++)
    {
        fs << *ft_it;
        if (ft_it + 1 != ft_vector.end())
            fs << ", ";
    }
    fs << "]\n";

    fs << "══════════════════════════════════════════════════════════════\n";

    /* Error case */
    if (empty == false)
        return (false);
    else if (size == false)
        return (false);
    else if (max_size == false)
        return (false);
    else if (capacity == false)
        return (false);
    else if (content == "✘")
        return (false);
    return (true);
}

template <class T> std::string equalStackContent(
    std::stack<T> stl_stack,
    ft::stack<T> ft_stack
)
{
    while (42)
    {
        if (stl_stack.size() == 0 || ft_stack.size() == 0)
            break;
        if (ft_stack.top() != stl_stack.top())
            return ("✘");
        ft_stack.pop();
        stl_stack.pop();
    }
    return ("✔");
}

template <class T> bool printStackAttributes( std::fstream& fs, std::stack<T>& stl_stack, ft::stack<T>& ft_stack)
{
    
    /* STL Values */
    std::string stl_empty = ((stl_stack.empty() == 1) ? "true" : "false");
    size_t stl_size = stl_stack.size();

    /* FT Values */
    std::string ft_empty = ((ft_stack.empty() == 1) ? "true" : "false");
    size_t ft_size = ft_stack.size();
    
    /* FT Result compare values */
    bool empty = equalbool(ft_empty, stl_empty);
    bool size = equalbool(ft_size, stl_size);
    //std::string content = equalContent(stl_stack, ft_stack);
    
    fs << "\n══════════════════════════════════════════════════════════════\n";
    fs << "stacks attributes : \n";
    fs << "STL : \n";
    fs << "Empty       : " << stl_empty  << std::endl;
    fs << "Size        : " << stl_size  << std::endl;
    fs << "Content     : [";
    while (!stl_stack.empty())
        {
            fs << stl_stack.top();
            if (stl_stack.size() != 0)
                fs << ", ";
            stl_stack.pop();
        }
    fs << "]\n";
    fs << std::endl;

    fs << "FT : \n";
    fs << "Empty    [" << equal(ft_empty, stl_empty) << "]: " << ft_empty  << std::endl;
    fs << "Size     [" << equal(ft_size, stl_size) << "]: " << ft_size  << std::endl;
    fs << "Content  [" ;
    while (!ft_stack.empty())
            {
                fs << ft_stack.top();
                if (ft_stack.size() != 0)
                    fs << ", ";
                ft_stack.pop();
            }
    fs << "]\n";
    fs << std::endl;
    fs << "══════════════════════════════════════════════════════════════\n";

    /* Error case */
    if (empty == false)
        return (false);
    else if (size == false)
        return (false);
    //else if (content == "✘")
    //    return (false);
    return (true);
    return (true);
}



// t1 == stl
// t2 == ft
template<class T>
static bool printSingleValue(std::fstream& fs, const T& t1, const T& t2)
{
    fs << "\n══════════════════════════════════════════════════════════════\n";
    fs << "Value from :\n";
    fs << "STL    : " << t1 << "\n";
    fs << "FT  [" << equal(t1, t2) << "]: " << t2 << "\n";
    fs << "══════════════════════════════════════════════════════════════\n";
    return (t1 == t2 ? true : false);
}


struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int main()
{
    /*
    ft::vector<int> first(10,3);
    show_ftvector(first);
    ft::vector<int> copy = first;
    show_ftvector(copy);
    show_ftvector(first);
    first.erase(first.begin());
    show_ftvector(first);
    return 0;
    */

    /*VECTOR*/
    {
        ft::vector<int> vi;

        std::cout << BOLD_RED << "VECTORS :\n" << NORMAL << NORMAL ;

        mkdir("./tester/vectors_output", 0777);
        
        std::fstream fs;

        /* Constructors */
        std::cout << "Constructors : \n" ;
        /* Default constructor */
        {
            std::vector<int> stl_default_vector;
            ft::vector<int> ft_default_vector; 
            
            fs.open("./tester/vectors_output/constructor_default", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << "ft::vector<int> ft_default_vector:" ;
            std::cout << ((printVectorAttributes(fs, stl_default_vector, ft_default_vector) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_default_vector;\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_default_vector;\n";
            fs.close();
            
        }
        /* Fill constructor */
        {
            std::vector<int> stl_fill_vector(0);
            ft::vector<int> ft_fill_vector(0);

            fs.open("./tester/vectors_output/constructor_fill_empty", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "ft::vector<int> ft_fill_vector(0):" ;
            std::cout << ((printVectorAttributes(fs, stl_fill_vector, ft_fill_vector) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_fill_vector(0);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_fill_vector(0);\n";
            fs.close();
        }
        /* Fill constructor n */
        {
            std::vector<int> stl_fill_vector_sized(19);
            ft::vector<int> ft_fill_vector_sized(19);

            fs.open("./tester/vectors_output/constructor_fill_sized", std::fstream::in | std::fstream::out | std::fstream::trunc);
             std::cout << "constructor_fill_sized:" ;
            std::cout << ((printVectorAttributes(fs, stl_fill_vector_sized, ft_fill_vector_sized) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_fill_vector_sized(19);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_fill_vector_sized(19);\n";
            fs.close();

        }
        {
            std::vector<int> stl_fill_vector_sized(19, 42);
            ft::vector<int> ft_fill_vector_sized(19, 42);

            fs.open("./tester/vectors_output/constructor_fill_sized_valued", std::fstream::in | std::fstream::out | std::fstream::trunc);
             std::cout << "constructor_fill_sized_valued:" ;
            std::cout << ((printVectorAttributes(fs, stl_fill_vector_sized, ft_fill_vector_sized) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_fill_vector_sized(19, 42);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_fill_vector_sized(19, 42);\n";
            fs.close();
        }
        /* Default constructor pointer */
        {
            std::vector<int> *stl_pointer_default_vector = new std::vector<int>;
            ft::vector<int> *ft_pointer_default_vector = new ft::vector<int>;

            fs.open("./tester/vectors_output/constructor_default_pointer", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "ft::vector<int> *ft_pointer_default_vector = new ft::vector<int>:" ;
            std::cout << ((printVectorAttributes(fs, *stl_pointer_default_vector, *ft_pointer_default_vector) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> *ft_pointer_default_vector = new ft::vector<int>;\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> *stl_pointer_default_vector = new std::vector<int>;\n";
            fs.close();

            delete stl_pointer_default_vector;
            delete ft_pointer_default_vector;
        }
        /* igual constructor pointer */
        {   
            std::vector<int> stl_default_vector(10,2);
            ft::vector<int> ft_default_vector(10,2);
            
            std::vector<int> stl_copy_vector;
            ft::vector<int> ft_copy_vector;

            stl_copy_vector = stl_default_vector;
            ft_copy_vector = ft_default_vector;

            fs.open("./tester/vectors_output/constructor=", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "ft_copy_vector = ft_default_vector:" ;
            std::cout << ((printVectorAttributes(fs, stl_copy_vector, ft_copy_vector) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> *ft_pointer_default_vector = new ft::vector<int>;\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> *stl_pointer_default_vector = new std::vector<int>;\n";
            fs.close();
        }

        /* igual constructor pointer */
        {   
            std::vector<int> stl_vector(10,3);
            ft::vector<int> ft_vector(10,3);
            //stl_vector.push_back(5);
            //ft_vector.push_back(5);

            fs.open("./tester/vectors_output/constructor_range", std::fstream::in | std::fstream::out | std::fstream::trunc);

                
            std::vector<int> stl_copy_vector(stl_vector);
            ft::vector<int> ft_copy_vector(ft_vector);

            std::cout << "ft::vector<int> ft_copy_vector(ft_vector):" ;
            std::cout << ((printVectorAttributes(fs, stl_copy_vector, ft_copy_vector) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { -89, 561, 874, 7777 , 987, -6 };\n";
            fs << "ft::vector<int>::iterator ft_iterator(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 6);\n";
            fs << "ft::vector<int> ft_copy_vector(ft_range_vector);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { -89, 561, 874, 7777 , 987, -6 };\n";
            fs << "std::vector<int>::iterator stl_iterator(&(range_array[0]));\n";
            fs << "std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 6);\n";
            fs << "std::vector<int> stl_copy_vector(stl_range_vector);\n";
            fs.close();
        }
        /* constructor_copy*/
        {
            std::vector<int> stl_range_vector(10,3);
            ft::vector<int> ft_range_vector(10,3);
            stl_range_vector.push_back(5);
            ft_range_vector.push_back(5);
            stl_range_vector.push_back(9);
            ft_range_vector.push_back(9);

            fs.open("./tester/vectors_output/constructor_copy", std::fstream::in | std::fstream::out | std::fstream::trunc);

            
            std::vector<int> stl_copy_vector(stl_range_vector.begin(), stl_range_vector.begin()+11);
            ft::vector<int> ft_copy_vector(ft_range_vector.begin(), ft_range_vector.begin()+11);

            std::cout << "ft::vector<int> ft_copy_vector(ft_range_vector.begin(), ft_range_vector.begin()+11):" ;
            std::cout << ((printVectorAttributes(fs, stl_copy_vector, ft_copy_vector) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { -89, 561, 874, 7777 , 987, -6 };\n";
            fs << "ft::vector<int>::iterator ft_iterator(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 6);\n";
            fs << "ft::vector<int> ft_copy_vector(ft_range_vector);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { -89, 561, 874, 7777 , 987, -6 };\n";
            fs << "std::vector<int>::iterator stl_iterator(&(range_array[0]));\n";
            fs << "std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 6);\n";
            fs << "std::vector<int> stl_copy_vector(stl_range_vector);\n";
            fs.close();
        }
    
        std::cout << "\n";
        std::cout << "Assign : \n";
        /* Assign operator */
        {
            std::vector<int> stl_range_vector(10,3);
            ft::vector<int> ft_range_vector(10,3);

            stl_range_vector.push_back(5);
            ft_range_vector.push_back(5);
            stl_range_vector.push_back(9);
            ft_range_vector.push_back(9);

            fs.open("./tester/vectors_output/operator_assign=", std::fstream::in | std::fstream::out | std::fstream::trunc);

            std::vector<int> stl_assign_vector = stl_range_vector;
            ft::vector<int> ft_assign_vector = ft_range_vector;

            std::cout << "ft::vector<int> ft_assign_vector = ft_range_vector:" ;
            std::cout << ((printVectorAttributes(fs, stl_assign_vector, ft_assign_vector) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { 74, 569, -8822, 8515, 5 };\n";
            fs << "ft::vector<int>::iterator ft_iterator(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 5);\n";
            fs << "ft::vector<int> ft_assign_vector = ft_range_vector;\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { 74, 569, -8822, 8515, 5 };\n";
            fs << "std::vector<int>::iterator stl_iterator(&(range_array[0]));\n";
            fs << "std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 5);\n";
            fs << "std::vector<int> stl_assign_vector = stl_range_vector;\n";
            fs.close();
        }
        //return(0);
        std::cout << "\n";
        std::cout << "Iterator : \n";
        /* Iterator begin() */
        {
            std::vector<int> stl_range_vector(10,3);
            ft::vector<int> ft_range_vector(10,3);
            stl_range_vector.push_back(5);
            ft_range_vector.push_back(5);
            stl_range_vector.push_back(9);
            ft_range_vector.push_back(9);
            stl_range_vector.push_back(99);
            ft_range_vector.push_back(99);

            fs.open("./tester/vectors_output/iterator_begin", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            int from_stl = *(stl_range_vector.begin());
            int from_ft = *(ft_range_vector.begin());
            
            std::cout << "int from_ft = *(ft_range_vector.begin()):" ;
            std::cout << ((printSingleValue(fs, from_stl, from_ft) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { 87, 92, -5, 8984, 96 };\n";
            fs << "ft::vector<int>::iterator ft_iterator(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 5);\n";
            fs << "int from_ft = *(ft_range_vector.begin());\n";
            fs << "    ^^^^^^^\n";
            fs << "    Compared value";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { 87, 92, -5, 8984, 96 };\n";
            fs << "std::vector<int>::iterator stl_iterator(&(range_array[0]));\n";
            fs << "std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 5);\n";
            fs << "int from_stl = *(stl_range_vector.begin());\n";
            fs << "    ^^^^^^^^\n";
            fs << "    Compared value";
            fs.close();
        }

        /* Const iterator begin() */
        {
            std::vector<int> stl_range_vector(10,3);
            ft::vector<int> ft_range_vector(10,3);
            stl_range_vector.push_back(5);
            ft_range_vector.push_back(5);
            stl_range_vector.push_back(9);
            ft_range_vector.push_back(9);
            stl_range_vector.push_back(99);
            ft_range_vector.push_back(99);
        
            fs.open("./tester/vectors_output/iterator_const_begin", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::vector<int>::const_iterator stl_const_it = stl_range_vector.begin();
            ft::vector<int>::const_iterator ft_const_it = ft_range_vector.begin();
            const int from_stl = *(stl_const_it);
            const int from_ft = *(ft_const_it);
             std::cout << "const int from_ft = *(ft_const_it):" ;
            std::cout << ((printSingleValue(fs, from_stl, from_ft) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { 87, 92, -5, 8984, 96 };\n";
            fs << "ft::vector<int>::const_iterator ft_iterator(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 5);\n";
            fs << "ft::vector<int>::const_iterator ft_const_it = ft_range_vector.begin();\n";
            fs << "int from_ft = *(ft_const_it);\n";
            fs << "    ^^^^^^^\n";
            fs << "    Compared value";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { 87, 92, -5, 8984, 96 };\n";
            fs << "std::vector<int>::const_iterator stl_iterator(&(range_array[0]));\n";
            fs << "std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 5);\n";
            fs << "std::vector<int>::const_iterator stl_const_it = stl_range_vector.begin();\n";
            fs << "int from_stl = *(stl_const_it);\n";
            fs << "    ^^^^^^^^\n";
            fs << "    Compared value";
            fs.close();
        }

        /* Iterator end() */
        {
            std::vector<int> stl_range_vector(10,3);
            ft::vector<int> ft_range_vector(10,3);
            stl_range_vector.push_back(5);
            ft_range_vector.push_back(5);
            stl_range_vector.push_back(9);
            ft_range_vector.push_back(9);
            stl_range_vector.push_back(99);
            ft_range_vector.push_back(99);
        
            fs.open("./tester/vectors_output/iterator_end", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            int from_stl = *(stl_range_vector.end() - 1);
            int from_ft = *(ft_range_vector.end() - 1);
            std::cout << "int from_ft = *(ft_range_vector.end() - 1);:" ;
            std::cout << ((printSingleValue(fs, from_stl, from_ft) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { 48, 967, 52, -45, -9, 956551, 44};\n";
            fs << "ft::vector<int>::iterator ft_iterator(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 7);\n";
            fs << "int from_ft = *(ft_range_vector.end() - 1);\n";
            fs << "    ^^^^^^^\n";
            fs << "    Compared value";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { 48, 967, 52, -45, -9, 956551, 44};\n";
            fs << "std::vector<int>::iterator stl_iterator(&(range_array[0]));\n";
            fs << "std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 7);\n";
            fs << "int from_stl = *(stl_range_vector.end() - 1);\n";
            fs << "    ^^^^^^^^\n";
            fs << "    Compared value";
            fs.close();
        }

        /* Const iterator end() */
        {
            std::vector<int> stl_range_vector(10,3);
            ft::vector<int> ft_range_vector(10,3);
            stl_range_vector.push_back(5);
            ft_range_vector.push_back(5);
            stl_range_vector.push_back(9);
            ft_range_vector.push_back(9);
            stl_range_vector.push_back(99);
            ft_range_vector.push_back(99);
        
            fs.open("./tester/vectors_output/iterator_const_end", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::vector<int>::const_iterator stl_const_it = stl_range_vector.end() - 1;
            ft::vector<int>::const_iterator ft_const_it = ft_range_vector.end() - 1;
            const int from_stl = *(stl_const_it);
            const int from_ft = *(ft_const_it);
            
            std::cout << "const int from_ft = *(ft_const_it);:" ;
            std::cout << ((printSingleValue(fs, from_stl, from_ft) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { 95, 89, -6121, 48, 5 };\n";
            fs << "ft::vector<int>::const_iterator ft_iterator(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 5);\n";
            fs << "std::vector<int>::const_iterator stl_const_it = stl_range_vector.end() - 1;\n";
            fs << "int from_ft = *(ft_const_it);\n";
            fs << "    ^^^^^^^\n";
            fs << "    Compared value";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { 95, 89, -6121, 48, 5 };\n";
            fs << "std::vector<int>::const_iterator stl_iterator(&(range_array[0]));\n";
            fs << "std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 5);\n";
            fs << "ft::vector<int>::const_iterator ft_const_it = ft_range_vector.end() - 1;\n";
            fs << "int from_stl = *(stl_const_it);\n";
            fs << "    ^^^^^^^^\n";
            fs << "    Compared value";
            fs.close();
        }

        /* Iterator rbegin() */
        {
            std::vector<int> stl_range_vector(10,3);
            ft::vector<int> ft_range_vector(10,3);
            stl_range_vector.push_back(5);
            ft_range_vector.push_back(5);
            stl_range_vector.push_back(9);
            ft_range_vector.push_back(9);
            stl_range_vector.push_back(99);
            ft_range_vector.push_back(99);
        
            fs.open("./tester/vectors_output/iterator_reverse_begin", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            int from_stl = *(stl_range_vector.rbegin());
            int from_ft = *(ft_range_vector.rbegin());

            std::cout << "int from_ft = *(ft_range_vector.rbegin()):" ;
            std::cout << ((printSingleValue(fs, from_stl, from_ft) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {250, -1200, -98657, 2, 34};\n";
            fs << "ft::vector<int>::iterator ft_iterator(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 5);\n";
            fs << "int from_ft = *(ft_range_vector.rbegin());\n";
            fs << "    ^^^^^^^\n";
            fs << "    Compared value";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {250, -1200, -98657, 2, 34};\n";
            fs << "std::vector<int>::iterator stl_iterator(&(range_array[0]));\n";
            fs << "std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 5);\n";
            fs << "int from_stl = *(stl_range_vector.rbegin());\n";
            fs << "    ^^^^^^^^\n";
            fs << "    Compared value";
            fs.close();
        }

        /* Const iterator rbegin() */
        {
            std::vector<int> stl_range_vector(10,3);
            ft::vector<int> ft_range_vector(10,3);
            stl_range_vector.push_back(5);
            ft_range_vector.push_back(5);
            stl_range_vector.push_back(9);
            ft_range_vector.push_back(9);
            stl_range_vector.push_back(99);
            ft_range_vector.push_back(99);
        
            fs.open("./tester/vectors_output/iterator_const_reverse_begin", std::fstream::in | std::fstream::out | std::fstream::trunc);
            

            ft::vector<int>::const_reverse_iterator ft_const_it = ft_range_vector.rbegin();
            int from_stl = *(stl_range_vector.rbegin());
            int from_ft = *(ft_range_vector.rbegin());
            std::cout << "const int from_ft = *(ft_range_vector.rbegin()):" ;    
            std::cout << ((printSingleValue(fs, from_stl, from_ft) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { 958, -561, 54, 789, -8};\n";
            fs << "ft::vector<int>::const_iterator ft_iterator(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 5);\n";
            fs << "ft::vector<int>::const_reverse_iterator ft_const_it = ft_range_vector.rbegin();\n";
            fs << "int from_ft = *(ft_const_it);\n";
            fs << "    ^^^^^^^\n";
            fs << "    Compared value";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { 958, -561, 54, 789, -8};\n";
            fs << "std::vector<int>::const_iterator stl_iterator(&(range_array[0]));\n";
            fs << "std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 5);\n";
            fs << "std::vector<int>::const_reverse_iterator stl_const_it = stl_range_vector.rbegin();\n";
            fs << "int from_stl = *(stl_const_it);\n";
            fs << "    ^^^^^^^^\n";
            fs << "    Compared value";
            fs.close();
        }

        /* Iterator rend() */
        {
            std::vector<int> stl_range_vector(10,3);
            ft::vector<int> ft_range_vector(10,3);
            stl_range_vector.push_back(5);
            ft_range_vector.push_back(5);
            stl_range_vector.push_back(9);
            ft_range_vector.push_back(9);
            stl_range_vector.push_back(99);
            ft_range_vector.push_back(99);
        
            fs.open("./tester/vectors_output/iterator_reverse_end", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            int from_stl = *(stl_range_vector.rend() - 1);
            int from_ft = *(ft_range_vector.rend() - 1);

            std::cout << "int from_ft = *(ft_range_vector.rend() - 1):" ; 
            std::cout << ((printSingleValue(fs, from_stl, from_ft) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {78, -951, 562, 8, 745, 51236, 6987};\n";
            fs << "ft::vector<int>::iterator ft_iterator(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 7);\n";
            fs << "int from_ft = *(ft_range_vector.rend() - 1);\n";
            fs << "    ^^^^^^^\n";
            fs << "    Compared value";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {78, -951, 562, 8, 745, 51236, 6987};\n";
            fs << "std::vector<int>::iterator stl_iterator(&(range_array[0]));\n";
            fs << "std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 7);\n";
            fs << "int from_stl = *(stl_range_vector.rend() - 1);\n";
            fs << "    ^^^^^^^^\n";
            fs << "    Compared value";
            fs.close();
        }

        /* Const iterator rend() */
        {
            std::vector<int> stl_range_vector(10,3);
            ft::vector<int> ft_range_vector(10,3);
            stl_range_vector.push_back(5);
            ft_range_vector.push_back(5);
            stl_range_vector.push_back(9);
            ft_range_vector.push_back(9);
            stl_range_vector.push_back(99);
            ft_range_vector.push_back(99);
        
            fs.open("./tester/vectors_output/iterator_const_reverse_end", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            
            ft::vector<int>::const_reverse_iterator ft_const_it = ft_range_vector.rend() - 1;
            const int from_stl = *(stl_range_vector.rend() - 1);
            const int from_ft = *(ft_range_vector.rend() - 1);
            
            std::cout << "const int from_ft = *(ft_range_vector.rend() - 1):" ;
            std::cout << ((printSingleValue(fs, from_stl, from_ft) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { 8, -5615, 412, 89, 475};\n";
            fs << "ft::vector<int>::const_iterator ft_iterator(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_range_vector(ft_iterator, ft_iterator + 5);\n";
            fs << "std::vector<int>::const_reverse_iterator stl_const_it = stl_range_vector.rend() - 1;\n";
            fs << "int from_ft = *(ft_const_it);\n";
            fs << "    ^^^^^^^\n";
            fs << "    Compared value";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { 8, -5615, 412, 89, 475};\n";
            fs << "std::vector<int>::const_iterator stl_iterator(&(range_array[0]));\n";
            fs << "std::vector<int> stl_range_vector(stl_iterator, stl_iterator + 5);\n";
            fs << "ft::vector<int>::const_reverse_iterator ft_const_it = ft_range_vector.rend() - 1;\n";
            fs << "int from_stl = *(stl_const_it);\n";
            fs << "    ^^^^^^^^\n";
            fs << "    Compared value";
            fs.close();
        }

        std::cout << "\n";
        std::cout << "Capacity : \n";

        /* Size small */
        {
            std::vector<int> stl_filled(20);
            ft::vector<int> ft_filled(20);

            fs.open("./tester/vectors_output/size_small", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << "ft::vector<int> ft_filled(20):" ;
            std::cout << ((printVectorAttributes(fs, stl_filled, ft_filled) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_filled(20);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_filled(20);\n";
            fs.close();
        }

        /* Size big */
        {
            std::vector<int> stl_filled(100000);
            ft::vector<int> ft_filled(100000);

            fs.open("./tester/vectors_output/size_big", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "ft::vector<int> ft_filled(100000):" ;
            std::cout << ((printVectorAttributes(fs, stl_filled, ft_filled) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_filled(1000000);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_filled(1000000);\n";
            fs.close();
        }

        /* Maximum size */
        {
            std::vector<int> stl_base;
            ft::vector<int> ft_base;

            fs.open("./tester/vectors_output/maximum_size", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "ft::vector<int> ft_base:" ;
            std::cout << ((printVectorAttributes(fs, stl_base, ft_base) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_base;\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_base;\n";
            fs.close();    
        }

        /* Resize extension */
        {
            std::vector<int> stl_base(40);
            ft::vector<int> ft_base(40);

            stl_base.resize(81);
            ft_base.resize(81);

            fs.open("./tester/vectors_output/resize_extension", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "resize ft_base.resize(81):" ;
            std::cout << ((printVectorAttributes(fs, stl_base, ft_base) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_base(40);\n";
            fs << "ft_base.resize(85);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_base(40);\n";
            fs << "stl_base.resize(85);\n";
            fs.close();
            //show_stlvector(stl_base);
            //show_ftvector(ft_base);
            //std::cout << std::endl;

        }

        /* Resize reduction */
        {
            std::vector<int> stl_base(40);
            ft::vector<int> ft_base(40);

            stl_base.resize(3);
            ft_base.resize(3);

            std::cout << "reduccion ft_base.resize(3):" ;
            fs.open("./tester/vectors_output/resize_reduction", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << ((printVectorAttributes(fs, stl_base, ft_base) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_base(40);\n";
            fs << "ft_base.resize(3);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_base(40);\n";
            fs << "stl_base.resize(3);\n";
            fs.close();    
        }
        /* Capacity short */
        {
            std::vector<int> stl_base(40);
            ft::vector<int> ft_base(40);

            stl_base.push_back(42);
            ft_base.push_back(42);
            stl_base.push_back(69);
            ft_base.push_back(69);

            fs.open("./tester/vectors_output/capacity_short", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "capacity_short:" ;
            std::cout << ((printVectorAttributes(fs, stl_base, ft_base) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_base(40);\n";
            fs << "ft_base.push_back(42);\n";
            fs << "ft_base.push_back(69);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_base(40);\n";
            fs << "stl_base.push_back(42);\n";
            fs << "stl_base.push_back(69);\n";
            fs.close();    
        }
        
        /* Capacity big */
        {
            std::vector<int> stl_base(40000);
            ft::vector<int> ft_base(40000);

            fs.open("./tester/vectors_output/capacity_big", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << "capacity_big:" ;
            std::cout << ((printVectorAttributes(fs, stl_base, ft_base) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_base(40000);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_base(40000);\n";
            fs.close();
        }

        /* Empty true */
        {
            std::vector<int> stl_base;
            ft::vector<int> ft_base;

            fs.open("./tester/vectors_output/empty_true", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << "empty_true:" ;
            std::cout << ((printVectorAttributes(fs, stl_base, ft_base) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_base;\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_base;\n";
            fs.close();
        }

        /* Empty false */
        {
            std::vector<int> stl_base(5);
            ft::vector<int> ft_base(5);

            fs.open("./tester/vectors_output/empty_false", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << "empty_false:" ;
            std::cout << ((printVectorAttributes(fs, stl_base, ft_base) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_base(5);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_base(5);\n";
            fs.close();
        }

        /* Empty after resize */
        {
            std::vector<int> stl_base(5);
            ft::vector<int> ft_base(5);

            stl_base.resize(0);
            ft_base.resize(0);

            fs.open("./tester/vectors_output/empty_after_resize", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << "empty_after_resize:" ;
            std::cout << ((printVectorAttributes(fs, stl_base, ft_base) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_base(5);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_base(5);\n";
            fs << "stl_base.resize(0);\n";
            fs.close();
        }

        /* Reserve normal */
        {
            std::vector<int> stl_base;
            ft::vector<int> ft_base;

            stl_base.reserve(100);
            ft_base.reserve(100);
            
            stl_base.push_back(42);
            ft_base.push_back(42);
            
            fs.open("./tester/vectors_output/reserve", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "Reserve normal,ft_base.reserve(100):" ;
            std::cout << ((printVectorAttributes(fs, stl_base, ft_base) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_base;\n";
            fs << "ft_base.reserve(100);\n";
            fs << "ft_base.push_back(42);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_base;\n";
            fs << "stl_base.reserve(100);\n";
            fs << "stl_base.push_back(42);\n";
            fs.close();
        }
        std::cout << "\n";
        std::cout << "Element access : \n";

        /* Operator [] */
        {
            std::vector<int> stl_base(40);
            ft::vector<int> ft_base(40);

            stl_base.push_back(42);
            ft_base.push_back(42);
            stl_base.push_back(69);
            ft_base.push_back(69);

            fs.open("./tester/vectors_output/operator_at", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "Operator []:" ;
            std::cout << ((printSingleValue(fs, stl_base[1], ft_base[1]) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { 8, -5615, 412, 89, 475};\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_operator(ft_iterator_beg, ft_iterator_beg + 5);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = { 8, -5615, 412, 89, 475};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));\n";
            fs << "std::vector<int> stl_operator(stl_iterator_beg, stl_iterator_beg + 5);\n";
            fs.close();
        }

        /* Const Operator [] */
        {
            std::vector<int> stl_base(40);
            ft::vector<int> ft_base(40);

            stl_base.push_back(42);
            ft_base.push_back(42);
            stl_base.push_back(69);
            ft_base.push_back(69);

            const int stl_const = stl_base[1];
            const int ft_const = ft_base[1];
            
            fs.open("./tester/vectors_output/operator_at_const", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << "Const Operator []:" ;
            std::cout << ((printSingleValue(fs, stl_const, ft_const) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {8, -98, 541, 53361, 9};\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_operator(ft_iterator_beg, ft_iterator_beg + 5);\n";
            fs << "const int stl_const = stl_operator[1];\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {8, -98, 541, 53361, 9};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));\n";
            fs << "std::vector<int> stl_operator(stl_iterator_beg, stl_iterator_beg + 5);\n";
            fs << "const int stl_const = stl_operator[1];\n";
            fs.close();
        }


        /* Normal at() */
        {
            std::vector<int> stl_base(40);
            ft::vector<int> ft_base(40);

            stl_base.push_back(42);
            ft_base.push_back(42);
            stl_base.push_back(69);
            ft_base.push_back(69);

            fs.open("./tester/vectors_output/at", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "Normal at():" ;
            std::cout << ((printSingleValue(fs, stl_base.at(3), ft_base.at(3)) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {8, -986, -8, 66, 7};\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_at(ft_iterator_beg, ft_iterator_beg + 5);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {8, -986, -8, 66, 7};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));\n";
            fs << "std::vector<int> stl_at(stl_iterator_beg, stl_iterator_beg + 5);\n";
            fs.close();
        }  

        /* Const at() */
        {
            std::vector<int> stl_base(40);
            ft::vector<int> ft_base(40);

            stl_base.push_back(42);
            ft_base.push_back(42);
            stl_base.push_back(69);
            ft_base.push_back(69);

            const int stl_const = stl_base.at(4);
            const int ft_const = ft_base.at(4);
            
            fs.open("./tester/vectors_output/const_at", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "Const at():" ;
            std::cout << ((printSingleValue(fs, stl_const, ft_const) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {845, -9, 47, 4, -825};\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_at(ft_iterator_beg, ft_iterator_beg + 5);\n";
            fs << "const int stl_const = stl_at.at(4);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {845, -9, 47, 4, -825};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));\n";
            fs << "std::vector<int> stl_at(stl_iterator_beg, stl_iterator_beg + 5);\n";
            fs << "const int ft_const = ft_at.at(4);\n";
            fs.close();
        }

        /* Normal front() */
        {
            std::vector<int> stl_base(40);
            ft::vector<int> ft_base(40);

            stl_base.push_back(42);
            ft_base.push_back(42);
            stl_base.push_back(69);
            ft_base.push_back(69);

            fs.open("./tester/vectors_output/front", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "Normal front():" ;
            std::cout << ((printSingleValue(fs, stl_base.front(), ft_base.front()) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {2, 0, 982, -9, 87};\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_front(ft_iterator_beg, ft_iterator_beg + 5);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {2, 0, 982, -9, 87};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));\n";
            fs << "std::vector<int> stl_front(stl_iterator_beg, stl_iterator_beg + 5);\n";
            fs.close();
        }

        /* Const front() */
        {
            std::vector<int> stl_base(40);
            ft::vector<int> ft_base(40);

            stl_base.push_back(42);
            ft_base.push_back(42);
            stl_base.push_back(69);
            ft_base.push_back(69);

            const int stl_const = stl_base.front();
            const int ft_const = ft_base.front();

            fs.open("./tester/vectors_output/front_const", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "Const front():" ;
            std::cout << ((printSingleValue(fs, stl_const, ft_const) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {5589, -97, -98, -63, 8};\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_front(ft_iterator_beg, ft_iterator_beg + 5);\n";
            fs << "const int ft_const = ft_front.front();\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {5589, -97, -98, -63, 8};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));\n";
            fs << "std::vector<int> stl_front(stl_iterator_beg, stl_iterator_beg + 5);\n";
            fs << "const int stl_const = stl_front.front();\n";
            fs.close();
        }

        /* Normal back() */
        {
                std::vector<int> stl_base(10,3);
            ft::vector<int> ft_base(10,3);

            stl_base.push_back(42);
            ft_base.push_back(42);
            stl_base.push_back(69);
            ft_base.push_back(69);


            fs.open("./tester/vectors_output/back", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "Normal back():" ;
            std::cout << ((printSingleValue(fs, stl_base.back(), ft_base.back()) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {2, 0, 982, -9, 87};\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_back(ft_iterator_beg, ft_iterator_beg + 5);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {2, 0, 982, -9, 87};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));\n";
            fs << "std::vector<int> stl_back(stl_iterator_beg, stl_iterator_beg + 5);\n";
            fs.close();
        }
        
        /* Const back() */
        {
            std::vector<int> stl_base(10,3);
            ft::vector<int> ft_base(10,3);

            stl_base.push_back(42);
            ft_base.push_back(42);
            stl_base.push_back(69);
            ft_base.push_back(69);


            const int stl_const = stl_base.back();
            const int ft_const = ft_base.back();

            fs.open("./tester/vectors_output/back_const", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "Const back():" ;
            std::cout << ((printSingleValue(fs, stl_const, ft_const) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {5589, -97, -98, -63, 8};\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_back(ft_iterator_beg, ft_iterator_beg + 5);\n";
            fs << "const int ft_const = ft_back.back();\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {5589, -97, -98, -63, 8};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));\n";
            fs << "std::vector<int> stl_back(stl_iterator_beg, stl_iterator_beg + 5);\n";
            fs << "const int stl_const = stl_back.back();\n";
            fs.close();
        }

        std::cout << "\n";
        std::cout << "Modifiers :\n";
        //--------------------------------------------------------------//
        /* Assign range */
        {
            std::vector<int> stl_base(10,3);
            ft::vector<int> ft_base(10,3);
            
            stl_base.push_back(42);
            ft_base.push_back(42);
            stl_base.push_back(69);
            ft_base.push_back(69);
            
            std::vector<int>::iterator stl_iterator_beg(stl_base.begin());
            ft::vector<int>::iterator ft_iterator_beg(ft_base.begin());

            std::vector<int> stl_assign;
            ft::vector<int> ft_assign;

            /*
            show_stlvector(stl_base);
            show_ftvector(ft_base);
            std::cout<<std::endl;
            */
            stl_assign.assign(stl_iterator_beg, stl_iterator_beg + 6);
            ft_assign.assign(ft_iterator_beg, ft_iterator_beg + 6);

            fs.open("./tester/vectors_output/assign_range", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << "ft_assign.assign(ft_iterator_beg, ft_iterator_beg + 6):" ;
            std::cout << ((printVectorAttributes(fs, stl_assign, ft_assign) == true) ?  "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {84, 522, -654, -7623, 4};\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_assign;\n";
            fs << "ft_assign.assign(ft_iterator_beg, ft_iterator_beg + 5);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {84, 522, -654, -7623, 4};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));\n";
            fs << "std::vector<int> stl_assign;\n";
            fs << "stl_assign.assign(stl_iterator_beg, stl_iterator_beg + 5);\n";
            fs.close();
            //show_stlvector(stl_assign);
            //show_ftvector(ft_assign);
            //std::cout<<std::endl;
        }

        /* Assign range replace */
        {
            std::vector<int> stl_base(10,3);
            ft::vector<int> ft_base(10,3);

            stl_base.push_back(42);
            ft_base.push_back(42);
            stl_base.push_back(69);
            ft_base.push_back(69);

            std::vector<int>::iterator stl_iterator_beg(stl_base.begin());
            ft::vector<int>::iterator ft_iterator_beg(ft_base.begin());

            std::vector<int> stl_assign(42);
            ft::vector<int> ft_assign(42);

            stl_assign.assign(stl_iterator_beg, stl_iterator_beg + 5);
            ft_assign.assign(ft_iterator_beg, ft_iterator_beg + 5);

            fs.open("./tester/vectors_output/assign_range_replace", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "replace ft_assign.assign(ft_iterator_beg, ft_iterator_beg + 5):" ;
            std::cout << ((printVectorAttributes(fs, stl_assign, ft_assign) == true) ?  "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {547, 98, -6, 0, 47};\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_assign;\n";
            fs << "ft_assign.assign(ft_iterator_beg, ft_iterator_beg + 5);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {547, 98, -6, 0, 47};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));\n";
            fs << "std::vector<int> stl_assign;\n";
            fs << "stl_assign.assign(stl_iterator_beg, stl_iterator_beg + 5);\n";
            fs.close();
        }
        
        /* Assign fill */
        {
            std::vector<int> stl_assign_fill;
            ft::vector<int> ft_assign_fill;

            stl_assign_fill.assign(87, 42);
            ft_assign_fill.assign(87, 42);
            
            fs.open("./tester/vectors_output/assign_fill", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << "assign_fill:" ;
            std::cout << ((printVectorAttributes(fs, stl_assign_fill, ft_assign_fill) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_assign_fill;\n";
            fs << "ft_assign_fill.assign(87, 42);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";    
            fs << "std::vector<int> stl_assign_fill;\n";
            fs << "stl_assign_fill.assign(87, 42);\n";
            fs.close();
        }
        

        /* Assign fill Replace */
        {
            std::vector<int> stl_assign_fill(42);
            ft::vector<int> ft_assign_fill(42);

            stl_assign_fill.assign(420, 14);
            ft_assign_fill.assign(420, 14);
            
            fs.open("./tester/vectors_output/assign_fill_replace", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "Assign fill Replace ft_assign_fill.assign(420, 14):" ;
            std::cout << ((printVectorAttributes(fs, stl_assign_fill, ft_assign_fill) == true) ?  "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_assign_fill;\n";
            fs << "ft_assign_fill.assign(87, 42);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";    
            fs << "std::vector<int> stl_assign_fill;\n";
            fs << "stl_assign_fill.assign(87, 42);\n";
            fs.close();
        }
       
        /* Push back empty */
        {
            std::vector<int> stl_pushback;
            ft::vector<int> ft_pushback;

            stl_pushback.push_back(42);
            ft_pushback.push_back(42);

            fs.open("./tester/vectors_output/push_back_empty", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "Push back empty ft_pushback.push_back(42):" ;
            std::cout << ((printVectorAttributes(fs, stl_pushback, ft_pushback) == true) ?  "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_pushback;\n";
            fs << "ft_pushback.push_back(42);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_pushback;\n";
            fs << "stl_pushback.push_back(42);\n";
            fs.close();
        }
        
        /* Push back */
        {
            std::vector<int> stl_pushback(7);
            ft::vector<int> ft_pushback(7);

            stl_pushback.push_back(42);
            ft_pushback.push_back(42);

            fs.open("./tester/vectors_output/push_back", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "Push back normal ft_pushback.push_back(42):" ;
            std::cout << ((printVectorAttributes(fs, stl_pushback, ft_pushback) == true) ?  "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::vector<int> ft_pushback(7);\n";
            fs << "ft_pushback.push_back(42);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::vector<int> stl_pushback(7);\n";
            fs << "stl_pushback.push_back(42);\n";
            fs.close();
        }

        /* Pop back */
        {
            std::vector<int> stl_base(10);
            ft::vector<int> ft_base(10);

            stl_base.push_back(42);
            ft_base.push_back(42);
            stl_base.push_back(69);
            ft_base.push_back(69);

            std::vector<int>::iterator stl_iterator_beg(stl_base.begin());
            ft::vector<int>::iterator ft_iterator_beg(ft_base.begin());

            std::vector<int> stl_assign(42);
            ft::vector<int> ft_assign(42);

            stl_assign.assign(stl_iterator_beg, stl_iterator_beg + 5);
            ft_assign.assign(ft_iterator_beg, ft_iterator_beg + 5);

            stl_assign.pop_back();
            ft_assign.pop_back();
            
            fs.open("./tester/vectors_output/pop_back", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "Pop Back normal ft_assign.pop_back():" ;
            std::cout << ((printVectorAttributes(fs, stl_assign, ft_assign) == true) ?  "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {547, 98, -6, 0, 47};\n";
            fs << "ft::vector<int> ft_popback(ft_iterator_beg, ft_iterator_beg + 5);\n";
            fs << "ft_popback.pop_back();\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {547, 98, -6, 0, 47};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));\n";
            fs << "stl_popback.pop_back();\n";
            fs.close();
        }

        /* Insert single element */
        
        {
            std::vector<int> stl_base(10,3);
            ft::vector<int> ft_base(10,3);
            std::vector<int> stl_insert;
            ft::vector<int> ft_insert;
            
            stl_base.push_back(42);
            ft_base.push_back(42);
            stl_base.push_back(69);
            ft_base.push_back(69);

            stl_base.insert(stl_base.begin() , 9999);
            ft_base.insert(ft_base.begin() , 9999);

            fs.open("./tester/vectors_output/insert_single", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "Insert Single ft_base.insert(ft_base.begin() + 2, 9999):" ;
            std::cout << ((printVectorAttributes(fs, stl_insert, ft_insert) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {478, 87, -85, 44, 7};\n";
            fs << "ft::vector<int> ft_insert(ft_iterator_beg, ft_iterator_beg + 5);\n";
            fs << "ft_insert.pop_back();\n";
            fs << "ft_insert.insert(ft_insert.begin() + 2, 9999);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {478, 87, -85, 44, 7};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));\n";
            fs << "stl_insert.insert(stl_insert.begin() + 2, 9999);\n";
            fs.close();
        }
        

        /* Insert fill */
        
        {
            std::vector<int> stl_range_vector(10,3);
            ft::vector<int> ft_range_vector(10,3);
            stl_range_vector.push_back(5);
            ft_range_vector.push_back(5);
            stl_range_vector.push_back(9);
            ft_range_vector.push_back(9);
            stl_range_vector.push_back(99);
            ft_range_vector.push_back(99);

            stl_range_vector.insert(stl_range_vector.begin()+2, 6, 4269);
            ft_range_vector.insert(ft_range_vector.begin()+2, 6, 4269);


            fs.open("./tester/vectors_output/insert_fill", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "Insert fill ft_range_vector.insert(ft_range_vector.begin()+2, 6, 4269):" ;
            std::cout << ((printVectorAttributes(fs, stl_range_vector, ft_range_vector) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {47, 152, -325, 9, 14444};\n";
            fs << "ft::vector<int> ft_insert(ft_iterator_beg, ft_iterator_beg + 5);\n";
            fs << "ft_insert.insert(ft_insert.begin() + 2, 6, 4269);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {47, 152, -325, 9, 14444};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));\n";
            fs << "stl_insert.insert(stl_insert.begin() + 2, 6, 4269);\n";
            fs.close();
        }
  

        /* Insert range */
        {
            std::vector<int> stl_range_vector(10,3);
            ft::vector<int> ft_range_vector(10,3);
            stl_range_vector.push_back(5);
            ft_range_vector.push_back(5);
            stl_range_vector.push_back(9);
            ft_range_vector.push_back(9);
            stl_range_vector.push_back(99);
            ft_range_vector.push_back(99);

            std::vector<int> stl_insert(4);
            ft::vector<int> ft_insert(4);

            stl_insert.insert(stl_insert.end(), stl_range_vector.begin(), stl_range_vector.begin() + 5);
            ft_insert.insert(ft_insert.end(), ft_range_vector.begin(), ft_range_vector.begin() + 5);

            fs.open("./tester/vectors_output/insert_range", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "Insert range ft_insert.insert(ft_insert.end(), ft_range_vector.begin(), ft_range_vector.begin() + 5):" ;
            std::cout << ((printVectorAttributes(fs, stl_insert, ft_insert) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {47, 152, -325, 9, 14444};\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_insert(4);\n";
            fs << "ft_insert.insert(ft_insert.end(), ft_iterator_beg, ft_iterator_beg + 5);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {47, 152, -325, 9, 14444};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));\n";
            fs << "std::vector<int> stl_insert(4);\n";
            fs << "stl_insert.insert(stl_insert.end(), stl_iterator_beg, stl_iterator_beg + 5);\n";
            fs.close();
        }
          
        /* Erase single element */
        {
        std::vector<int> stl_range_vector(10,3);
            ft::vector<int> ft_range_vector(10,3);
            stl_range_vector.push_back(5);
            ft_range_vector.push_back(5);
            stl_range_vector.push_back(9);
            ft_range_vector.push_back(9);
            stl_range_vector.push_back(99);
            ft_range_vector.push_back(99);

            stl_range_vector.erase(stl_range_vector.begin() + 2);
            ft_range_vector.erase(ft_range_vector.begin() + 2);
            
            fs.open("./tester/vectors_output/erase_single", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "Erase single element ft_range_vector.erase(ft_range_vector.begin() + 2):" ;
            std::cout << ((printVectorAttributes(fs, stl_range_vector, ft_range_vector) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {47, 152, -325, 9, 14444};\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_erase(ft_iterator_beg, ft_iterator_beg + 5);\n";
            fs << "ft_erase.erase(ft_erase.begin());\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {47, 152, -325, 9, 14444};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));\n";
            fs << "std::vector<int> stl_erase(stl_iterator_beg, stl_iterator_beg + 5);\n";
            fs << "stl_erase.erase(stl_erase.begin());\n";
            fs.close();
        }
        /* Erase range */
        {
        std::vector<int> stl_range_vector(10,3);
            ft::vector<int> ft_range_vector(10,3);
            stl_range_vector.push_back(5);
            ft_range_vector.push_back(5);
            stl_range_vector.push_back(9);
            ft_range_vector.push_back(9);
            stl_range_vector.push_back(99);
            ft_range_vector.push_back(99);

            stl_range_vector.erase(stl_range_vector.begin() + 1, stl_range_vector.begin() + 3);
            ft_range_vector.erase(ft_range_vector.begin() + 1,ft_range_vector.begin() + 3);

            fs.open("./tester/vectors_output/erase_range", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "Erase range ft_range_vector.erase(ft_range_vector.begin() + 1,ft_range_vector.begin() + 3):" ;
            std::cout << ((printVectorAttributes(fs, stl_range_vector, ft_range_vector) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {1458, -98, 745, 62, 9};\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_erase(ft_iterator_beg, ft_iterator_beg + 5);\n";
            fs << "ft_erase.erase(ft_erase.begin() + 1, ft_erase.end() - 2);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {1458, -98, 745, 62, 9};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));\n";
            fs << "std::vector<int> stl_erase(stl_iterator_beg, stl_iterator_beg + 5);\n";
            fs << "stl_erase.erase(stl_erase.begin() + 1, stl_erase.end() - 2);\n";
            fs.close();
        }

        /* Swap */     
        {
            std::vector<int> stl_one(10,3);
            ft::vector<int> ft_one(10,3);
            std::vector<int> stl_two(10,5);
            ft::vector<int> ft_two(10,5);

            stl_one.swap(stl_two);
            ft_one.swap(ft_two);

            fs.open("./tester/vectors_output/swap_member", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "Swap ft_one.swap(ft_two):" ;
            std::cout << ((printVectorAttributes(fs, stl_one, ft_one) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << ((printVectorAttributes(fs, stl_two, ft_two) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {1458, -98, 745, 62, 9};\n";
            fs << "int range_array_two[] = {478, 87, -15, 44, 7};       \n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "ft::vector<int> ft_swap_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);\n";
            fs << "ft::vector<int> ft_swap_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);\n";
            fs << "ft_swap_one.swap(ft_swap_two);\n";

            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {1458, -98, 745, 62, 9};\n";
            fs << "int range_array_two[] = {478, 87, -15, 44, 7};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "std::vector<int> stl_swap_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);\n";
            fs << "std::vector<int> stl_swap_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);\n";
            fs << "stl_swap_one.swap(stl_swap_two);\n";
            fs.close();
        }
        
        /* Clear */
        {
            std::vector<int> stl_clear(10,3);
            ft::vector<int> ft_clear(10,3);

            stl_clear.clear();
            ft_clear.clear();
            
            fs.open("./tester/vectors_output/clear", std::fstream::in | std::fstream::out | std::fstream::trunc);
            
            std::cout << "ft_clear.clear():" ;
            std::cout << ((printVectorAttributes(fs, stl_clear, ft_clear) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {-455, 2, 1347, 75, 945};\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg(&(range_array[0]));\n";
            fs << "ft::vector<int> ft_clear(ft_iterator_beg, ft_iterator_beg + 5);\n";
            fs << "ft_clear.clear();\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array[] = {-455, 2, 1347, 75, 945};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg(&(range_array[0]));\n";
            fs << "std::vector<int> stl_clear(stl_iterator_beg, stl_iterator_beg + 5);\n";
            fs << "stl_clear.clear();\n";
            fs.close();
        }

        std::cout << "\n";
        std::cout << "Non member function overloads : ";
        /* RL = Relation operator */

        /* RL '==' true */
        {
            std::vector<int> stl_one(10,3);
            ft::vector<int> ft_one(10,3);
            std::vector<int> stl_two(10,3);
            ft::vector<int> ft_two(10,3);

            fs.open("./tester/vectors_output/operator_equal_true", std::fstream::in | std::fstream::out | std::fstream::trunc);
            printVectorAttributes(fs, stl_one, ft_one);
            printVectorAttributes(fs, stl_two, ft_two);

            std::cout << "RL '==' true :" ;
            std::cout << ((printBoolResult(fs, (stl_one == stl_two), (ft_one == ft_two))) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {1458, -98, 745, 62, 9};\n";
            fs << "int range_array_two[] = {1458, -98, 745, 62, 9};       \n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "ft::vector<int> ft_equal_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);\n";
            fs << "ft::vector<int> ft_equal_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);\n";

            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {1458, -98, 745, 62, 9};\n";
            fs << "int range_array_two[] = {1458, -98, 745, 62, 9};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "std::vector<int> stl_equal_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);\n";
            fs << "std::vector<int> stl_equal_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);\n";
            fs.close();
        }

        /* RL '==' false */
        {
            std::vector<int> stl_equal_one(10,3);
            ft::vector<int> ft_equal_one(10,5);
            std::vector<int> stl_equal_two(10,3);
            ft::vector<int> ft_equal_two(10,5);

            fs.open("./tester/vectors_output/operator_equal_false", std::fstream::in | std::fstream::out | std::fstream::trunc);
            printVectorAttributes(fs, stl_equal_one, ft_equal_one);
            printVectorAttributes(fs, stl_equal_two, ft_equal_two);
            std::cout << "RL '==' false :" ;
            std::cout << ((printBoolResult(fs, (stl_equal_one == stl_equal_two), (ft_equal_one == ft_equal_two))) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 335, 5, 0, -54};\n";
            fs << "int range_array_two[] = {1458, -98, 745, 62, 9};       \n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "ft::vector<int> ft_equal_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);\n";
            fs << "ft::vector<int> ft_equal_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);\n";

            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 335, 5, 0, -54};\n";
            fs << "int range_array_two[] = {1458, -98, 745, 62, 9};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "std::vector<int> stl_equal_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);\n";
            fs << "std::vector<int> stl_equal_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);\n";
            fs.close();
        }
            /* RL '!=' true */
        {
            std::vector<int> stl_operator_one(10,3);
            ft::vector<int> ft_operator_one(10,5);
            std::vector<int> stl_operator_two(10,3);
            ft::vector<int> ft_operator_two(10,5);

            fs.open("./tester/vectors_output/operator_not_equal_true", std::fstream::in | std::fstream::out | std::fstream::trunc);
            printVectorAttributes(fs, stl_operator_one, ft_operator_one);
            printVectorAttributes(fs, stl_operator_two, ft_operator_two);

            std::cout << "RL '!=' true :" ;
            std::cout << ((printBoolResult(fs, (stl_operator_one != stl_operator_two), (ft_operator_one != ft_operator_two))) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 335, 5, 0, -54};\n";
            fs << "int range_array_two[] = {1458, -98, 745, 62, 9};       \n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "ft::vector<int> ft_operator_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);\n";
            fs << "ft::vector<int> ft_operator_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);\n";

            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 335, 5, 0, -54};\n";
            fs << "int range_array_two[] = {1458, -98, 745, 62, 9};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "std::vector<int> stl_operator_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);\n";
            fs << "std::vector<int> stl_operator_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);\n";
            fs.close();
        }

        /* RL '!=' false */
        {
            std::vector<int> stl_operator_one(10,3);
            ft::vector<int> ft_operator_one(10,3);
            std::vector<int> stl_operator_two(10,3);
            ft::vector<int> ft_operator_two(10,3);

            fs.open("./tester/vectors_output/operator_not_equal_false", std::fstream::in | std::fstream::out | std::fstream::trunc);
            printVectorAttributes(fs, stl_operator_one, ft_operator_one);
            printVectorAttributes(fs, stl_operator_two, ft_operator_two);
            std::cout << "RL '!=' false :" ;
            std::cout << ((printBoolResult(fs, (stl_operator_one != stl_operator_two), (ft_operator_one != ft_operator_two))) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 335, 5, 0, -54};\n";
            fs << "int range_array_two[] = {144, 335, 5, 0, -54};       \n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "ft::vector<int> ft_operator_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);\n";
            fs << "ft::vector<int> ft_operator_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);\n";

            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 335, 5, 0, -54};\n";
            fs << "int range_array_two[] = {144, 335, 5, 0, -54};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "std::vector<int> stl_operator_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);\n";
            fs << "std::vector<int> stl_operator_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);\n";
            fs.close();
        }
        /* RL '<' true */
        {
        std::vector<int> stl_operator_one(10,3);
            ft::vector<int> ft_operator_one(100,3);
            std::vector<int> stl_operator_two(10,3);
            ft::vector<int> ft_operator_two(100,3);

            fs.open("./tester/vectors_output/operator_inferior_true", std::fstream::in | std::fstream::out | std::fstream::trunc);
            printVectorAttributes(fs, stl_operator_one, ft_operator_one);
            printVectorAttributes(fs, stl_operator_two, ft_operator_two);
            std::cout << "RL '<' true :" ;
            std::cout << ((printBoolResult(fs, (stl_operator_one < stl_operator_two), (ft_operator_one < ft_operator_two))) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 335, 1, -98, 5};\n";
            fs << "int range_array_two[] = {144, 335, 5, 0, -54};       \n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "ft::vector<int> ft_operator_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);\n";
            fs << "ft::vector<int> ft_operator_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);\n";

            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 335, 1, -98, 5};\n";
            fs << "int range_array_two[] = {144, 335, 5, 0, -54};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "std::vector<int> stl_operator_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);\n";
            fs << "std::vector<int> stl_operator_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);\n";
            fs.close();
        }

        /* RL '<' false */
        {
        std::vector<int> stl_operator_one(10,3);
            ft::vector<int> ft_operator_one(100,3);
            std::vector<int> stl_operator_two(10,3);
            ft::vector<int> ft_operator_two(100,3);
            fs.open("./tester/vectors_output/operator_inferior_false", std::fstream::in | std::fstream::out | std::fstream::trunc);
            printVectorAttributes(fs, stl_operator_one, ft_operator_one);
            printVectorAttributes(fs, stl_operator_two, ft_operator_two);
            std::cout << "RL '<' false :" ;
            std::cout << ((printBoolResult(fs, (stl_operator_one < stl_operator_two), (ft_operator_one < ft_operator_two))) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {6780, 335, 1, -98, 5};\n";
            fs << "int range_array_two[] = {144, 335, 5, 0, -54};       \n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "ft::vector<int> ft_operator_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);\n";
            fs << "ft::vector<int> ft_operator_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);\n";

            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {6780, 335, 1, -98, 5};\n";
            fs << "int range_array_two[] = {144, 335, 5, 0, -54};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "std::vector<int> stl_operator_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);\n";
            fs << "std::vector<int> stl_operator_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);\n";
            fs.close();
        }


        /* RL '<=' true */
        {
            std::vector<int> stl_operator_one(10,3);
            ft::vector<int> ft_operator_one(100,5);
            std::vector<int> stl_operator_two(10,3);
            ft::vector<int> ft_operator_two(100,5);     

            fs.open("./tester/vectors_output/operator_inf_or_equal_true", std::fstream::in | std::fstream::out | std::fstream::trunc);
            printVectorAttributes(fs, stl_operator_one, ft_operator_one);
            printVectorAttributes(fs, stl_operator_two, ft_operator_two);
            std::cout << "RL '<=' true :" ;
            std::cout << ((printBoolResult(fs, (stl_operator_one <= stl_operator_two), (ft_operator_one <= ft_operator_two))) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 335, 1, -98, 5};\n";
            fs << "int range_array_two[] = {144, 335, 5, 0, -54};       \n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "ft::vector<int> ft_operator_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);\n";
            fs << "ft::vector<int> ft_operator_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);\n";

            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 335, 1, -98, 5};\n";
            fs << "int range_array_two[] = {144, 335, 5, 0, -54};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "std::vector<int> stl_operator_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);\n";
            fs << "std::vector<int> stl_operator_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);\n";
            fs.close();
        }

        /* RL '<=' true equal */
        {
            std::vector<int> stl_operator_one(10,3);
            ft::vector<int> ft_operator_one(100,3);
            std::vector<int> stl_operator_two(10,3);
            ft::vector<int> ft_operator_two(100,3);   
            
            fs.open("./tester/vectors_output/operator_inf_or_equal_true_equal", std::fstream::in | std::fstream::out | std::fstream::trunc);
            printVectorAttributes(fs, stl_operator_one, ft_operator_one);
            printVectorAttributes(fs, stl_operator_two, ft_operator_two);
            std::cout << "RL '<=' true equal :" ;
            std::cout << ((printBoolResult(fs, (stl_operator_one <= stl_operator_two), (ft_operator_one <= ft_operator_two))) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 335, 5, 0, -54};\n";
            fs << "int range_array_two[] = {144, 335, 5, 0, -54};       \n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "ft::vector<int> ft_operator_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);\n";
            fs << "ft::vector<int> ft_operator_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);\n";

            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 335, 5, 0, -54};\n";
            fs << "int range_array_two[] = {144, 335, 5, 0, -54};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "std::vector<int> stl_operator_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);\n";
            fs << "std::vector<int> stl_operator_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);\n";
            fs.close();
        }

            /* RL '<=' false */
        {
            std::vector<int> stl_operator_one(10,3);
            ft::vector<int> ft_operator_one(100,5);
            std::vector<int> stl_operator_two(10,3);
            ft::vector<int> ft_operator_two(100,5); 

            fs.open("./tester/vectors_output/operator_inf_or_equal_false", std::fstream::in | std::fstream::out | std::fstream::trunc);
            printVectorAttributes(fs, stl_operator_one, ft_operator_one);
            printVectorAttributes(fs, stl_operator_two, ft_operator_two);
            std::cout << "RL '<=' false  :" ;
            std::cout << ((printBoolResult(fs, (stl_operator_one <= stl_operator_two), (ft_operator_one <= ft_operator_two))) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 9999, 5, 0, -54};\n";
            fs << "int range_array_two[] = {144, 335, 5, 0, -54};       \n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "ft::vector<int> ft_operator_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);\n";
            fs << "ft::vector<int> ft_operator_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);\n";

            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 9999, 5, 0, -54};\n";
            fs << "int range_array_two[] = {144, 335, 5, 0, -54};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "std::vector<int> stl_operator_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);\n";
            fs << "std::vector<int> stl_operator_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);\n";
            fs.close();
        }
        
        /* RL '>' true */
        {
            std::vector<int> stl_operator_one(10,3);
            ft::vector<int> ft_operator_one(100,5);
            std::vector<int> stl_operator_two(10,3);
            ft::vector<int> ft_operator_two(100,5)
            ; 
            fs.open("./tester/vectors_output/operator_superior_true", std::fstream::in | std::fstream::out | std::fstream::trunc);
            printVectorAttributes(fs, stl_operator_one, ft_operator_one);
            printVectorAttributes(fs, stl_operator_two, ft_operator_two);
            std::cout << "RL '>' true  :" ;
            std::cout << ((printBoolResult(fs, (stl_operator_one > stl_operator_two), (ft_operator_one > ft_operator_two))) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 9999, 5, 0, -54};\n";
            fs << "int range_array_two[] = {144, 335, 5, 0, -54};       \n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "ft::vector<int> ft_operator_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);\n";
            fs << "ft::vector<int> ft_operator_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);\n";

            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 9999, 5, 0, -54};\n";
            fs << "int range_array_two[] = {144, 335, 5, 0, -54};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "std::vector<int> stl_operator_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);\n";
            fs << "std::vector<int> stl_operator_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);\n";
            fs.close();
        }

        /* RL '>' false */
        {
            std::vector<int> stl_operator_one(10,3);
            ft::vector<int> ft_operator_one(100,5);
            std::vector<int> stl_operator_two(10,3);
            ft::vector<int> ft_operator_two(100,5); 

            fs.open("./tester/vectors_output/operator_superior_false", std::fstream::in | std::fstream::out | std::fstream::trunc);
            printVectorAttributes(fs, stl_operator_one, ft_operator_one);
            printVectorAttributes(fs, stl_operator_two, ft_operator_two);
            std::cout << "RL '>' false  :" ;
            std::cout << ((printBoolResult(fs, (stl_operator_one > stl_operator_two), (ft_operator_one > ft_operator_two))) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 335, 5, 0, -54};\n";
            fs << "int range_array_two[] = {144, 335, 77, 0, -54};       \n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "ft::vector<int> ft_operator_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);\n";
            fs << "ft::vector<int> ft_operator_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);\n";

            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 335, 5, 0, -54};\n";
            fs << "int range_array_two[] = {144, 335, 77, 0, -54};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "std::vector<int> stl_operator_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);\n";
            fs << "std::vector<int> stl_operator_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);\n";
            fs.close();
        }

        /* RL '>=' true */
        {
            std::vector<int> stl_operator_one(10,3);
            ft::vector<int> ft_operator_one(100,5);
            std::vector<int> stl_operator_two(10,3);
            ft::vector<int> ft_operator_two(100,5); 

            fs.open("./tester/vectors_output/operator_sup_or_equal_true", std::fstream::in | std::fstream::out | std::fstream::trunc);
            printVectorAttributes(fs, stl_operator_one, ft_operator_one);
            printVectorAttributes(fs, stl_operator_two, ft_operator_two);
            std::cout << "RL '>=' true  :" ;
            std::cout << ((printBoolResult(fs, (stl_operator_one >= stl_operator_two), (ft_operator_one >= ft_operator_two))) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 335, 78, 0, -54};\n";
            fs << "int range_array_two[] = {144, 335, 77, 0, -54};       \n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "ft::vector<int> ft_operator_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);\n";
            fs << "ft::vector<int> ft_operator_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);\n";

            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 335, 5, 0, -54};\n";
            fs << "int range_array_two[] = {144, 335, 77, 0, -54};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "std::vector<int> stl_operator_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);\n";
            fs << "std::vector<int> stl_operator_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);\n";
            fs.close();
        }

        /* RL '>=' false */
        {
            std::vector<int> stl_operator_one(10,3);
            ft::vector<int> ft_operator_one(100,5);
            std::vector<int> stl_operator_two(10,3);
            ft::vector<int> ft_operator_two(100,5); 

            fs.open("./tester/vectors_output/operator_sup_or_equal_false", std::fstream::in | std::fstream::out | std::fstream::trunc);
            printVectorAttributes(fs, stl_operator_one, ft_operator_one);
            printVectorAttributes(fs, stl_operator_two, ft_operator_two);
            std::cout << "RL '>=' false  :" ;
            std::cout << ((printBoolResult(fs, (stl_operator_one >= stl_operator_two), (ft_operator_one >= ft_operator_two))) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 335, 5, 0, -54};\n";
            fs << "int range_array_two[] = {144, 335, 77, 0, -54};       \n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "ft::vector<int>::iterator ft_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "ft::vector<int> ft_operator_one(ft_iterator_beg_one, ft_iterator_beg_one + 5);\n";
            fs << "ft::vector<int> ft_operator_two(ft_iterator_beg_two, ft_iterator_beg_two + 5);\n";

            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "int range_array_one[] = {144, 335, 5, 0, -54};\n";
            fs << "int range_array_two[] = {144, 335, 77, 0, -54};\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_one(&(range_array_one[0]));\n";
            fs << "std::vector<int>::iterator stl_iterator_beg_two(&(range_array_two[0]));\n";
            fs << "std::vector<int> stl_operator_one(stl_iterator_beg_one, stl_iterator_beg_one + 5);\n";
            fs << "std::vector<int> stl_operator_two(stl_iterator_beg_two, stl_iterator_beg_two + 5);\n";
            fs.close();
        }

        /*reverse*/
        {
            std::cout << '\n';
            std::cout << BOLD_GREEN << "PROBANDO RBEGIN() REND()" << NORMAL << std::endl;
            int range_array[] = { 45, 87846, 12, 965, 5 };
            std::vector<int> myvector (5);
            ft::vector<int>::iterator ft_iterator(&(range_array[0]));
            ft::vector<int> ftvector(ft_iterator, ft_iterator+5);
            show_ftvector(ftvector);

            //std::vector<int>::reverse_iterator rit = myvector.rbegin();
            ft::vector<int>::reverse_iterator ft_rit = ftvector.rbegin();
            
            std::cout << "FT:myvector contains:" << std::endl;
            for (ft::vector<int>::iterator it = ftvector.begin(); it != ftvector.end(); ++it)
                std::cout << ' ' << *it;
            std::cout << std::endl;
            for (ft::vector<int>::reverse_iterator it = ftvector.rbegin(); it != ftvector.rend(); ++it)
                std::cout << ' ' << *it;
            
            std::cout << '\n';
        }
    }

    /*STACK*/
    {
        std::cout << BOLD_RED << "STACK :\n" << NORMAL;

        mkdir("./tester/stacks_output", 0777);
        
        std::fstream fs;

        /* Member functions */
        std::cout << "Member functions : \n";

        /* Default Constructor */
        {
            std::stack<int> stl_default;
            ft::stack<int> ft_default;
            //for (int i=1;i<=10;i++) stl_default.push(i);
            //for (int i=1;i<=10;i++) ft_default.push(i);
            fs.open("./tester/stacks_output/constructor_default", std::fstream::in | std::fstream::out | std::fstream::trunc);          
            std::cout << "ft::stack<int> ft_default  :" ;
            std::cout << ((printStackAttributes(fs, stl_default, ft_default) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::stack<int> ft_default;\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::stack<int> stl_default;\n";
            fs.close();
            
        }
        /* Constructor with vector */
        {
            std::vector<int> myvector (2,200);        // vector with 2 elements
            ft::vector<int> ftvector (2,200);        
            
            std::stack<int,std::vector<int> > std_stack (myvector);
            ft::stack<int,ft::vector<int> > ft_stack (ftvector);
    
            std::cout << "ft::stack<int,ft::vector<int> > ft_stack (ftvector):\n" ;
            //std::cout << ((std_stack==ft_stack)) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            //std::cout << std::endl;

            std::cout << "size: " << std_stack.size() << " ";
            std::cout << "\t Content std [" ;
            while (!std_stack .empty())
                {
                    std::cout << std_stack .top();
                    if (std_stack .size() != 0)
                        std::cout << ", ";
                    std_stack.pop();
                }
            std::cout << "]";
            std::cout << "size: " << std_stack.size() << "empty: " << std_stack.empty() << std::endl;
            std::cout << "size: " << ft_stack.size() << " ";
            std::cout << "\t Content ft  [" ;
            while (!ft_stack.empty())
                {
                    std::cout << ft_stack.top();
                    if (ft_stack.size() != 0)
                        std::cout << ", ";
                    ft_stack.pop();
                }
            std::cout << "]";
            std::cout << "size: " << ft_stack.size() << "empty: " << ft_stack.empty() << std::endl;
            
        }
        /* Empty true */
        {
            std::stack<int> stl_empty;
            ft::stack<int> ft_empty;

                fs.open("./tester/stacks_output/empty_true", std::fstream::in | std::fstream::out | std::fstream::trunc);
                std::cout << "Empty true  :" ;
                std::cout << ((printStackAttributes(fs, stl_empty, ft_empty) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
                std::cout << std::endl;
                fs << "\nCode executed:\n";
                fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
                fs << "ft::stack<int> ft_empty;\n";
                fs << "\nCompared with:\n";
                fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
                fs << "std::stack<int> stl_empty;\n";
                fs.close();
        }
    
        /* Empty false */
        {
            std::stack<int> stl_empty;
            ft::stack<int> ft_empty;

            stl_empty.push(42);
            ft_empty.push(42);

            fs.open("./tester/stacks_output/empty_false", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << "Empty false  :" ;
            std::cout << ((printStackAttributes(fs, stl_empty, ft_empty) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::stack<int> ft_empty;\n";
            fs << "ft_empty.push(42);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::stack<int> stl_empty;\n";
            fs << "stl_empty.push(42);\n";
            fs.close();
        }
   
        /* Size */
        {
            std::stack<int> stl_size;
            ft::stack<int> ft_size;

            for (int i = 0; i < 42; i++)
            {
                stl_size.push(i);
                ft_size.push(i);
            }

            fs.open("./tester/stacks_output/size", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << "Size  :" ;
            std::cout << ((printStackAttributes(fs, stl_size, ft_size) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::stack<int> ft_size;\n";
            fs << "for (int i = 0; i < 42; i++)\n";
            fs << "     ft_size.push(i);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::stack<int> stl_size;\n";
            fs << "for (int i = 0; i < 42; i++)\n";
            fs << "     stl_size.push(i);\n";
            fs.close();
        }
        
        /* Top */
        {
            std::stack<int> stl_top;
            ft::stack<int> ft_top;

            for (int i = 0; i < 42; i++)
            {
                stl_top.push(i);
                ft_top.push(i);
            }

            fs.open("./tester/stacks_output/top", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << "Top  :" ;
            std::cout << ((printSingleValue(fs, stl_top.top(), ft_top.top()) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            stl_top.pop();
            ft_top.pop();
            std::cout << "Top  :" ;
            std::cout << ((printSingleValue(fs, stl_top.top(), ft_top.top()) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::stack<int> ft_top;\n";
            fs << "for (int i = 0; i < 42; i++)\n";
            fs << "     ft_top.push(i);\n";
            fs << "Send output...\n";
            fs << "ft_top.pop();\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::stack<int> stl_top;\n";
            fs << "for (int i = 0; i < 42; i++)\n";
            fs << "     stl_top.push(i);\n";
            fs << "Send output...\n";
            fs << "stl_top.pop();\n";
            fs.close();
        }
       
        /* Push */
        {
            std::stack<int> stl_size;
            ft::stack<int> ft_size;

            for (int i = 0; i < 42; i++)
            {
                stl_size.push(i * 2);
                ft_size.push(i * 2);
            }

            fs.open("./tester/stacks_output/push", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << "Push  :" ;
            std::cout << ((printStackAttributes(fs, stl_size, ft_size) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::stack<int> ft_size;\n";
            fs << "for (int i = 0; i < 42; i++)\n";
            fs << "     ft_size.push(i * 2);\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::stack<int> stl_size;\n";
            fs << "for (int i = 0; i < 42; i++)\n";
            fs << "     stl_size.push(i * 2);\n";
            fs.close();
        }
        
        /* Pop */
        {
            std::stack<int> stl_pop;
            ft::stack<int> ft_pop;

            for (int i = 0; i < 42; i++)
            {
                stl_pop.push(i);
                ft_pop.push(i);
            }

            fs.open("./tester/stacks_output/pop", std::fstream::in | std::fstream::out | std::fstream::trunc);
            std::cout << "Pop  :" ;
            std::cout << ((printStackAttributes(fs, stl_pop, ft_pop) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");

            std::stack<int> stl_pop1;
            ft::stack<int> ft_pop1;

            for (int i = 0; i < 42; i++)
            {
                stl_pop1.push(i);
                ft_pop1.push(i);
            }


            stl_pop1.pop();
            ft_pop1.pop();

            std::cout << ((printStackAttributes(fs, stl_pop1, ft_pop1) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
            fs << "\nCode executed:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "ft::stack<int> ft_pop;\n";
            fs << "for (int i = 0; i < 42; i++)\n";
            fs << "     ft_pop.push(i);\n";
            fs << "Send output...\n";
            fs << "ft_pop.pop();\n";
            fs << "\nCompared with:\n";
            fs << "¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n";
            fs << "std::stack<int> stl_pop;\n";
            fs << "for (int i = 0; i < 42; i++)\n";
            fs << "     stl_pop.push(i);\n";
            fs << "Send output...\n";
            fs << "stl_pop.pop();\n";
            fs.close();
        }
        
        std::cout << std::endl;
        std::cout << "Non-member function overloads : \n";
        /* RL = relational operator */

        /* RL == true */
        {
            std::stack<int> stl_pop_one;
            std::stack<int> stl_pop_two;
            ft::stack<int> ft_pop_one;
            ft::stack<int> ft_pop_two;

            for (int i = 0; i < 42; i++)
            {
                stl_pop_one.push(i);
                stl_pop_two.push(i);
                ft_pop_one.push(i);
                ft_pop_two.push(i);
            }
            
            std::cout << "RL == true  :" ;
            std::cout << ((printBoolResult(fs, (stl_pop_one == stl_pop_two), (ft_pop_one == ft_pop_two)) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
        }
        /* RL == false */
        {
            std::stack<int> stl_pop_one;
            std::stack<int> stl_pop_two;
            ft::stack<int> ft_pop_one;
            ft::stack<int> ft_pop_two;

            for (int i = 0; i < 42; i++)
            {
                stl_pop_one.push(i);
                stl_pop_two.push(i * 2);
                ft_pop_one.push(i);
                ft_pop_two.push(i * 2);
            }      
            std::cout << "RL == false  :" ;
            std::cout << ((printBoolResult(fs, (stl_pop_one == stl_pop_two), (ft_pop_one == ft_pop_two)) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
        }
        /* RL != true */
        {
            std::stack<int> stl_pop_one;
            std::stack<int> stl_pop_two;
            ft::stack<int> ft_pop_one;
            ft::stack<int> ft_pop_two;

            for (int i = 0; i < 42; i++)
            {
                stl_pop_one.push(i);
                stl_pop_two.push(i * 2);
                ft_pop_one.push(i);
                ft_pop_two.push(i * 2);
            }

            printStackAttributes(fs, stl_pop_one, ft_pop_one);
            printStackAttributes(fs, stl_pop_two, ft_pop_two);
            
            std::cout << "RL != true  :" ;
            std::cout << ((printBoolResult(fs, (stl_pop_one != stl_pop_two), (ft_pop_one != ft_pop_two)) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
        }

        /* RL != false */
        {
            std::stack<int> stl_pop_one;
            std::stack<int> stl_pop_two;
            ft::stack<int> ft_pop_one;
            ft::stack<int> ft_pop_two;

            for (int i = 0; i < 42; i++)
            {
                stl_pop_one.push(i);
                stl_pop_two.push(i);
                ft_pop_one.push(i);
                ft_pop_two.push(i);
            }

            printStackAttributes(fs, stl_pop_one, ft_pop_one);
            printStackAttributes(fs, stl_pop_two, ft_pop_two);
            std::cout << "RL != false  :" ;
            std::cout << ((printBoolResult(fs, (stl_pop_one != stl_pop_two), (ft_pop_one != ft_pop_two)) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
        }

        /* RL < true */
        {
            std::stack<int> stl_pop_one;
            std::stack<int> stl_pop_two;
            ft::stack<int> ft_pop_one;
            ft::stack<int> ft_pop_two;

            for (int i = 0; i < 42; i++)
            {
                stl_pop_one.push(i);
                ft_pop_one.push(i);
                if (i == 30)
                {
                    stl_pop_two.push(i * 2);
                    ft_pop_two.push(i * 2);
                }
                else
                {
                    stl_pop_two.push(i);
                    ft_pop_two.push(i);
                }
            }
            printStackAttributes(fs, stl_pop_one, ft_pop_one);
            printStackAttributes(fs, stl_pop_two, ft_pop_two);
            std::cout << "RL < true  :" ;
            std::cout << ((printBoolResult(fs, (stl_pop_one < stl_pop_two), (ft_pop_one < ft_pop_two)) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
        }

        /* RL < false */
        {
            std::stack<int> stl_pop_one;
            std::stack<int> stl_pop_two;
            ft::stack<int> ft_pop_one;
            ft::stack<int> ft_pop_two;

            for (int i = 0; i < 42; i++)
            {
                stl_pop_two.push(i);
                ft_pop_two.push(i);
                if (i == 30)
                {
                    stl_pop_one.push(i * 2);
                    ft_pop_one.push(i * 2);
                }
                else
                {
                    stl_pop_one.push(i);
                    ft_pop_one.push(i);
                }
            }

            printStackAttributes(fs, stl_pop_one, ft_pop_one);
            printStackAttributes(fs, stl_pop_two, ft_pop_two);
            std::cout << "RL < false  :" ;
            std::cout << ((printBoolResult(fs, (stl_pop_one < stl_pop_two), (ft_pop_one < ft_pop_two)) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;

        }

        /* RL <= true */
        {
            std::stack<int> stl_pop_one;
            std::stack<int> stl_pop_two;
            ft::stack<int> ft_pop_one;
            ft::stack<int> ft_pop_two;

            for (int i = 0; i < 42; i++)
            {
                stl_pop_one.push(i);
                stl_pop_two.push(i * 2);
                ft_pop_one.push(i);
                ft_pop_two.push(i * 2);
            }

            printStackAttributes(fs, stl_pop_one, ft_pop_one);
            printStackAttributes(fs, stl_pop_two, ft_pop_two);
            std::cout << "RL <= true  :" ;
            std::cout << ((printBoolResult(fs, (stl_pop_one <= stl_pop_two), (ft_pop_one <= ft_pop_two)) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
        }

        /* RL <= true equal */
        {
            std::stack<int> stl_pop_one;
            std::stack<int> stl_pop_two;
            ft::stack<int> ft_pop_one;
            ft::stack<int> ft_pop_two;

            for (int i = 0; i < 42; i++)
            {
                stl_pop_one.push(i);
                stl_pop_two.push(i);
                ft_pop_one.push(i);
                ft_pop_two.push(i);
            }

            printStackAttributes(fs, stl_pop_one, ft_pop_one);
            printStackAttributes(fs, stl_pop_two, ft_pop_two);
            std::cout << "RL <= true equal  :" ;
            std::cout << ((printBoolResult(fs, (stl_pop_one <= stl_pop_two), (ft_pop_one <= ft_pop_two)) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
        }

        /* RL <= false */
        {
            std::stack<int> stl_pop_one;
            std::stack<int> stl_pop_two;
            ft::stack<int> ft_pop_one;
            ft::stack<int> ft_pop_two;

            for (int i = 0; i < 42; i++)
            {
                stl_pop_one.push(i * 2);
                stl_pop_two.push(i);
                ft_pop_one.push(i * 2);
                ft_pop_two.push(i);
            }

            printStackAttributes(fs, stl_pop_one, ft_pop_one);
            printStackAttributes(fs, stl_pop_two, ft_pop_two);
            std::cout << "RL <= false  :" ;
            std::cout << ((printBoolResult(fs, (stl_pop_one <= stl_pop_two), (ft_pop_one <= ft_pop_two)) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
        }

        /* RL > true */
        {
            std::stack<int> stl_pop_one;
            std::stack<int> stl_pop_two;
            ft::stack<int> ft_pop_one;
            ft::stack<int> ft_pop_two;

            for (int i = 0; i < 42; i++)
            {
                stl_pop_one.push(i * 2);
                stl_pop_two.push(i);
                ft_pop_one.push(i * 2);
                ft_pop_two.push(i);
            }

            printStackAttributes(fs, stl_pop_one, ft_pop_one);
            printStackAttributes(fs, stl_pop_two, ft_pop_two);
            std::cout << "RL > true  :" ;
            std::cout << ((printBoolResult(fs, (stl_pop_one > stl_pop_two), (ft_pop_one > ft_pop_two)) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
        }

        /* RL > false */
        {
            std::stack<int> stl_pop_one;
            std::stack<int> stl_pop_two;
            ft::stack<int> ft_pop_one;
            ft::stack<int> ft_pop_two;

            for (int i = 0; i < 42; i++)
            {
                stl_pop_one.push(i);
                stl_pop_two.push(i);
                ft_pop_one.push(i);
                ft_pop_two.push(i);
            }
            printStackAttributes(fs, stl_pop_one, ft_pop_one);
            printStackAttributes(fs, stl_pop_two, ft_pop_two);
            std::cout << "RL > false  :" ;
            std::cout << ((printBoolResult(fs, (stl_pop_one > stl_pop_two), (ft_pop_one > ft_pop_two)) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
        }

        /* RL >= true */
        {
            std::stack<int> stl_pop_one;
            std::stack<int> stl_pop_two;
            ft::stack<int> ft_pop_one;
            ft::stack<int> ft_pop_two;

            for (int i = 0; i < 42; i++)
            {
                stl_pop_one.push(i);
                stl_pop_two.push(i);
                ft_pop_one.push(i);
                ft_pop_two.push(i);
            }
            printStackAttributes(fs, stl_pop_one, ft_pop_one);
            printStackAttributes(fs, stl_pop_two, ft_pop_two);
            std::cout << "RL >= true  :" ;
            std::cout << ((printBoolResult(fs, (stl_pop_one > stl_pop_two), (ft_pop_one > ft_pop_two)) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
        }

        /* RL >= false */
        {
            std::stack<int> stl_pop_one;
            std::stack<int> stl_pop_two;
            ft::stack<int> ft_pop_one;
            ft::stack<int> ft_pop_two;

            for (int i = 0; i < 42; i++)
            {
                stl_pop_one.push(i);
                ft_pop_one.push(i);
                if (i == 30)
                {
                    stl_pop_two.push(i * 2);
                    ft_pop_two.push(i * 2);
                }
                else
                {
                    stl_pop_two.push(i);
                    ft_pop_two.push(i);
                }
            }
            std::cout << "RL >= false  :" ;
            std::cout << ((printBoolResult(fs, (stl_pop_one >= stl_pop_two), (ft_pop_one >= ft_pop_two)) == true) ? "\033[1;32m[OK]\033[0;37m" : "\033[1;31m[NOP]\033[0;37m");
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    
 
   return(0);
;}