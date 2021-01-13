/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwyu <hwyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:58:55 by hwyu              #+#    #+#             */
/*   Updated: 2021/01/12 01:55:11 by hwyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

phonebook::phonebook()
{
	this->num = 0;
}

phonebook::~phonebook()
{
}

void	phonebook::set_phone(void)
{
	if (this->num >= 8)
		std::cout << "contact is full." << std::endl;
	else
	{
		this->contacts[this->num++].set_contact();
		if (this->contacts[this->num - 1].null_check() == -1)
		{
			std::cout << "please put inform" << std::endl;
			this->num--;
		}
	}
}

void	phonebook::display_4columns(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     index|first_Name| last_Name|  nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i < this->num; i++)
	{
		this->contacts[i].display_4columns(i + 1);
	}
	std::cout << "|-------------------------------------------|" << std::endl;
}

void	phonebook::display_phone(void)
{
	this->display_4columns();
	std::string s;
	int i = 0;

	std::cout << "index : ";
	getline(std::cin, s);
	if (s.length() == 1)
		i = s[0] - 48;
	if (i > 0 && i <= this->num)
		this->contacts[i - 1].display_contact();
	else
		std::cout << "wrong index" << std::endl;
}
