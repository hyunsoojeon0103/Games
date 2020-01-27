template <class T>
animal<T>::animal(const T& question,const T& name1,const T& name2)
{
    root = new bst_node<T>(question);
    cursor = root;
    root->set_left(name1);
    root->set_right(name2);
}
template <class T>
animal<T>::~animal()
{
    clear(root);
}
template <class T>
const T& animal<T>::guess()const
{
    return cursor->get_data();
}
template <class T>
bool animal<T>::is_leaf()const
{
    return cursor->get_left() == nullptr && cursor->get_right() == nullptr;
}
template <class T>
void animal<T>::move_right()
{
    cursor = cursor->get_right();
}
template <class T>
void animal<T>::move_left()
{
    cursor = cursor->get_left();
}
template <class T>
void animal<T>::learn(const T& name, const T& description)
{
    cursor->set_left(cursor->get_data());
    cursor->set_right(name);
    cursor->set_data(description);
}
template <class T>
void animal<T>::reset()
{
    cursor = root;
}
template <class T>
bst_node<T>* animal<T>::find_parent(bst_node<T>* parent)
{
    if(parent == nullptr)
        return nullptr;
    else if(parent->get_left() == cursor || parent->get_right() == cursor)
        return parent;
    bst_node<T>* left = find_parent(parent->get_left()); 
    return left == nullptr ? find_parent(parent->get_right()) : left;
}
template <class T>
void animal<T>::clear(bst_node<T>* nd)
{
    if(nd == nullptr)
        return;
    clear(nd->get_left());
    clear(nd->get_right());
    delete nd;
    nd = nullptr;
}
