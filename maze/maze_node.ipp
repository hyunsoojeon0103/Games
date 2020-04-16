template <class T>
maze_node<T>::maze_node()
{
    for(unsigned short i =0; i < MAX_DIRECTION; ++i)
        way[i] = nullptr;
}
template <class T>
maze_node<T>*& maze_node<T>::operator[](const unsigned short way_in)
{
    return way[way_in];
}
