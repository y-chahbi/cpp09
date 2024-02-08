/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:01:35 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/08 10:25:24 by ychahbi          ###   ########.fr       */
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
    public:
        RPN();
        RPN(std::string);
        void    set(std::string);
        void    fill();
        void    do_math(int, int, char);
        void    display();
        static void    error(std::string);
        ~RPN();
};

#endif