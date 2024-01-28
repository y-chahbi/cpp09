/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:26:05 by ychahbi           #+#    #+#             */
/*   Updated: 2024/01/28 02:30:18 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

float BitcoinExchange::toFloat(const std::string &str) {
    std::stringstream sstr(str);
    float result;
    if (!(sstr >> result && sstr.eof())) {
        throw std::exception();
    }
    return result;
}

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");

    (!file) ? (void)error("Data file is not found!") : (void)(dataCSV = "data.csv");

    std::string line;

    while (std::getline(file, line))
    {
        try
        {
            datamapped[line.substr(0, 10)] = toFloat(line.substr(11, line.size()));
        }
        catch(std::exception& e)
        {
            (void)e;  
        }
    }

    file.close();
    // std::map<std::string, float>::iterator it = datamapped.begin();
    // while (it != datamapped.end())
    // {
    //     std::cout << it->first <<","<< it->second << std::endl;
    //     it++;
    // }
}

BitcoinExchange::BitcoinExchange(std::string file)
{
    fill(file);
}

void BitcoinExchange::error(std::string l)
{
    std::cout << l << std::endl;
    exit(1);
}

void    check_first_line(std::string ls)
{
    std::string tmp;
    std::string data[3] = {"date", "|", "value"};
    std::istringstream str(ls);
    std::vector<std::string> token;

    while (std::getline(str, tmp, ' '))
        token.push_back(tmp);
    
    std::vector<std::string>::iterator i = token.begin();
    for (int j = 0; i != token.end(); j++)
    {
        if (data[j] != *i)
            BitcoinExchange::error("Parssing error there is an error in first line");
        i++;
    }
}

bool    BitcoinExchange::fill_map(std::string str, int i)
{
    input[str] = i;
    return (1);
}

void    BitcoinExchange::checkLine(std::string tmp)
{
    std::istringstream str1(tmp);
    std::vector<std::string> token;
    std::vector<std::string> date;
    
    while (std::getline(str1, tmp, '|'))
        token.push_back(tmp);

    std::istringstream str2(token[0]);
    while (std::getline(str2, tmp, '-'))
        date.push_back(tmp);

    if (date.size() != 3)
        error("error in date!");
    
    if (toFloat(token[1]) < 0 && fill_map("Error: not a positive number.", -1))
        return;
    if (toFloat(token[1]) > 1000 && fill_map("Error: value is large.", -1))
        return;
    if (toFloat(token[1]) >= INT_MAX && fill_map("Error: too large a number.", -1))
        return;
    std::vector<std::string>::iterator iter = date.begin();
    while (iter != date.end())
    {
        std::cout << *iter << std::endl;
        //std::cout << toFloat(*iter) << std::endl;
        iter++;
    }
}

void    BitcoinExchange::display()
{
    std::map<std::string, float>::iterator iter = input.begin();
    while (iter != input.end())
    {
        if (iter->second == -1)
            std::cout << iter->first << std::endl;
        iter++;
    }
}

void    BitcoinExchange::fill(std::string file)
{
    std::ifstream inpute(file);
    std::string   tmp;

    if (!inpute)
        error("Error: could not open file.");
    
    if (std::getline(inpute, tmp))
        check_first_line(tmp);
    while (std::getline(inpute, tmp))
        checkLine(tmp);
}

BitcoinExchange::~BitcoinExchange(){}