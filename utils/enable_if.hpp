/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:45:02 by dperez-z          #+#    #+#             */
/*   Updated: 2022/05/09 17:45:03 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template<bool Cond, class T = void>
	struct enable_if
	{};

	template<class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
}