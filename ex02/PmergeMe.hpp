/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:59:08 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/11 15:28:16 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <limits>
#include <sstream>
#include <ctime>


class PmergeMe
{
    private:
        std::string                       av;
        std::vector<int>                  funkctro;
        std::vector<std::pair<int, int> > pair;
        std::vector<int>                  chain;
        std::vector<int>                  pend;
        std::vector<int>                  Jacobsthal;
        std::vector<int>                  Combination;

        std::deque<int>                  d_funkctro;
        std::deque<std::pair<int, int> > d_pair;
        std::deque<int>                  d_chain;
        std::deque<int>                  d_pend;
        std::deque<int>                  d_Jacobsthal;
        std::deque<int>                  d_Combination;

        std::clock_t                      dequ;
        std::clock_t                      vect;
        int                               odd;
    public:
        PmergeMe();
        PmergeMe(std::string);
        static  void        error(std::string);
        void        set(std::string);
        void        parssing();
        void        fill_pair();
        void        sort_pairs();
        void        swap(int&, int&);
        void        makeChain();
        void        genJacobsthal(int);
        void        genCombination();
        void        binarySearch();
        void        displayChain();
        ~PmergeMe();
};

#endif