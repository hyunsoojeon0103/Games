#include "fruit.h"
Fruit::Fruit(const unsigned short width_in,const unsigned short height_in)
    :width(width_in),height(height_in)
{
    regenerate();
}
void Fruit::regenerate()
{
    fruit.x = rand() % (width -2) + 1;
    fruit.y = rand() % (height-2) + 1;
    fruit.data = rand() % 3 + 1;
}
unsigned short Fruit::get_data()const
{
    return fruit.data;
}
unsigned short Fruit::get_x()const
{
    return fruit.x;
}
unsigned short Fruit::get_y()const
{
    return fruit.y;
}
