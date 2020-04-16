#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include "segment.h"
#include "snake.h"
#include "fruit.h"
WINDOW* create_window(const unsigned short height, const unsigned short width, const unsigned short start_y, const unsigned short start_x);
int main()
{
    srand((unsigned)time(nullptr));

    initscr(); // start curse mode
    cbreak(); // line buffering disabled
    refresh(); // print it onto the real screen
    noecho();  // no echo while getch()

    //unsigned short x,y;
    //getmaxyx(stdscr,y,x); // get the num of rows and cols
    const unsigned short WIDTH = COLS * 0.8;
    const unsigned short HEIGHT = LINES * 0.8;
    const unsigned short START_X = (COLS-WIDTH) / 2;
    const unsigned short START_Y = (LINES-HEIGHT) / 2;

    WINDOW* board = create_window(HEIGHT,WIDTH,START_Y,START_X);
    WINDOW* info = create_window(START_Y, WIDTH, 0, START_X);

    wtimeout(board,50); // same as nodelay but when the number is positive, it delays that milliseconds
    keypad(board,true); // I need that nifty F1 && keyboard arrows 
    curs_set(false); // hide the cursor from the screen

    Snake sn(WIDTH,HEIGHT);
    Fruit fr(WIDTH,HEIGHT);

    while(!sn.is_over())
    {
        Segment<char>* cursor = sn.get_head_ptr();
        while(cursor != nullptr)
        {
            mvwprintw(board,cursor->y,cursor->x,"%c",cursor->data);
            cursor = cursor->next;
        }
        
        mvwprintw(board,fr.get_y(),fr.get_x(),"%d",fr.get_data()); // equavalent to mvprintw but move (y,x) relative to window
        mvwprintw(info,1,1,"Snake Length:\t%2d\tCoordinate: (%3d,%3d)\t\t\tPress F1 to exit",
                    sn.length(),sn.get_x(),sn.get_y());// print coordinates to help debug
        wrefresh(info);
        
        unsigned short move = wgetch(board);    
        sn.move(move);
        
        if(fr.get_x() == sn.get_x() && fr.get_y() == sn.get_y())
        {
            sn.grow(fr.get_data());
            fr.regenerate();
        }

        werase(board);
        werase(info);
        box(board,0,0); // 0,0 gives default characters for the border
        box(info,0,0);
    }

    delwin(board); // destroy windows
    delwin(info);
    endwin(); // end curses mode
    
    return 0;
}
WINDOW* create_window(const unsigned short height, const unsigned short width, const unsigned short start_y, const unsigned short start_x)
{
    WINDOW* window = newwin(height,width,start_y,start_x); // calculate the center
    wrefresh(window); // show the box
    return window;
}
