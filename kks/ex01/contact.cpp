/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwyu <hwyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:58:55 by hwyu              #+#    #+#             */
/*   Updated: 2021/01/12 01:54:16 by hwyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

contact::contact()
{
}

contact::~contact()
{
}

int		contact::null_check(void)
{	
	if (this->first_name.length() == 0 && this->last_name.length() == 0 &&
			this->nickname.length() == 0 && this->login.length() == 0 &&
			this->postal_address.length() == 0 &&
			this->email_address.length() == 0 &&
			this->phone_number.length() == 0 &&
			this->birthday_date.length() == 0 &&
			this->favorite_meal.length() == 0 &&
			this->underwear_color.length() == 0 &&
			this->darkest_secret.length() == 0)
		return (-1);
	return (0);
}

void	contact::set_contact(void)
{
	std::cout << "first_name = ";
	std::getline(std::cin, this->first_name);
	std::cout << "last_name = ";
	std::getline(std::cin, this->last_name);
	std::cout << "nickname = ";
	std::getline(std::cin, this->nickname);
	std::cout << "login = ";
	std::getline(std::cin, this->login);
	std::cout << "postal_address = ";
	std::getline(std::cin, this->postal_address);
	std::cout << "email_address = ";
	std::getline(std::cin, this->email_address);
	std::cout << "phone_number = ";
	std::getline(std::cin, this->phone_number);
	std::cout << "birthday_data = ";
	std::getline(std::cin, this->birthday_date);
	std::cout << "favorite_meal = ";
	std::getline(std::cin, this->favorite_meal);
	std::cout << "underwear_color = ";
	std::getline(std::cin, this->underwear_color);
	std::cout << "darkest_secret = ";
	std::getline(std::cin, this->darkest_secret);
}

void	contact::display_4columns(int index)
{
	std::cout << "|" << std::setw(10) << index;
	if (this->first_name.length() <= 10)
		std::cout << "|" << std::setw(10) << this->first_name;
	else
		std::cout << "|" << this->first_name.substr(0, 9) << ".";
	if (this->last_name.length() <= 10)
		std::cout << "|" << std::setw(10) << this->last_name;
	else
		std::cout << "|" << this->last_name.substr(0, 9) << ".";
	if (this->nickname.length() <= 10)
		std::cout << "|" << std::setw(10) << this->nickname << "|";
	else
		std::cout << "|" << this->nickname.substr(0, 9) << ".|";
	std::cout << std::endl;
}

void	contact::display_contact(void)
{
	std::cout << "first_name = ";
	std::cout << this->first_name << std::endl;
	std::cout << "last_name = ";
	std::cout << this->last_name << std::endl;
	std::cout << "nickname = ";
	std::cout << this->nickname << std::endl;
	std::cout << "login = ";
	std::cout << this->login << std::endl;
	std::cout << "postal_address = ";
	std::cout << this->postal_address << std::endl;
	std::cout << "email_address = ";
	std::cout << this->email_address << std::endl;
	std::cout << "phone_number = ";
	std::cout << this->phone_number << std::endl;
	std::cout << "birthday_data = ";
	std::cout << this->birthday_date << std::endl;
	std::cout << "favorite_meal = ";
	std::cout << this->favorite_meal << std::endl;
	std::cout << "underwear_color = ";
	std::cout << this->underwear_color << std::endl;
	std::cout << "darkest_secret = ";
	std::cout << this->darkest_secret << std::endl;
}
