/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dperez-z <dperez-z@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:45:28 by dperez-z          #+#    #+#             */
/*   Updated: 2022/05/09 17:45:31 by dperez-z         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "nullptr.hpp"

namespace ft
{
    template <typename T>
    struct BST_Node
    {
        public :

            /* First template argument, the type of stocked value */
            typedef T   value_type;

            value_type value;
            BST_Node* parent;
            BST_Node* left;
            BST_Node* right;

            /*
            ** @brief Default.
            ** Create a BST_Node with default initisialized value.
            ** Left and right branch pointer to a "u_nullptr" (t_nullptr).
            */
            BST_Node ()
            :
                value(),
                parent(u_nullptr),
                left(u_nullptr),
                right(u_nullptr)
            {}

            /*
            ** @brief Default.
            ** Create a BST_Node with default initisialized value.
            ** Left and right branch pointer to a "u_nullptr" (t_nullptr).
            */
            BST_Node (BST_Node* parent = u_nullptr,
                    BST_Node* left = u_nullptr, BST_Node* right = u_nullptr)
            :
                value(),
                parent(parent),
                left(left),
                right(right)
            {}
            
            /*
            ** @brief Value.
            ** Create a BST_Node with value defined by a copy of "val".
            ** Left and right branch pointer to a "u_nullptr" (t_nullptr).
            **
            ** @param val the value to copy.
            */
            BST_Node (const value_type& val, BST_Node* parent = u_nullptr,
                    BST_Node* left = u_nullptr, BST_Node* right = u_nullptr)
            :
                value(val),
                parent(parent),
                left(left),
                right(right)
            {}

            /*
            ** @brief Copy.
            ** Create a BST_Node that a copy of "nd".
            ** The value is initalized by a copy of "nd" value.
            ** Left and right branch point to the same than "nb" branches.
            **
            ** @param nd the BST_Node to copy.
            */
            BST_Node (const BST_Node& nd)
            :
                value(nd.value),
                parent(nd.parent),
                left(nd.left),
                right(nd.right)
            {}

            virtual ~BST_Node() {}

            /*
            ** @brief Equal operator.
            ** Create a BST_Node that a copy of "nd".
            ** The value is initalized by a copy of "nd" value.
            ** Left and right branch point to the same than "nb" branches.
            **
            ** @param nd the BST_Node to copy.
            ** @return *this.
            */
            BST_Node &operator=(const BST_Node& nd)
            {
                if (nd == *this)
                    return (*this);
                
                this->value = nd.value;
                this->parent = nd.parent;
                this->left = nd.left;
                this->right = nd.right;
                
                return (*this);
            }

            /*
            ** @brief Compare two BST_Node to know
            ** if they contains the same value.
            **
            ** @param nd the BST_Node to compare.
            ** @return true if the value are the same,
            ** otherwise no.
            */
            bool operator==(const BST_Node& nd)
            {
                if (value == nd.value)
                    return (true);
                return (false);
            }
    };

    /* List Node : */
    template <class Data_T>
    struct Doubly_Linked_Node 
    {
        public :

            Doubly_Linked_Node  *prev;
            Doubly_Linked_Node  *next;
            Data_T              data;

            /*
            ** @brief Default:
            ** Create a node with next and prev
            ** value that pointing to u_nullptr.
            ** data is unitialized.
            */
            Doubly_Linked_Node()
            :
                prev(u_nullptr),
                next(u_nullptr)
            {}

            /*
            ** @brief Data init:
            ** Create a node with next and prev
            ** value that pointing to u_nullptr.
            ** data is itialized to "val".
            **
            ** @param val the data of this node.
            */
            Doubly_Linked_Node(const Data_T& val)
            :
                prev(u_nullptr),
                next(u_nullptr),
                data(val)
            {}

            /*
            ** @brief Init:
            ** Create a node with next and prev
            ** value that pointing to parameters "prev" & "next".
            ** data is itialized to "val".
            **
            ** @param val the data of this node.
            ** @param prev,next the previous and next node. 
            */
            Doubly_Linked_Node(const Data_T& val,
                Doubly_Linked_Node *prev, Doubly_Linked_Node *next)
            :
                prev(prev),
                next(next),
                data(val)
            {}
    };



}