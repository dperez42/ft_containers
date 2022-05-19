/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nullptr.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:45:34 by dperez-z          #+#    #+#             */
/*   Updated: 2022/05/09 17:45:37 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

static class nullptr_t
{
    public:
        template<class T>
        operator T*() const { return (0); }

        template<class C, class T>
        operator T C::*() const { return (0); }

    private:

        void operator&() const;

} u_nullptr = {};