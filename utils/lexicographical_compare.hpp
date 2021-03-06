/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:45:22 by dperez-z          #+#    #+#             */
/*   Updated: 2022/05/09 17:45:25 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
        {
            while (first2 != last2)
            {
                if (first1 == last1 || comp(*first1, *first2))
                    return (true);
                if (comp(*first2, *first1))
                    return false;
                ++first1;
                ++first2;
            }
            return (first2 != last2);
        }
    
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,  InputIterator2 first2, InputIterator2 last2)
        {
            while (first1 != last1)
            {
                if (first2 == last2 || *first2 < *first1) return false;
                else if (*first1 < *first2) return true;
                ++first1;
                ++first2;
            }
            return (first2 != last2);
        }
    
}