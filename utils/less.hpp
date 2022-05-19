/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:45:16 by dperez-z          #+#    #+#             */
/*   Updated: 2022/05/09 17:45:18 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "binary_function.hpp"

namespace ft
{
     /*
    ** A binary function object class who will return
    ** whether the first arguement compares less than the second.
    ** (using "<" operator).
    */
    template <class T>
        struct less : binary_function<T, T, bool>
        {
            bool operator() (const T& x, const T& y) const { return (x < y); }
        };
}
