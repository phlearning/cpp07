/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:48:00 by pvong             #+#    #+#             */
/*   Updated: 2023/12/07 13:37:36 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, int len, void (*f)(T const &)) {
    for (int i = 0; i < len; i++)
        f(array[i]);
}

template <typename T, typename Func>
void iter(T *array, int len, Func f)
{
    for (int i = 0; i < len; i++)
        f(array[i]);
}

#endif