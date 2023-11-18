/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpereira <tpereira@42Lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:56:41 by tpereira          #+#    #+#             */
/*   Updated: 2023/09/16 12:00:56 by tpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <map>
# include <string>

class BitcoinExchange
{

	private:

		std::map<std::string, double> bitcoinDatabase;
		std::map<std::string, double> inputDatabase;

	public:

		BitcoinExchange();
		BitcoinExchange( BitcoinExchange const & src );
		~BitcoinExchange();

		BitcoinExchange &		operator=( BitcoinExchange const & rhs );

		static bool parseDatabase(std::ifstream &file, std::map<std::string, double> &database);
		static bool parseInput(std::ifstream &file, std::map<std::string, double> &database);

		
};

std::ostream &			operator<<( std::ostream & o, BitcoinExchange const & i );

#endif /* ************************************************* BITCOINEXCHANGE_H */
