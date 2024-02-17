/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:13:36 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/17 12:48:39 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <map>
#include <limits.h>
#include <fstream>
#include <cstring>
#include <algorithm>

class BitcoinExchange
{
    private:
        std::map<std::string, float>   DataCSV;
    public:
        BitcoinExchange();
        BitcoinExchange(std::string);
        void                getDataFromDataCSV();
        void                fill(std::string);
        BitcoinExchange(const BitcoinExchange& Copy);
        BitcoinExchange& operator=(const BitcoinExchange& Copy);
        void                checkLine(std::string);
        static float        toFloat(const std::string &str);
        static void         error(std::string);
        void                getDataVal(std::string, float);
        ~BitcoinExchange();
};

#endif
