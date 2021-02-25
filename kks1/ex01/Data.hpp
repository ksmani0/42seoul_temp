#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>
# include <cstdlib>

#pragma pack(push, 1)

struct Data { std::string s1; int n; std::string s2; };

#pragma pack(pop)

void        *serialize(void);
Data        *deserialize(void * raw);

#endif
