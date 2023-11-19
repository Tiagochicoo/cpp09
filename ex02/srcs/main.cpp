/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:49:12 by tpereira          #+#    #+#             */
/*   Updated: 2023/11/19 18:24:58 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **/*argv*/)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN <inverted Polish mathematical expression>" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "it works!" << std::endl;
	
	}
	return 0;
}
