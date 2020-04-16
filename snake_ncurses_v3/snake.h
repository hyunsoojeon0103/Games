#ifndef SNAKE_H 
#define SNAKE_H 
#include <cstdlib>
#include <ncurses.h>
#include "segment.h"
class Snake
{
    public:
        Snake(const unsigned short width, const unsigned short height);
        ~Snake();
        void grow(const unsigned short val);
        void move(const unsigned short mv);
        unsigned short get_x()const;
        unsigned short get_y()const;
        unsigned short length()const;
        char get_data()const;
        bool is_over()const;
        Segment<char>* get_tail_ptr()const;
        Segment<char>* get_head_ptr()const;
    private:
        Segment<char>* head;
        Segment<char>* tail;
        unsigned short snake_length;
        unsigned short board_height;
        unsigned short board_width;
        bool over;
};
#endif
