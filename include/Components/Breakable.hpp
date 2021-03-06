/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-arthur.boucard
** File description:
** Breakable
*/

#ifndef BREAKABLE_HPP_
#define BREAKABLE_HPP_

#include "Components.hpp"

class Breakable : public Components {
    public:
        Breakable();
        ~Breakable();

        void link(int id);
        int getLink() const;
        void breakBrick();
    protected:
        int _link;
    private:
};

#endif /* !BREAKABLE_HPP_ */
