#include "funcs.hpp"
bool inquire(const char* query)
{
    char ans;
    do
    {
        std::cout << query << "? [Yes / No]\n:";
        std::cin >> ans;
        eat_line();
        ans = tolower(ans);
    }while(ans != 'y' && ans !='n');
    return ans == 'y';
}
void eat_line()
{
    char tmp;
    do
        std::cin.get(tmp);
    while(tmp != '\n');
}
