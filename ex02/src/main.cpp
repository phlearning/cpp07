/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:48:09 by pvong             #+#    #+#             */
/*   Updated: 2023/12/07 14:24:11 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"

void print_separator(int len, char c, std::string str, std::string color) {
    int str_len = str.length();
    int left_len = (len - str_len) / 2;
    int right_len = len - str_len - left_len;
    std::cout << color << std::string(left_len, c) << ' ' << str << ' ' << std::string(right_len, c) << RESET << std::endl;
}

int main() {

    try {
        print_separator(80, '=', "Constructor with 0 len and 5 len", BOLDBLACK);
        Array<int> arr1; // Default constructor
        std::cout << "arr1 size: " << arr1.size() << std::endl;

        Array<int> arr2(5); // Parameterized constructor
        std::cout << "arr2 size: " << arr2.size() << std::endl;

        print_separator(80, '=', "Copy constructor and assignment operator", BOLDBLACK);
        arr2[2] = 42;
        std::cout << "arr2[2]: " << arr2[2] << std::endl;

        Array<int> arr3 = arr2; // Copy constructor
        std::cout << "arr3 size: " << arr3.size() << std::endl;
        arr3[2] = 99;
        std::cout << "arr2[2]: " << arr2[2] << std::endl;
        std::cout << "arr3[2]: " << arr3[2] << std::endl;

        Array<int> arr4;
        arr4 = arr2; // Assignment operator
        std::cout << "arr4 size: " << arr4.size() << std::endl;

        // Uncommenting the line below will throw an exception
        print_separator(80, '=', "Out of bound exception", BOLDBLACK);
        std::cout << arr2[10] << std::endl;
    } catch (const std::exception &e) {
        std::cerr << COLOR("Exception: ", YELLOW) << e.what() << std::endl;
    }

    return 0;
}
