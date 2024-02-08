/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:26:05 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/07 18:03:04 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstring>

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
        DataCSV.insert(std::pair<std::string, float>(tmp.substr(0, 10), toFloat(tmp.substr(11))));
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
    std::deque<std::string> date_val;
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
    std::deque<int> date;

    while (std::getline(line, yearMD, '-'))
        date.push_back((BitcoinExchange::toFloat(yearMD)));
    if (date.size() < 3)
        return false;
    return (dateVal(date[0], date[1], date[2]));
}


void    BitcoinExchange::getDataVal(std::string date, float value)
{
    float value_from_date = -1;
    date.at(10) = '\0';

    (DataCSV.find(date.c_str()) != DataCSV.end()) && (value_from_date = DataCSV[date.c_str()]);
    if (value_from_date != -1)
        std::cout << date << " => " <<  value << " = " << value * value_from_date << std::endl;
    else
    {
        std::map<std::string, float>::iterator it;
        it = DataCSV.lower_bound(date.c_str());
        std::cout << date << " => " <<  value << " = " << value * double(it->second) << std::endl;
    }

}

void    BitcoinExchange::checkLine(std::string tmp)
{
    std::istringstream line(tmp);
    std::deque<std::string> dava;
    std::string              date[3];

    while (std::getline(line, tmp, '|'))
        dava.push_back(tmp);

    std::istringstream num(dava[1]);
    double dava_num;
    num >> dava_num;
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
            getDataVal(dava[0], dava_num);
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