#ifndef SHASHKI_H
#define SHASHKI_H
#include <iostream>
#include <vector>
#include "vandak.h"

class Shashki{
    public:
    Shashki();
    private:
    void start();
    void enter_index();
    bool check_at(int,int);
    bool check_to(int,int);
    void check_win();
    char vandak[8][8];
    char figur;
    bool state;
    int at_index1;
    int at_index2;
    int to_index1;
    int to_index2;
    bool count;
};






#endif//SHASHKI_H
