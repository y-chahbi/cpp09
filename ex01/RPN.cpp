/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:01:37 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/17 15:02:47 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}


RPN::RPN(std::string string){
    set(string);
    fill();
    display();
}

void    RPN::error(std::string error)
{
    std::cerr << error << std::endl;
    exit(1);
}


void    RPN::set(std::string string){
    this->string = string;
}

bool isoper(char *opr, char c)
{
    for (int i = 0; opr[i] != '\0' && i < 5; i++)
    {
        if (opr[i] == c)
            return (1);
    }
    return (0);
}

void    RPN::do_math()
{
    int sum;
    int b = vector.top();
    vector.pop();
    int a = vector.top();
    char sn = sign.top();

    switch (sn){
        case '+':
            sum = a + b;
            break;
        case '-':
            sum = a - b;
            break;
        case '*':
            sum = a * b;
            break;
        case '/':
            if (b != 0)
                sum = a / b;
            else
                error("Can't divide on ZERO");
            break;
    }
    vector.pop();
    sign.pop();
    vector.push(sum);
    
}

void    RPN::display()
{
    if (vector.size() == 1 && sign.size() == 0)
       std::cout << vector.top() << std::endl;
    else
        error("Invalid :( !");
}

RPN::RPN(const RPN& Copy)
{
    *this = Copy;
}

RPN& RPN::operator=(const RPN& Copy)
{
    std::stack<int>  it_int = Copy.vector;
    std::stack<char> it_char = Copy.sign;

    for (; it_int.size() != 0; it_int.pop())
        this->vector.push(it_int.top());
    for (; it_char.size() != 0; it_char.pop())
        this->sign.push(it_char.top());
    this->string = Copy.string;
    return (*this);
}

void    RPN::fill(){
    std::stringstream strm(this->string);
    std::string tmp;
    char        opr[] = "+-*/";

    while (std::getline(strm, tmp, ' '))
    {
        if (isoper(opr, tmp.c_str()[0]) && tmp.size() == 1)
        {
            sign.push(tmp.c_str()[0]);
            if (vector.size() > 1)
                do_math();
        }
        else if (isdigit(tmp.c_str()[0]) && tmp.size() == 1)
            vector.push(tmp.c_str()[0] - 48);
        else
           error("Error!");
    }
}

RPN::~RPN(){}