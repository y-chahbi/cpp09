/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:59:09 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/11 15:58:34 by ychahbi          ###   ########.fr       */
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
        {
            funkctro.push_back(int_tmp);
            d_funkctro.push_back(int_tmp);
        }
        else
            error("Error in parssing!");
    }
}

void    PmergeMe::fill_pair()
{
    {
        std::clock_t start = clock();
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
        std::clock_t end = clock();
        vect += end - start;
    }
    {
        std::clock_t start = clock();
        (d_funkctro.size() % 2 == 0) ? odd = -1 : odd = *(d_funkctro.end() - 1);
        
        std::deque<int>::iterator it;
        it = d_funkctro.begin();
        while (it != d_funkctro.end() && d_funkctro.size() > 1)
        {
            if (d_funkctro.size() > 1)
            {
                int tmp = *it;
                d_funkctro.erase(it);
                d_pair.push_back(std::make_pair(tmp, *it));
                d_funkctro.erase(it);
            }
        }
        std::clock_t end = clock();
        dequ += end - start;
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
    {
        std::clock_t start = clock();
        std::vector<std::pair<int, int> >::iterator its;
        its = pair.begin();
    
        while (its != pair.end())
        {
            if (its->first < its->second)
                swap(its->first, its->second);
            its++;
        }
        std::sort(pair.begin(), pair.end());
        std::clock_t end = clock();
        vect += end - start;
    }
    {
        std::clock_t start = clock();
        std::deque<std::pair<int, int> >::iterator its;
        its = d_pair.begin();
    
        while (its != d_pair.end())
        {
            if (its->first < its->second)
                swap(its->first, its->second);
            its++;
        }
        std::sort(d_pair.begin(), d_pair.end());
        std::clock_t end = clock();
        vect += end - start;
    }
}

void    PmergeMe::makeChain()
{
    {
        std::clock_t start = clock();
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
        std::clock_t end = clock();
        vect += end - start;
    }
    {
        std::clock_t start = clock();
        if (d_pair.size() > 0)
        {
            std::deque<std::pair<int, int> >::iterator its;
            its = d_pair.begin();
    
            d_chain.push_back(its->second);
            d_chain.push_back(its->first);
            its++;
            while (its != d_pair.end())
            {
                d_chain.push_back(its->first);
                d_pend.push_back(its->second);
                its++;
            }
        }
        std::clock_t end = clock();
        dequ += end - start;
    }
}

void    PmergeMe::genJacobsthal(int limit)
{
    {
        std::clock_t start = clock();
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
        std::clock_t end = clock();
        vect += end - start;
    }
    {
        std::clock_t start = clock();
        int first = 0;
        int second = 1;
        int next;
    
        while (first <= limit + 2)
        {
            d_Jacobsthal.push_back(first);
            next = first * 2 + second;
            first = second;
            second = next;
        }
        std::clock_t end = clock();
        dequ += end - start;
    }
}

void        PmergeMe::genCombination()
{
    {
        std::clock_t start = clock();
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
        std::clock_t end = clock();
        vect += end - start;
    }
    {
        std::clock_t start = clock();
        std::deque<int>::iterator it;
        it = std::find(d_Jacobsthal.begin(), d_Jacobsthal.end(), 3);;
        int stop = 1;
        int it_tmp;

        while (it != d_Jacobsthal.end())
        {
            it_tmp = *it;
            while (it_tmp != stop)
            {
                d_Combination.push_back(it_tmp);
                it_tmp--;
            }
            stop = *it;
            it++;
        }
        std::clock_t end = clock();
        dequ += end - start;
    }
}

void    PmergeMe::binarySearch()
{
    {
        std::clock_t start = clock();
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
        std::clock_t end = clock();
        vect += end - start;
    }
    {
        std::clock_t start = clock();
        std::deque<int>::iterator it;
        std::deque<int>::iterator finder;
        it = d_Combination.begin();
        while (it != d_Combination.end())
        {
            if (*it - 2 < (int)d_pend.size())
            {
                int tmp = *it - 2;
                finder = std::lower_bound(d_chain.begin(), d_chain.end(), d_pend[tmp]);
                d_chain.insert(finder, d_pend[tmp]);
            }
            it++;
        }
        if (odd != -1)
        {
            finder = std::lower_bound(d_chain.begin(), d_chain.end(), odd);
            d_chain.insert(finder, odd);
        }
        std::clock_t end = clock();
        dequ += end - start;
    }
}

void    PmergeMe::displayChain()
{
    std::cout << "Before : " << av << std::endl;
    std::cout << "After  : ";
    {
        std::vector<int>::iterator it;

        it = chain.begin();
        while(it != chain.end())
        {
            std::cout << *it << " ";
            it++;
        }
        std::cout << std::endl;
    }
    std::cout << "Time to process a range of " << chain.size() << " elements with std::vector : ";
    double time = (double)vect / CLOCKS_PER_SEC * 1000000.0;
    std::cout << time << " us" << std::endl;
    std::cout << "Time to process a range of " << d_chain.size() << " elements with std::deque : ";
    time = (double)dequ / CLOCKS_PER_SEC * 1000000.0;
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