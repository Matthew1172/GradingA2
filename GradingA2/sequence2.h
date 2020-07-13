// FILE: sequence2.h
// CLASS PROVIDED: sequence (a container class for a sequence of items,
// where each sequence may have a designated item called the current item)
//
// TYPEDEF for the sequence class:
//   typedef ____ value_type
//     sequence::value_type is the data type of the items in the sequence. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and a copy constructor.
//
// CONSTRUCTOR for the sequence class:
//   sequence( )
//     Postcondition: The sequence has been initialized as an empty sequence.
//
// MODIFICATION MEMBER FUNCTIONS for the sequence class:
//   void start( )
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
//
//   void advance( )
//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item on the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence before
//     the current item. If there was no current item, then the new entry has 
//     been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void attach(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has 
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
//   void remove_current( )
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.
//
// CONSTANT MEMBER FUNCTIONS for the sequence class:
//   size_t size( ) const
//     Postcondition: The return value is the number of items on the sequence.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item on the sequence.
//
// VALUE SEMANTICS for the sequence class:
//    Assignments and the copy constructor may be used with sequence objects.
//
// DYNAMIC MEMORY USAGE by the sequence:
//   If there is insufficient dynamic memory, then the following functions call
//   new_handler: The constructors, insert, attach, and the
//   assignment operator.

#ifndef ASSIGNMENT_SEQUENCE2_H
#define ASSIGNMENT_SEQUENCE2_H
#include<iostream>
#include <cstdlib> // Provides size_t and NULL
#include "node2.h"   // Provides linked list toolkit

namespace assignment_sequence2
{

    class sequence
    {
    public:
        // TYPEDEF
        typedef size_t size_type; //typedef std::size_t size_type;
        typedef node::value_type value_type;
        // CONSTRUCTORS and DESTRUCTOR
        sequence();
        sequence(const sequence& source);
        ~sequence();
        // MODIFICATION MEMBER FUNCTIONS
        void start();
        void end();
        void advance();
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current();
        void operator =(const sequence& source);
        // CONSTANT MEMBER FUNCTIONS
        size_t size() const;
        bool is_item() const;
        value_type current() const;

        void printAll() {
            if (many_nodes < 1) std::cout << "no nodes" << std::endl;
            for (const node* c = head_ptr; c != NULL; c = c->link()) {
                std::cout << c->data() << std::endl;
            }
        }
        void printH() {
            std::cout << "HEAD" << std::endl;
            std::cout << head_ptr->data() << std::endl;
            std::cout << "----------HEAD--------------" << std::endl;
        }
        void printT() {
            std::cout << "TAIL" << std::endl;
            std::cout << tail_ptr->data() << std::endl;
            std::cout << "----------TAIL------------" << std::endl;
        }
        void printP() {
            if (!is_item()) return;
            std::cout << "PRECURSOR" << std::endl;
            std::cout << pre->data() << std::endl;
            std::cout << "----------PRECURSOR------" << std::endl;
        }
        void printC() {
            if (!is_item()) return;
            std::cout << "CURRENT" << std::endl;
            std::cout << current_ptr->data() << std::endl;
            std::cout << "----------CURRENT------" << std::endl;
        }

    private:
        node* current_ptr;    //
        node* head_ptr;       // List head pointer
        node* tail_ptr;       // List head pointer
        node* pre;
        size_type many_nodes; // Number of nodes on the list
    };
}

#endif