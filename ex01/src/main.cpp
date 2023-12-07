/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 10:55:14 by pvong             #+#    #+#             */
/*   Updated: 2023/12/07 13:38:30 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>


void print_separator(int len, char c, std::string str) {
    int str_len = str.length();
    int left_len = (len - str_len) / 2;
    int right_len = len - str_len - left_len;
    std::cout << std::string(left_len, c) << ' ' << str << ' ' << std::string(right_len, c) << std::endl;
}

template <typename T>
void print(T const &x) {
    std::cout << x << std::endl;
}

int main(void) {
    print_separator(80, '=', "Int"); // Separator
    int array[5] = {1, 2, 3, 4, 5};
    iter(array, 5, print);
    
    print_separator(80, '=', "Char"); // Separator
    char array2[5] = {'a', 'b', 'c', 'd', 'e'};
    iter(array2, 5, print);

    return (0);
}