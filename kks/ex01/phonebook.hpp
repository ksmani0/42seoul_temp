#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include "contact.hpp"

class phonebook
{
  private:
    contact contacts[8];
    int     num;
  public:
	phonebook();
	~phonebook();
    void	set_phone(void);
	void	display_4columns(void);
	void	display_phone(void);
};

#endif
