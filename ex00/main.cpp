/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:27:21 by ychahbi           #+#    #+#             */
/*   Updated: 2024/01/28 05:20:32 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange btc;

    (ac == 2) ? btc.fill(av[1]) : btc.error("Error: could not open file.");
    btc.display();

    return (0);
}