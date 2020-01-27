#include "maze.hpp"
const unsigned short maze::MAZE_SIZE = 1000;
maze::maze()
    :ctr(0),entrance(nullptr),exit(nullptr)
    ,curr(nullptr)
{
    for(size_t i = 0; i < MAZE_SIZE; ++i)
    {
        mazenode* prev = nullptr;
        maze_gene(prev,curr);
    }
    entrance = curr;
}
bool maze::left()
{
    if((*curr)[LEFT] == nullptr)
        return false;
    curr = (*curr)[LEFT];
    return true;
}
bool maze::ahead()
{
    if((*curr)[AHEAD] == nullptr)
        return false;
    curr = (*curr)[AHEAD];
    return true;
}
bool maze::up()
{
    if((*curr)[UP] == nullptr)
        return false;
    curr = (*curr)[UP];
    return true;
}
bool maze::right()
{
    if((*curr)[RIGHT] == nullptr)
        return false;
    curr = (*curr)[RIGHT];
    return true;
}
bool maze::back()
{
    if((*curr)[BACK] == nullptr)
        return false;
    curr = (*curr)[BACK];
    return true;
}
bool maze::down()
{
    if((*curr)[DOWN] == nullptr)
        return false;
    curr = (*curr)[DOWN];
    return true;
}
unsigned short maze::size()const
{
    return ctr;
}
void maze::look_back()
{
    display(path);    
}
void maze::solution()
{
    std::stack<unsigned short> res;
    mazenode* cursor = curr;
    backtrack(res,cursor);
    display(res);    
}
maze::mazenode* maze::get_current_loc()const
{
    return curr;
}
maze::mazenode* maze::get_entrance_loc()const
{
    return entrance;
}
maze::mazenode* maze::get_exit_loc()const
{
    return exit;
}
void  maze::maze_gene(mazenode* prv, mazenode*& cur,unsigned short prev_dir)
{
    unsigned short new_dir = rand() % mazenode::MAX_DIRECTION;
    prev_dir = (cur == nullptr)? prev_dir: new_dir;
    if(cur == nullptr)
    {
        cur = new mazenode();
        if(ctr == MAZE_SIZE -1)
            exit = cur;
        if(prv != nullptr)
            (*cur)[opposite_dir(prev_dir)] = prv;
        ++ctr;
        return;
    }
    prv = cur;
    if(ctr == MAZE_SIZE - 1)
    {
        if(!path.empty() && new_dir == opposite_dir(path.top()))
            path.pop();
        else
            path.push(new_dir);
    }
    maze_gene(prv,(*cur)[new_dir],prev_dir);
}
unsigned short maze::opposite_dir(const unsigned short index)const
{
    return (index + mazenode::MAX_DIRECTION / 2) % mazenode::MAX_DIRECTION;
}
bool maze::backtrack(std::stack<unsigned short>& res,mazenode* cursor,const mazenode* prev)
{
    if(cursor == exit)
        return true;
    else if(cursor != nullptr)
        for(unsigned short i =0; i < mazenode::MAX_DIRECTION; ++i)
            if((*cursor)[i] != nullptr && (*cursor)[i] != prev)
            {
                res.push(i);
                if (backtrack(res,(*cursor)[i],cursor))
                    return true;
                else
                    res.pop();
            }
    return false;
}
void display(std::stack<unsigned short> st)
{
    std::stack<unsigned short> reverse;
    while(!st.empty())
    {
        reverse.push(st.top());
        st.pop();
    }
    while(!reverse.empty())
    {
        switch(reverse.top())
        {
            case BACK: std::cout << "BACK"; break;
            case LEFT: std::cout << "LEFT"; break;
            case UP: std::cout << "UP"; break;
            case AHEAD: std::cout << "AHEAD"; break;
            case RIGHT: std::cout << "RIGHT"; break;
            case DOWN: std::cout << "DOWN"; break;
            default: std::cout << "PROBLEM";break;
        }
        reverse.pop();
        if(!reverse.empty())
            std::cout << " -> ";
    }
    std::cout << std::endl;
}
void eat_line()
{
    char tmp;
    do
        std::cin.get(tmp);
    while(tmp != '\n');
}
void speak(const char* words)
{
    std::cout << '\n' << words << std::endl;
}
