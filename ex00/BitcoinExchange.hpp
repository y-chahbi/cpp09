/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:13:36 by ychahbi           #+#    #+#             */
/*   Updated: 2024/01/27 22:49:51 by ychahbi          ###   ########.fr       */
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
        std::vector<int>        dataBase;
        std::string             dataCSV;
        std::string             data;
        std::map<std::string, float>   datamapped;
        std::map<std::string, float>   input;
        
    public:
        BitcoinExchange();
        BitcoinExchange(std::string);
        void        fill(std::string);
        void        checkLine(std::string);
        float       toFloat(const std::string &str);
        bool        fill_map(std::string, int);
        static void error(std::string);
        void        display();
        ~BitcoinExchange();
};

#endif