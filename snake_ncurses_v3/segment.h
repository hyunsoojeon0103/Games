#ifndef SEGMENT_H
#define SEGMENT_H
#include <cstdlib>

enum Direction {STOP,UP,RIGHT,LEFT,DOWN};

template <class T>
struct Segment
{
    Segment(const unsigned short xIn = 0, const unsigned short yIn = 0, const T& dataIn = T(),
            const Direction dirIn = STOP, Segment<T>* ptrIn = nullptr)
            :x(xIn),y(yIn),data(dataIn),dir(dirIn),next(ptrIn){}
    unsigned short x;
    unsigned short y;
    T data;
    Direction dir;
    Segment<T>* next;
};
#endif
