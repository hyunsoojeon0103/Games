#include <iostream>
#include <ctime>
#include "maze.hpp"
#include "maze_node.hpp"
int main()
{
    srand((unsigned)time(nullptr));
    maze m;
    std::cout << "Maze size = " << m.size() << std::endl;
    char choice;
    bool escape =false;
    while(!escape)
    {
        std::cout << "You have started from " << m.get_entrance_loc() << std::endl;
        std::cout << "You are currently at " << m.get_current_loc() << std::endl;
        std::cout << "The exit is at " << m.get_exit_loc() << std::endl;
        do
        {
            std::cout << "Make your move...[Left],[Right],[Up],[Down],[Ahead],[Back],[Solution]\n: "; 
            std::cin >> choice;
            eat_line();
            choice = tolower(choice);
        }while(choice != 'l' && choice != 'r' && choice != 'u' && choice != 'd' && choice != 'a' && choice != 'b' && choice != 's');
        switch(choice)
        {
            case 'l':
                if(m.left())
                    speak("Moved left!");
                else
                    speak("Dead end...");
                break;
            case 'a': 
                if(m.ahead())
                    speak("Moved ahead!");
                else
                    speak("Dead end...");
                break;
            case 'u': 
                if(m.up())
                    speak("Moved up!");
                else
                    speak("Dead end...");
                break;
            case 'r':  
                if(m.right())
                    speak("Moved right!");
                else
                    speak("Dead end...");
                break;
            case 'b':  
                if(m.back())
                    speak("Moved back!");
                else
                    speak("Dead end...");
                break;
            case 'd': 
                if(m.down())
                    speak("Moved down!"); 
                else
                    speak("Dead end...");
                break;
            case 's':
                    speak("Here you go!");
                    m.solution();
                break;
        }
        std::cout << std::endl;
        escape = m.get_current_loc() == m.get_exit_loc();
    }
    std::cout << "Congrats! You have succesfully escaped the maze!" << std::endl;
    return 0;
}
