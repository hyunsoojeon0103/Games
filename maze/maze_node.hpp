#ifndef MAZENODE__H
#define MAZENODE__H
#include <cstdlib>
enum DIR {BACK=0,LEFT=1,UP=2,AHEAD=3,RIGHT=4,DOWN=5};
template <class T>
class maze_node
{
    public:
        static const unsigned short MAX_DIRECTION = 6;
        maze_node();
        maze_node*& operator[](const unsigned short way_in); 
    private:
        maze_node* way[MAX_DIRECTION];
};
#include "maze_node.ipp"
#endif
