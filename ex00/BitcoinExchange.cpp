/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:26:05 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/05 18:08:07 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

float BitcoinExchange::toFloat(const std::string &str) {
    std::stringstream sstr(str);
    float result;
    if (!(sstr >> result)) {
        throw std::exception();
    }
    return result;
}

void    BitcoinExchange::getDataFromDataCSV()
{
    std::ifstream DataCSV_v("data.csv");
    if (!DataCSV_v)
        BitcoinExchange::error("Filed to read database!");

    std::string tmp;
    std::getline(DataCSV_v, tmp);
    while (std::getline(DataCSV_v, tmp))
        DataCSV.insert(std::pair<std::string, float>(tmp.substr(0, 9), toFloat(tmp.substr(11))));
}

BitcoinExchange::BitcoinExchange()
{
    getDataFromDataCSV();
}

BitcoinExchange::BitcoinExchange(std::string file)
{
    getDataFromDataCSV();
    fill(file);
}

void BitcoinExchange::error(std::string error)
{
    std::cerr << error << std::endl;
    exit(1);
}

bool    check_first_line(std::string firstLine)
{
    std::istringstream line(firstLine);
    std::vector<std::string> date_val;
    while (std::getline(line, firstLine, ' '))
        date_val.push_back(firstLine);

    if (!(date_val[0] == "date" && date_val[1] == "|" && date_val[2] == "value"))
        BitcoinExchange::error("Error: first line filed are not correct!");
    return (1);
}

bool dateVal(int year, int month, int day) {
    // Check if the year is within a valid range
    if (year < 1) {
        return false;
    }

    // Check if the month is within a valid range (1 to 12)
    if (month < 1 || month > 12) {
        return false;
    }

    // Check if the day is within a valid range for that month and year
    int max_day;
    if (month == 2) {
        // Check for February
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            max_day = 29;
        } else {
            max_day = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        max_day = 30;
    } else {
        max_day = 31;
    }

    if (day < 1 || day > max_day) {
        return false;
    }

    return true;
}

bool checkYear(std::string yearMD)
{
    std::istringstream line(yearMD);
    std::vector<int> date;

    while (std::getline(line, yearMD, '-'))
        date.push_back((BitcoinExchange::toFloat(yearMD)));
    if (date.size() < 3)
        return false;
    return (dateVal(date[0], date[1], date[2]));
}

void    BitcoinExchange::checkLine(std::string tmp)
{
    std::istringstream line(tmp);
    std::vector<std::string> dava;
    std::string              date[3];

    //std::cout << tmp << std::endl;
    while (std::getline(line, tmp, '|'))
        dava.push_back(tmp);

    if (dava.size() != 2)
        std::cout << "Error: bad input => " << dava[0] << std::endl;
    else if (dava.size() == 2)
    {
        if (toFloat(dava[1]) >= INT_MAX)
           std::cout << "Error: too large a number." << std::endl;
        else if (toFloat(dava[1]) < 0)
           std::cout << "Error: not a positive number." << std::endl;
        else if (toFloat(dava[1]) < 0)
           std::cout << "Error: not a positive number." << std::endl;
        else if (toFloat(dava[1]) > 1000)
           std::cout << "Error: the price is more then 1K" << std::endl;
        else if (!checkYear(dava[0]))
           std::cout << "Error: bad input => " << dava[0] << std::endl;
        else
            std::cout << dava[0] <<  dava[1] << std::endl;;
    }
}

void    BitcoinExchange::fill(std::string file)
{
    std::ifstream getInput(file);
    if (!getInput)
        error("Error: could not open file.");
    std::string tmp;
    (std::getline(getInput, tmp)) && (check_first_line(tmp));
    while (std::getline(getInput, tmp))
        checkLine(tmp);
}

BitcoinExchange::~BitcoinExchange(){}