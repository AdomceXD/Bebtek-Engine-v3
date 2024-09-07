#include "Save.h"
#include <fstream>
#include <iostream>

void SaveGame() {
    std::ofstream saveFile("save.txt");
    if (saveFile.is_open()) {
        saveFile << item1 << "\n";
        saveFile.close();
        std::cout << "Game saved successfully!\n";
    } else {
        std::cerr << "Unable to open file for saving!\n";
    }
}

void LoadGame() {
    std::ifstream loadFile("save.txt");

    if (loadFile.is_open()) {
        loadFile >> item1;
        loadFile.ignore();
        loadFile.close();
        std::cout << "Game loaded successfully!\n";
    } else {
        std::cerr << "Unable to open file for loading!\n";
    }
}
