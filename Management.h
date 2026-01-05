#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <vector>
#include <string>
#include "Device.h"

class Management {
private:
    std::vector<Device*> list;
    // made by Vu Viet Hung 202514168
    std::vector<std::string> split(std::string s, std::string delimiter);

public:
    Management();
    ~Management();

    void addDevice();
    void displayAll();
    void searchById();
    void deleteById();
    void sortByYear();
    void maintenanceAll();
    
    void saveToFile(std::string filename);
    void loadFromFile(std::string filename);
};

#endif