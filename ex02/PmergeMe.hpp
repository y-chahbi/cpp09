/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:59:08 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/08 13:40:21 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <sstream>

class PmergeMe
{
    private:
        std::string         av;
        std::vector<int>    funkctro;
    public:
        PmergeMe();
        PmergeMe(std::string);
        static  void        error(std::string);
        void        set(std::string);
        void        parssing();
        ~PmergeMe();
};

#endif