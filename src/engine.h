/*Bebtek engine v3*/
/*More optimized and faster version of Bebtek engine v2*/
/*Created Sept 7th, 2024*/

#include <iostream>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <cstdlib>
#include <termios.h>
#include <string>
#include "Savegame.h"
#include "Inventory.h"

class Engine {
public:
    void waitForInput() {
        setTerminalMode();
        std::string input;
        while (true) {
            printf("> ");
            std::getline(std::cin, input);
            if (input == "help") {
                printf("#---------------------------------------------#\n");
                printf("| 'help' - Print help sheet                   |\n");
                printf("| 'inventory' - Print inventory               |\n");
                printf("|                                             |\n");
                printf("|                                             |\n");
                printf("|                                             |\n");
                printf("| 'save/load' - Save or Load save game data   |\n");
                printf("| 'exit' - Exit the game                      |\n");
                printf("#---------------------------------------------#\n");
            } else if (input == "exit") {
                system("clear");
                break;
            } else if (input == "save") {
                SaveGame();
            } else if (input == "load") {
                LoadGame();
            } else if (input == "inventory") {
                printInventory();
            } else if (input == "clear") {
                system("clear");
            } else {
                //std::cout << "Unknown command..." << std::endl;
            }
        }
        restoreTerminalMode();
    }
private:
    struct termios originalTermios;

    void setTerminalMode() {
        tcgetattr(STDIN_FILENO, &originalTermios);

        struct termios newTermios = originalTermios;
        /*Uncomment these 2 lines below if you don't want to see input commands*/
        //newTermios.c_lflag &= ~ICANON; // Disable canonical mode
        //newTermios.c_lflag &= ~ECHO;   // Disable echoing input characters

        tcsetattr(STDIN_FILENO, TCSANOW, &newTermios);
    }

    void restoreTerminalMode() {
        tcsetattr(STDIN_FILENO, TCSANOW, &originalTermios);
    }
};
