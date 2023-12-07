/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:39:53 by pvong             #+#    #+#             */
/*   Updated: 2023/12/07 14:24:30 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

#ifndef SHOWMSG
#define SHOWMSG 1
#endif

#ifndef MYCOLORS
#define MYCOLORS
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

#define MSG_SEP "============================"
#define MSG_SEP2 "============="
#define COLOR(text, color) color << text << RESET
#define MY_SEP() std::cout << COLOR(MSG_SEP, BOLDBLACK) << std::endl
#define MY_SEP2(msg) std::cout << COLOR(MSG_SEP2, BOLDWHITE) << " " << msg << " " << COLOR(MSG_SEP2, BOLDWHITE) << std::endl

#endif

template <typename T>
class Array {
public:
    // Canonical Form
    Array(void);
    Array(Array const &src);
    ~Array(void);
    Array &operator=(Array const &rhs);

    // My constructor
    Array(unsigned int n);

    T &operator[](unsigned int n);

    // Getters
    unsigned int size(void) const;

    // Exception when index is out of range
    class OutOfBoundsException : public std::exception {
        virtual const char *what() const throw();
    };

private:
    T *_array;
    unsigned int _len;
};

#include "array.tpp"

#endif