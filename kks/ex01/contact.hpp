#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class contact
{
  private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string login;
    std::string postal_address;
    std::string email_address;
    std::string phone_number;
    std::string birthday_date;
    std::string favorite_meal;
    std::string underwear_color;
    std::string darkest_secret;
  public:
    contact();
    ~contact();
    void	set_contact();
	int		null_check();
	void	display_4columns(int index);
	void	display_contact();
};

#endif
