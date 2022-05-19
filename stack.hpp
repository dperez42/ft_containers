/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:44:41 by dperez-z          #+#    #+#             */
/*   Updated: 2022/05/09 17:44:42 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef	T			value_type;
			typedef Container	container_type;
			typedef	size_t		size_type;

		protected:
			container_type ct;

		public:
			explicit stack(const container_type &ctnr = container_type())
			{
				this->ct = ctnr;
			}
			~stack(void) {}

			bool empty(void) const { return ct.empty(); }
			size_type size(void) const { return ct.size(); }
			value_type &top(void) { return ct.back(); }
			const value_type &top(void) const { return ct.back(); }
			void push(const value_type& x) { ct.push_back(x); }
			void pop(void) { ct.pop_back(); }

			container_type	get_container(void) const { return this->ct; }
	};

	template <class T, class Container>
	bool operator==(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
        return lhs.get_container() == rhs.get_container();
	}

	template <class T, class Container>
	bool operator!=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
        return lhs.get_container() != rhs.get_container();
	}

	template <class T, class Container>
	bool operator<(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
        return lhs.get_container() < rhs.get_container();
	}

	template <class T, class Container>
	bool operator<=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
        return lhs.get_container() <= rhs.get_container();
	}

	template <class T, class Container>
	bool operator>(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
        return lhs.get_container() > rhs.get_container();
	}
	
	template <class T, class Container>
	bool operator>=(const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs)
	{
        return lhs.get_container() >= rhs.get_container();
	}
}