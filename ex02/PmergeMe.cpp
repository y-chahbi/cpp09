/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:59:09 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/11 06:09:04 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>

PmergeMe::PmergeMe(){}

void    PmergeMe::set(std::string str)
{
    this->av = str;
}

void    PmergeMe::error(std::string error)
{
    std::cout << error << std::endl;
    exit(1);
}

void    check(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!(isdigit(str[i])))
            PmergeMe::error("Error in parsing");
}

void    PmergeMe::parssing()
{
    std::stringstream input(av);
    std::string tmp;
    int               int_tmp;

    while(std::getline(input, tmp, ' '))
    {
        check(tmp.c_str());
        std::stringstream conv( tmp);
        conv >> int_tmp;
        if (int_tmp < INT_MAX)
            funkctro.push_back(int_tmp);
        else
            error("Error in parssing!");
    }
}

void    PmergeMe::fill_pair()
{
    start = clock(); 
    (funkctro.size() % 2 == 0) ? odd = -1 : odd = *(funkctro.end() - 1);
    
    std::vector<int>::iterator it;
    it = funkctro.begin();
    while (it != funkctro.end() && funkctro.size() > 1)
    {
        if (funkctro.size() > 1)
        {
            int tmp = *it;
            funkctro.erase(it);
            pair.push_back(std::make_pair(tmp, *it));
            funkctro.erase(it);
        }
    }
}

void    PmergeMe::swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void    PmergeMe::sort_pairs()
{
    std::vector<std::pair<int, int> >::iterator its;
    its = pair.begin();

    while (its != pair.end())
    {
        if (its->first < its->second)
            swap(its->first, its->second);
        its++;
    }
    std::sort(pair.begin(), pair.end());
}

void    PmergeMe::makeChain()
{
    if (pair.size() > 0)
    {
        std::vector<std::pair<int, int> >::iterator its;
        its = pair.begin();

        chain.push_back(its->second);
        chain.push_back(its->first);
        its++;
        while (its != pair.end())
        {
            chain.push_back(its->first);
            pend.push_back(its->second);
            its++;
        }
    }
}

void    PmergeMe::genJacobsthal(int limit)
{
    int first = 0;
    int second = 1;
    int next;

    while (first <= limit + 2)
    {
        Jacobsthal.push_back(first);
        next = first * 2 + second;
        first = second;
        second = next;
    }
}

void        PmergeMe::genCombination()
{
    std::vector<int>::iterator it;
    it = std::find(Jacobsthal.begin(), Jacobsthal.end(), 3);;
    int stop = 1;
    int it_tmp;

    while (it != Jacobsthal.end())
    {
        it_tmp = *it;
        while (it_tmp != stop)
        {
            Combination.push_back(it_tmp);
            it_tmp--;
        }
        stop = *it;
        it++;
    }
}

void    PmergeMe::binarySearch()
{
    std::vector<int>::iterator it;
    std::vector<int>::iterator finder;
    it = Combination.begin();
    while (it != Combination.end())
    {
        if (*it - 2 < (int)pend.size())
        {
            int tmp = *it - 2;
            finder = std::lower_bound(chain.begin(), chain.end(), pend[tmp]);
            chain.insert(finder, pend[tmp]);
        }
        it++;
    }
    if (odd != -1)
    {
        finder = std::lower_bound(chain.begin(), chain.end(), odd);
        chain.insert(finder, odd);
    }
    end = clock();
}

void    PmergeMe::displayChain()
{
    std::vector<int>::iterator it;

    it = chain.begin();
    while(it != chain.end())
    {
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << chain.size() << " elements with std::clock_t : ";
    double time = (double)(end - start) / CLOCKS_PER_SEC * 1000000.0;
    std::cout << time << " us" << std::endl;
}

PmergeMe::PmergeMe(std::string av)
{
    set(av);
    parssing();
    fill_pair();
    sort_pairs();
    makeChain();
    genJacobsthal(pend.size() * 2);
    genCombination();
    binarySearch();
    displayChain();
}

PmergeMe::~PmergeMe(){}