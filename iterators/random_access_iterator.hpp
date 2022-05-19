/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:45:49 by dperez-z          #+#    #+#             */
/*   Updated: 2022/05/09 17:45:52 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator.hpp"

namespace ft
{
	template <typename T>
	class random_access_iterator
	{
		public:
			typedef typename ft::Iter<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::Iter<std::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename ft::Iter<std::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::Iter<std::random_access_iterator_tag, T>::pointer				pointer;
			typedef typename ft::Iter<std::random_access_iterator_tag, T>::reference			reference;
			pointer	_ptr;

		public:
			random_access_iterator(void) : _ptr(NULL) {}

			template <typename U>
			random_access_iterator(const random_access_iterator<U> &copy) : _ptr(copy._ptr) {}
			random_access_iterator(pointer p) : _ptr(p) {}

			random_access_iterator &operator=(const random_access_iterator &op)
			{
				if (this == &op)
					return *this;
				this->_ptr = op._ptr;
				return *this;
			}

            reference	operator*(void) const { return *(this->_ptr); }			 //const
			pointer		operator->(void) { return this->_ptr; }

            random_access_iterator	&operator++(void)
			{
				this->_ptr++;
				return *this;
			}

			random_access_iterator	operator++(int)
			{
				random_access_iterator	pre = *this;
				
				this->_ptr++;
				return pre;
			}

			random_access_iterator	&operator--(void)
			{
				this->_ptr--;
				return *this;
			}

			random_access_iterator	operator--(int)
			{
				random_access_iterator	pre = *this;
				this->_ptr--;
				return pre;
			}

			random_access_iterator operator+(difference_type n) const
			{
				return (_ptr + n);
                //random_access_iterator res(*this);
				//res._ptr += n;
				//return res;
			}

			random_access_iterator operator-(difference_type n) const
			{
				return (_ptr - n);
                //random_access_iterator res(*this);
				//res._ptr -= n;
				//return res;
			}

			random_access_iterator operator+=(difference_type n)
			{
				this->_ptr += n;
				return *this;
			}

			random_access_iterator operator-=(difference_type n)
			{
				this->_ptr -= n;
				return *this;
			}

            reference operator[](int n) { return this->_ptr[n]; }
			bool	operator==(const random_access_iterator &b) const { return this->_ptr == b._ptr; }
			bool	operator!=(const random_access_iterator &b) const { return this->_ptr != b._ptr; }
			bool	operator<(const random_access_iterator &b) const { return this->_ptr < b.get_pointer(); }
			bool	operator>(const random_access_iterator &b) const { return this->_ptr > b.get_pointer(); }
			bool	operator<=(const random_access_iterator &b) const { return this->_ptr <= b.get_pointer(); }
			bool	operator>=(const random_access_iterator &b) const { return this->_ptr >= b.get_pointer(); }

			pointer	get_pointer(void) const { return this->_ptr; }
	};

	template <typename T, typename U>
	bool operator<(const random_access_iterator<T> &a, const random_access_iterator<U> &b)
	{
		return a.get_pointer() < b.get_pointer();
	}

	template <typename T, typename U>
	bool operator>(const random_access_iterator<T> &a, const random_access_iterator<U> &b)
	{
		return a.get_pointer() > b.get_pointer();
	}
	
	template <typename T, typename U>
	bool operator<=(const random_access_iterator<T> &a, const random_access_iterator<U> &b)
	{
		return a.get_pointer() <= b.get_pointer();
	}

	template <typename T, typename U>
	bool operator>=(const random_access_iterator<T> &a, const random_access_iterator<U> &b)
	{
		return a.get_pointer() >= b.get_pointer();
	}

	template <typename T, typename U>
	typename random_access_iterator<T>::difference_type operator+(const random_access_iterator<T> &a, const random_access_iterator<U> &b)
	{
		return a.get_pointer() + b.get_pointer();
	}

	template <typename T, typename U>
	typename random_access_iterator<T>::difference_type operator-(const random_access_iterator<T> &a, const random_access_iterator<U> &b)
	{
		return a.get_pointer() - b.get_pointer();
	}

	template <typename T>
	ft::random_access_iterator<T> operator+(typename ft::random_access_iterator<T>::difference_type a, const random_access_iterator<T> &b)
	{
		return a + b.get_pointer();
	}

	template <typename T, typename U>
	bool operator!=(const random_access_iterator<T> &a, const random_access_iterator<U> &b)
	{
		return a.get_pointer() != b.get_pointer();
	}

	template <typename T, typename U>
	bool operator==(const random_access_iterator<T> &a, const random_access_iterator<U> &b)
	{
		return a.get_pointer() == b.get_pointer();
	}

};