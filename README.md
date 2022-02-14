# :heavy_check_mark: ft_containers
## Description
The project implements the following containers:  
  
**[Vector](https://www.geeksforgeeks.org/vector-in-cpp-stl/)**  (https://www.cplusplus.com/reference/vector/vector/)

**[Map](https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/)**  
**[Stack](https://www.geeksforgeeks.org/stack-in-cpp-stl/)**   
  
*P.s. On the website `www.cplusplus.com` you can find a very important information about containers library STL.*  
  
:do_not_litter: WARNING:exclamation:  
- [x] You must use ([std::allocator](https://www.geeksforgeeks.org/stdallocator-in-cpp-with-examples/))
- [ ] 
P.s. `INCHECK` is a proprietary algorithm memory allocation in the ft::vector\<\>  
The compiler to use is clang++. • Your code has to be compiled with the following flags : -Wall -Wextra -Werror.
-std=c++98.
  
## Container ft::vector\<\>:
For your vector implementation, it is not mandatory to code the vector<bool> specialization.
**Main coplien's form**  
- [x] ([constructor](https://www.cplusplus.com/reference/vector/vector/vector/))
- [x] ([destructor](https://www.cplusplus.com/reference/vector/vector/~vector/))
- [x] ([operator=](https://www.cplusplus.com/reference/vector/vector/operator=/))
  
**Iterators:**  
- [x] ([begin](https://www.cplusplus.com/reference/vector/vector/begin/)) Returns an iterator pointing to the first element in the vector
- [x] ([end](https://www.cplusplus.com/reference/vector/vector/end/)) Returns an iterator pointing to the theoretical element that follows the last element in the vector
- [x] ([rbegin](https://www.cplusplus.com/reference/vector/vector/rbegin/)) Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
- [x] ([rend](https://www.cplusplus.com/reference/vector/vector/rend/)) Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
  
**Capacity:**  
- [x] ([size](https://www.cplusplus.com/reference/vector/vector/size/)) Returns the number of elements in the vector.
- [x] ([max_size](https://www.cplusplus.com/reference/vector/vector/max_size/)) Returns the maximum number of elements that the vector can hold.
- [x] ([resize](https://www.cplusplus.com/reference/vector/vector/resize/)) 
- [x] ([capacity](https://www.cplusplus.com/reference/vector/vector/capacity/)) Returns the size of the storage space currently allocated to the vector expressed as number of elements.
- [x] ([empty](https://www.cplusplus.com/reference/vector/vector/empty/)) Resizes the container so that it contains ‘n’ elements.
- [x] ([reserve](https://www.cplusplus.com/reference/vector/vector/reserve/)) Requests that the vector capacity be at least enough to contain n elements.
  
**Element access:**  
- [x] ([operator[]](https://www.cplusplus.com/reference/vector/vector/operator[]/)) Returns a reference to the element at position ‘g’ in the vector
- [x] ([at](https://www.cplusplus.com/reference/vector/vector/at/)) Returns a reference to the element at position ‘g’ in the vector
- [x] ([front](https://www.cplusplus.com/reference/vector/vector/front/)) Returns a reference to the first element in the vector
- [x] ([back](https://www.cplusplus.com/reference/vector/vector/back/)) Returns a reference to the last element in the vector
  
**Modifiers:**  
- [x] ([assign](https://www.cplusplus.com/reference/vector/vector/assign/)) It assigns new value to the vector elements by replacing old ones
- [x] ([push_back](https://www.cplusplus.com/reference/vector/vector/push_back/)) It push the elements into a vector from the back
- [x] ([pop_back](https://www.cplusplus.com/reference/vector/vector/pop_back/)) It is used to pop or remove elements from a vector from the back.
- [x] ([insert](https://www.cplusplus.com/reference/vector/vector/insert/)) It inserts new elements before the element at the specified position
- [x] ([erase](https://www.cplusplus.com/reference/vector/vector/erase/)) It is used to remove elements from a container from the specified position or range.
- [x] ([swap](https://www.cplusplus.com/reference/vector/vector/swap/)) It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
- [x] ([clear](https://www.cplusplus.com/reference/vector/vector/clear/)) It is used to remove all the elements of the vector container
  
**Non-member function overloads:**  
- [x] ([relational operators (vector)](https://www.cplusplus.com/reference/vector/vector/operators/)) 
- [x] ([swap (vector)](https://www.cplusplus.com/reference/vector/vector/swap-free/))
  
## Container ft::map\<\>:
 
**Main coplien's form**  
- [x] ([constructor](https://www.cplusplus.com/reference/map/map/map/))
- [x] ([destructor](https://www.cplusplus.com/reference/map/map/~map/))
- [x] ([operator=](https://www.cplusplus.com/reference/map/map/operator=/))
  
**Iterators:**  
- [x] ([begin](https://www.cplusplus.com/reference/map/map/begin/))
- [x] ([end](https://www.cplusplus.com/reference/map/map/end/))
- [x] ([rbegin](https://www.cplusplus.com/reference/map/map/rbegin/))
- [x] ([rend](https://www.cplusplus.com/reference/map/map/rend/))
  
**Capacity:**  
- [x] ([empty](https://www.cplusplus.com/reference/map/map/empty/))
- [x] ([size](https://www.cplusplus.com/reference/map/map/size/))
- [x] ([max_size](https://www.cplusplus.com/reference/map/map/max_size/))
  
**Element access:**  
- [x] ([operator[]](https://www.cplusplus.com/reference/map/map/operator[]/))

**Modifiers:**  
- [x] ([insert](https://www.cplusplus.com/reference/map/map/insert/))
- [x] ([erase](https://www.cplusplus.com/reference/map/map/erase/))
- [x] ([swap](https://www.cplusplus.com/reference/map/map/swap/))
- [x] ([clear](https://www.cplusplus.com/reference/map/map/clear/))
  
**Observers:**  
- [x] ([key_comp](https://www.cplusplus.com/reference/map/map/key_comp/))
- [x] ([value_comp](https://www.cplusplus.com/reference/map/map/value_comp/))

**Operations:**  
- [x] ([find](https://www.cplusplus.com/reference/map/map/find/))
- [x] ([count](https://www.cplusplus.com/reference/map/map/count/))
- [x] ([lower_bound](https://www.cplusplus.com/reference/map/map/lower_bound/))
- [x] ([upper_bound](https://www.cplusplus.com/reference/map/map/upper_bound/))
- [x] ([equal_range](https://www.cplusplus.com/reference/map/map/equal_range/))

## Container ft::stack\<\>:
Your stack will use your vector class as default underlaying container, it must still be
compatible with others containers like the STL one.
**Member functions:**  
- [x] ([constructor](https://www.cplusplus.com/reference/stack/stack/stack/))
- [x] ([empty](https://www.cplusplus.com/reference/stack/stack/empty/))
- [x] ([size](https://www.cplusplus.com/reference/stack/stack/size/))
- [x] ([top](https://www.cplusplus.com/reference/stack/stack/top/))
- [x] ([push](https://www.cplusplus.com/reference/stack/stack/push/))
- [x] ([pop](https://www.cplusplus.com/reference/stack/stack/pop/))
  
**Non-member function overloads:**  
- [x] ([relational operators (stack)](https://www.cplusplus.com/reference/stack/stack/operators/))
  

