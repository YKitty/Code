#pragma once 

#include <iostream>
#include <ncurses.h>

#define SIZE 1024
class window 
{
  public:
    window();
    void draw_header();
    void draw_ouput();
    void draw_flist();
    void draw_input();
    WINDOW* get_header();
    WINDOW* get_list();
    WINDOW* get_output();
    WINDOW* get_input();
    ~window();
  private:
    WINDOW* header;
    WINDOW* output;
    WINDOW* flist;
    WINDOW* input;
};
