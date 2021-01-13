/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwyu <hwyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:35:33 by hwyu              #+#    #+#             */
/*   Updated: 2021/01/12 01:56:41 by hwyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int		main(void)
{
  std::string s;
  phonebook pb;

  while (1)
  {
    std::cout << "phonebook : ";
    getline(std::cin, s);
    if (s == "ADD")
		pb.set_phone();
    else if (s == "SEARCH")
		pb.display_phone();
    else if (s == "EXIT")
		break ;
  }
  std::cout << s << std::endl;
  return (0);
}
