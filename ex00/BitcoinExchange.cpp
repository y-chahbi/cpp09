/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:26:05 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/14 18:20:24 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstring>

float BitcoinExchange::toFloat(const std::string& str) {

    std::string proStr = str;

    proStr.erase(remove(proStr.begin(), proStr.end(), 'f'), proStr.end());
    std::stringstream sstr(proStr);

    float result;

    if (!(sstr >> result)) {
        throw std::runtime_error("Converting to float.");
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

    try{
        while (std::getline(DataCSV_v, tmp))
            DataCSV.insert(std::pair<std::string, float>(tmp.substr(0, 10), toFloat(tmp.substr(11))));
    }
    catch(std::exception& e)
    {
        error("Reading Data error! " + (std::string)(e.what())); 
    }
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
    int valid_day;

    if ((year < 1) || (month < 1 || month > 12) || day < 1)
        return (false);

    bool year_v = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (month == 2)
        (year_v) ? valid_day = 29 : valid_day = 28;

    bool mounth_v = (month != 2) && (month == 4 || month == 6 || month == 9 || month == 11);
        (mounth_v) ? valid_day = 30 : valid_day = 31;

    if (day > valid_day)
        return false;

    return true;
}

bool checkYear(std::string yearMD)
{
    std::istringstream line(yearMD);
    std::deque<int> date;

    try{
        while (std::getline(line, yearMD, '-'))
            date.push_back((BitcoinExchange::toFloat(yearMD)));
    }
    catch(std::exception& e)
    {
        BitcoinExchange::error("checking year error! " + (std::string)(e.what())); 
    }
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

void    parssing_val(const char* str)
{
    int points = 0;
    int fs     = 0;
    int minus  = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        (str[i] == '.') && points++;
        (str[i] == 'f') && fs++;
        (str[i] == '-') && minus++;

        if ((!(str[i] >= '0' && str[i] <= '9') && str[i] != '.' && str[i] != 'f' && str[i] != ' '
            && str[i] != '-') || points > 1 || fs > 1 || minus > 1 || (str[i + 1] && str[i] == 'f'))
            BitcoinExchange::error("parsing Error!");
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
        float myFloat;
        try { myFloat = toFloat(dava[1]); }
        catch(std::exception& e)
        { error("parssing error! " + (std::string)(e.what())); }

        parssing_val(dava[1].c_str());
        if (myFloat >= INT_MAX)
           std::cout << "Error: too large a number." << std::endl;
        else if (myFloat < 0)
           std::cout << "Error: not a positive number." << std::endl;
        else if (myFloat > 1000)
           std::cout << "Error: the price is more then 1K" << std::endl;
        else if (!checkYear(dava[0]))
           std::cout << "Error: bad input => " << dava[0] << std::endl;
        else
            getDataVal(dava[0], myFloat);
    }
}

void    BitcoinExchange::fill(std::string file)
{
    std::ifstream getInput(file);
    std::string tmp;

    if (!getInput)
        error("Error: could not open file.");

    (std::getline(getInput, tmp)) && (check_first_line(tmp));
    while (std::getline(getInput, tmp))
        checkLine(tmp);
}

BitcoinExchange::~BitcoinExchange(){}