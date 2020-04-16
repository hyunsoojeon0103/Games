#include <iostream>
#include <string>
#include "bst_node.hpp"
#include "animal.hpp"
#include "funcs.hpp"
int main()
{
    animal<std::string> animal(std::string("Does it live in the sea"),std::string("lion"),std::string("shark"));
    
    std::cout << "We will play a game! Think of an animal and I will make a guess. Let's begin!\n\n";
    
    bool over = false;
   
    while(!over)
    {
        std::string guess;
        while(!animal.is_leaf())
        {
            guess = animal.guess();
            if(inquire(guess.c_str()))
                animal.move_right();
            else
                animal.move_left();
        }

        guess = animal.guess();

        if(inquire(guess.c_str()))
            std::cout << "I got you!\n";
        else
        {
            std::string name;
            std::cout << "\nI give up... What is the answer?\n: ";
            std::cin >> name;

            std::string description;
            std::cout << "\nWhat would be the best question to reach " << name << "?\n: ";
            std::cin.ignore();
            std::getline(std::cin,description);
            animal.learn(name,description);

            std::cout << "Thanks for teaching me!\n";
        }

        if(inquire("\nWould you like to play one more time?"))
            animal.reset();
        else
            over = true;

        std::cout << '\n';
    }

    std::cout << "Bye~\n";

    return 0;
}
