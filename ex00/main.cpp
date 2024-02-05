/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:27:21 by ychahbi           #+#    #+#             */
/*   Updated: 2024/02/05 18:03:07 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    BitcoinExchange btc;

    (ac == 2) ? btc.fill(av[1]) : btc.error("Error: could not open file.");
    return (0);
}