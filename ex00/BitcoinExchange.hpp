/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:13:36 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/05 18:03:45 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <limits.h>
#include <fstream>


class BitcoinExchange
{
    private:
        std::map<std::string, float>   DataCSV;
        //std::map<std::string, float>   input;
    public:
        BitcoinExchange();
        BitcoinExchange(std::string);
        void                getDataFromDataCSV();
        void                fill(std::string);
        void                checkLine(std::string);
        static float        toFloat(const std::string &str);
        static void         error(std::string);
        ~BitcoinExchange();
};

#endif