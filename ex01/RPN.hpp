/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:01:35 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/16 20:32:21 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

class RPN
{
    private:
        std::string string;
        std::stack<int> vector;
        std::stack<char> sign;
    public:
        RPN();
        RPN(std::string);
        RPN(const RPN& Copy);
        RPN& operator=(const RPN& Copy);
        void    set(std::string);
        void    fill();
        void    do_math();
        void    display();
        static void    error(std::string);
        ~RPN();
};

#endif