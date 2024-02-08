/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:59:09 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/08 13:43:57 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

void    PmergeMe::set(std::string str)
{
    this->av = str;
}

void    PmergeMe::error(std::string error)
{
    std::cout << error << std::endl;
}

void    PmergeMe::parssing()
{
    std::stringstream input(av);
    std::string tmp;
    std::stringstream conv;
    int               int_tmp;

    while(std::getline(input, tmp, ' '))
    {
        conv << tmp;
        conv >> int_tmp;
        if (int_tmp >= 0 && int_tmp < INT_MAX)
            funkctro.push_back(int_tmp);
        else
            error("Error in parssing!");
    }
}

PmergeMe::PmergeMe(std::string av)
{
    set(av);
    parssing();
}

PmergeMe::~PmergeMe(){}