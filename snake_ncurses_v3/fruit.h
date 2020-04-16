#ifndef FRUIT_H
#define FRUIT_H
#include <cstdlib>
#include "segment.h"
class Fruit
{
    public:
        Fruit(const unsigned short width,const unsigned short height);
        void regenerate();
        unsigned short get_data()const;
        unsigned short get_x()const;
        unsigned short get_y()const;
    private:
        Segment<unsigned short> fruit;
        unsigned short width;
        unsigned short height;
};
#endif
