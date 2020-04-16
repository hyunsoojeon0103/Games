#ifndef ANIMAL_HPP__
#define ANIMAL_HPP__
#include <cstdlib>
#include "bst_node.hpp"
template <class T>
class animal
{
    public:
        animal(const T& question,const T& name1,const T& name2);
        ~animal();
        const T& guess()const;
        bool is_leaf()const;
        void move_right();
        void move_left();
        void learn(const T& name, const T& description);
        void reset();
    protected:
        bst_node<T>* find_parent(bst_node<T>* parent);
        void clear(bst_node<T>* nd);
    private:
        bst_node<T>* root;
        bst_node<T>* cursor;
};
#include "animal.ipp"
#endif
