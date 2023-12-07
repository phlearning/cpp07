/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:41:37 by pvong             #+#    #+#             */
/*   Updated: 2023/12/07 14:24:19 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"

/* -------------------------------------------------------------------------- */
/*                               CANONICAL FORM                               */
/* -------------------------------------------------------------------------- */

template <typename T>
Array<T>::Array(void) : _array(NULL), _len(0) {
    if (SHOWMSG) {
        std::cout << COLOR("Array default constructor called", CYAN) << std::endl;
    }
}

template <typename T>
Array<T>::Array(Array const &src) : _array(new T[src._len]), _len(src._len) {
    if (SHOWMSG) {
        std::cout << COLOR("Array copy constructor called", CYAN) << std::endl;
    }
    for (unsigned int i = 0; i < _len; i++) {
        _array[i] = src._array[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other) {
    if (SHOWMSG) {
        std::cout << COLOR("Array assignation operator called", CYAN) << std::endl;
    }
    if (this != &other) {
        delete[] _array;
        _array = new T[other._len];
        _len = other._len;
        for (unsigned int i = 0; i < _len; i++) {
            _array[i] = other._array[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array(void) {
    if (SHOWMSG) {
        std::cout << COLOR("Array destructor called", RED) << std::endl;
    }
    delete[] _array;
}

/* -------------------------------------------------------------------------- */
/*                               MY CONSTRUCTOR                               */
/* -------------------------------------------------------------------------- */

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _len(n) {
    if (SHOWMSG) {
        std::cout << COLOR("Array constructor called", CYAN) << std::endl;
        std::cout << COLOR("Array length: ", CYAN) << _len << std::endl;
    }
}

/* -------------------------------------------------------------------------- */
/*                                  EXCEPTION                                 */
/* -------------------------------------------------------------------------- */

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw() {
    return "Error: Out of limits";
}

/* -------------------------------------------------------------------------- */

// Subscript or Array index operator
template <typename T>
T &Array<T>::operator[](unsigned int i) {
    if (i >= _len) {
        throw Array::OutOfBoundsException();
    }
    return _array[i];
}

/* -------------------------------------------------------------------------- */
/*                               MEMBER FUNCTION                              */
/* -------------------------------------------------------------------------- */

template <typename T>
unsigned int Array<T>::size(void) const {
    return _len;
}