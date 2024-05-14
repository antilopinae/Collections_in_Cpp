//
// Created by antilopa on 13.05.24.
//

#ifndef DEBUGGING_H
#define DEBUGGING_H

#include <iostream>
#include "ListSequence.h"
#include "ArraySequence.h"

struct message{
    int _last_number;
    std::string _last_value;
};

typedef void (*render_menu) ();
typedef int (*menu_void) (message* mes);
typedef void(*change_menu)(int menu);

class Menu{
private:
    message* get_next_value (){
        char str[20];
        int i;
        std::string msg;
        getline(std::cin, msg);
        sscanf("%s %d", str, &i);
        printf("%d", i);
        return new message{i, msg};
    };
    render_menu _render_menu;
    menu_void _menu_void;
    change_menu _change_menu;
public:
    Menu(render_menu _render, menu_void _void, change_menu _change){
        this->_render_menu = _render;
        this->_menu_void = _void;
        this->_change_menu= _change;
    };
    void startMenu(){
        _render_menu();
        message* mes = get_next_value();
        int res;
        while(mes->_last_number != 0){
            _render_menu();
            mes = get_next_value();
            res = _menu_void(mes);
            if(res < 0) break;
        }
        _change_menu(res*(-1));
    };
};

class View{
private:
    static const int count_menu = 3;
//    const Menu* _menu[];

    static void start_menu_view(){

    }

    static int start_menu_void(message* mes){

    }

    static void delete_menu_view(){

    }

    static int delete_menu_void(message* mes){

    }

    static void create_menu_view(){

    }

    static int create_menu_void(message* mes){

    }
public:
    static void change_menu(int num){
//        _menu[num]->startMenu();
    };
//    View(): _menu(){

//        _menu = new Menu(&start_menu_view, &start_menu_void, &change_menu);

//        _menus = {
//                new Menu(&start_menu_view, &start_menu_void, &View::change_menu), //start
//                new Menu(&delete_menu_view, &delete_menu_void, &View::change_menu), //delete
//                new Menu(&create_menu_view, &create_menu_void, &View::change_menu) //create
//        }
//    };
    void StartView(){
        change_menu(0);
    };
};


#endif //DEBUGGING_H
