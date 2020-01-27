template <class T>
bst_node<T>::bst_node(const T& data_in, bst_node* lptr,bst_node* rptr)
    :data(data_in),left(lptr),right(rptr)
{    
}
template <class T>
const T& bst_node<T>::get_data()const
{
    return data;
}
template <class T>
bst_node<T>* bst_node<T>::get_left()const
{
    return left;
}
template <class T>
bst_node<T>* bst_node<T>::get_right()const
{
    return right;
}
template <class T>
void bst_node<T>::set_left(const T& data_in)
{
    assert(left == nullptr);
    left = new bst_node<T>(data_in);
}
template <class T>
void bst_node<T>::set_right(const T& data_in)
{
    assert(right == nullptr);
    right = new bst_node<T>(data_in);
}
template <class T>
void bst_node<T>::set_data(const T& data_in)
{
    data = data_in;
}
