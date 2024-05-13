//
// Created by antilopa on 13.05.24.
//

#ifndef DEBUGGING_H
#define DEBUGGING_H

#include <iostream>

class Menu{
private:
    struct message{
        int _last_number;
        std::string _last_value;
    };
    void (*menu_void) (int number, std::string value);
    message (*get_next_value) (){
        std::string name;
        std::cout << "Input your name: ";
        std::cin >> name;
        std::cout << "Your name: " << name << std::endl;

        char str[20];
        int i;

        sscanf(msg.c_str(), "%s %d", str, &i);
        printf("%s -> %d\n", str, i);
    };
public:
    void startMenu();
};


class View{
private:
    static const int count_menu = 5;
    Menu _menu [count_menu];
public:
    void StartView();
};

void View::StartView() {
    _menu[0].startMenu();

}

#endif //DEBUGGING_H
