#ifndef MAZE_H__
#define MAZE_H__
#include <cstdlib>
#include <stack>
#include <iostream>
#include "maze_node.hpp"
class maze
{
    public:
        typedef maze_node<char*> mazenode;
        static const unsigned short MAZE_SIZE;
        maze();
        bool left();
        bool ahead() ;
        bool up();
        bool right();
        bool back();
        bool down();
        unsigned short size()const;
        void look_back();
        void solution();
        mazenode* get_current_loc()const;
        mazenode* get_entrance_loc()const;
        mazenode* get_exit_loc()const;
    protected:
        void maze_gene(mazenode* prv, mazenode*& cur,unsigned short prev_dir = 0);
        unsigned short opposite_dir(const unsigned short index)const;
        bool backtrack(std::stack<unsigned short>& res,mazenode* c,const mazenode* p=nullptr);
    private:
        unsigned short ctr;
        std::stack<unsigned short> path;
        mazenode* entrance;
        mazenode* exit;
        mazenode* curr;
};
void display(std::stack<unsigned short> st);
void eat_line();
void speak(const char* words);
#endif
