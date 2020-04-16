#include "snake.h"
Snake::Snake(const unsigned short width, const unsigned short height)
{
    head = new Segment<char>(width/2,height/2,'O');
    tail = head;
    snake_length = 1;
    over = false;
    board_width = width;
    board_height = height;
}
Snake::~Snake()
{
    Segment<char>* temp = head;
    while(head != nullptr)
    {
        temp = head->next;
        delete head;
        head = temp;
    }
}
void Snake::grow(const unsigned short val)
{
    snake_length += val;
    for(unsigned short i =0; i < val; ++i)
    {
        unsigned short x = tail->x;
        unsigned short y = tail->y;
        switch(tail->dir)
        {
            case Direction::LEFT: ++x;break;
            case Direction::RIGHT: --x;break;
            case Direction::UP: ++y; break;
            case Direction::DOWN: --y; break;
            case Direction::STOP:break;
        }
        tail->next = new Segment<char>(x,y,'o',tail->dir);
        tail = tail->next;
    }
}       
void Snake::move(const unsigned short mv)
{
    Direction prev = head->dir;
    if(mv != ERR)
        switch(mv)
        {
            case KEY_LEFT:
                head->dir = Direction::LEFT;break;
            case KEY_RIGHT:
                head->dir = Direction::RIGHT;break;
            case KEY_UP:
                head->dir = Direction::UP;break;
            case KEY_DOWN:
                head->dir = Direction::DOWN;break;
            case KEY_F(1):
                over = true;break;
        }
    Segment<char>* cursor = head;
    while(cursor != nullptr)
    {
        switch(cursor->dir)
        {
            case Direction::LEFT:
                cursor->x = (cursor->x - 1 > 0)? cursor->x - 1 : board_width - 2;break;
            case Direction::RIGHT:
                cursor->x = (cursor->x + 1 < board_width-1)? cursor->x + 1 : 1 ;break;
            case Direction::UP:
                cursor->y = (cursor->y - 1 > 0)? cursor->y - 1 : board_height - 2;break;
            case Direction::DOWN:
                cursor->y = (cursor->y + 1 < board_height-1)? cursor->y + 1 : 1; break;
            case Direction::STOP:break;
        }
        cursor = cursor->next;
        if(cursor != nullptr)
        {
            Direction curr = cursor->dir;
            cursor->dir = prev;
            prev = curr;
        }
    }
}
unsigned short Snake::get_x()const
{
    return head->x;
}
unsigned short Snake::get_y()const
{
    return head->y;
}
unsigned short Snake::length()const
{
    return snake_length; 
}
char Snake::get_data()const
{
    return head->data;
}
bool Snake::is_over()const
{
    return over;
}
Segment<char>* Snake::get_tail_ptr()const
{
    return tail;
}
Segment<char>* Snake::get_head_ptr()const
{
    return head;
}
