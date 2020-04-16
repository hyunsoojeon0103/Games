#ifndef BST_NODE_HPP__
#define BST_NODE_HPP__
#include <cstdlib>
#include <cassert>
template <class T>
class bst_node
{
    public:
        bst_node(const T& data_in = T(), bst_node* lptr = nullptr,bst_node* rptr = nullptr);
        const T& get_data()const;
        bst_node* get_left()const;
        bst_node* get_right()const;
        void set_left(const T& data_in);
        void set_right(const T& data_in);
        void set_data(const T& data_in);
    private:
        T data;
        bst_node* left;
        bst_node* right;
};
#include "bst_node.ipp"
#endif
