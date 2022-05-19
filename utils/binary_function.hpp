/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_function.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:44:54 by dperez-z          #+#    #+#             */
/*   Updated: 2022/05/09 17:44:55 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
    template <class Arg1, class Arg2, class Result>
        struct binary_function
        {
            typedef Arg1 first_argument_type;
            typedef Arg2 second_argument_type;
            typedef Result result_type;
        };
}