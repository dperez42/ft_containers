/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:45:41 by dperez-z          #+#    #+#             */
/*   Updated: 2022/05/09 17:45:43 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <memory>
#include <iostream>

#pragma once

namespace	ft
{
	template <class T1, class T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		pair(void) : first(), second() {}

		template <class U, class V>
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}

		pair(const first_type &a, const second_type &b) : first(a), second(b) {}

		pair	&operator=(const pair &pr)
		{
			if (*this == pr)
				return *this;
			this->first = pr.first;
			this->second = pr.second;
			return *this;
		}
	};

	template <class T1, class T2>
	bool operator==(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second ? true : false;
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<(const pair<T1,T2> &lhs, const pair<T1,T2> &rhs)
	{
		if (lhs.first < rhs.first)
			return true;
		else if (lhs.first > rhs.first)
			return false;
		else if (lhs.second < rhs.second)
			return true;
		else
			return false;
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs < rhs;
	}

	template <class T1, class T2>
	bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs < rhs);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs < rhs);
	}


	template <class T1, class T2>
	pair<T1, T2>	make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}
};