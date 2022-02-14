#pragma once
//https://github.com/markveligod/ft_containers/blob/master/include/Vector.hpp
namespace ft
{
    template<class T, class Alloc = std::allocator<T> >
	class vector
	{
            private:
                size_type		len_size;
			    size_type		cap;
            public:
                //Constructors y destructor
                explicit vector(const allocator_type& alloc = allocator_type());
                explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
                vector(iterator first, iterator last, const allocator_type& alloc = allocator_type());
                vector(const_iterator first, const_iterator last, const allocator_type& alloc = allocator_type());
                vector(const vector& x);
                vector &operator=(const vector& x);
                ~vector();

                //Iterators
                iterator				begin()			{ return iterator(this->ptr);}
                const_iterator			begin() const	{ return const_iterator(this->ptr);}
                iterator				end()			{ return iterator(&this->ptr[this->len_size]);}
                const_iterator			end() const		{ return const_iterator(&this->ptr[this->len_size]);}
                reverse_iterator		rbegin()		{ return reverse_iterator(&this->ptr[this->len_size - 1]);}
                const_reverse_iterator	rbegin() const	{ return reverse_iterator(&this->ptr[this->len_size - 1]);}
                reverse_iterator		rend()			{ return reverse_iterator(this->ptr - 1);}
                const_reverse_iterator	rend() const	{ return reverse_iterator(this->ptr - 1);}
                
                //Capacity
                size_type	size() const		{ return this->len_size;}
			    size_type	max_size() const	{ return (std::numeric_limits<size_type>::max() / (sizeof(value_type)));}
			    size_type	capacity() const	{ return this->cap;}
			    bool		empty() const		{ return (!(this->len_size));}
			    void		resize(size_type n, value_type val = value_type());
			    void		reserve(size_type n);
                
                //Element Access
                reference		operator[](size_type n) 		{ return (this->ptr[n]);}
                const_reference	operator[](size_type n) const 	{ return (this->ptr[n]);}
                reference		front() 						{ return (this->ptr[0]);}
                const_reference	front() const 					{ return (this->ptr[0]);}
                reference		back() 							{ return (this->ptr[this->len_size - 1]);}
                const_reference	back() const 					{ return (this->ptr[this->len_size - 1]);}
                reference		at(size_type n)
                {
                    if (n >= this->len_size)
                        throw (std::out_of_range("out of range"));
                    return (this->ptr[n]);
                }
                const_reference	at(size_type n) const			{return (this->at(n));}
                
                //Modifiers
    			void		assign(iterator first, iterator last);
                void		assign(const_iterator first, const_iterator last);
                void		assign(size_type n, const value_type& val);
                void		push_back(const value_type& val);
                void		pop_back();
                iterator 	insert(iterator position, const value_type& val);
                void 		insert(iterator position, size_type n, const value_type& val);
                void		insert(iterator position, iterator first, iterator last);
                void		insert(iterator position, const_iterator first, const_iterator last);
                iterator	erase(iterator position);
                iterator	erase(iterator first, iterator last);
                void 		swap(vector& x);
                void		clear();            

    };
    /*
    **==========================
    **          Main
    **==========================
    */


    /*
    **==========================
    **   Non-member function 
    **        overloads       =
    **==========================
    */

    template<typename T, typename Alloc>
    bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
    {


    /*
    **==========================
    **        Capacity: size, max_size, resize, capacity, empty, reserve
    **==========================
    */
   
    /*
    **==========================
    **       Element acces: operator[], at, front, back
    **==========================
    */

    /*
    **==========================
    **       Modifiers: assign, push_back, pop_back, insert, erase, swap, clear
    **==========================
    */

    /*
    **==========================
    **   Non-member function 
    **        overloads       =
    **==========================
    */


} //ft namespace