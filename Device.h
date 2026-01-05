#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <iostream>

class Device {
protected:
    std::string id;
    std::string name;
    int importYear;

public:
    Device(std::string id, std::string name, int year);
    virtual ~Device(); 

    std::string getId() const;
    std::string getName() const;
    int getYear() const;

    void setName(std::string n);
    void setYear(int y);

    virtual void showStatus() const = 0;
    virtual void performMaintenance() const = 0;
    // anti copy Vu Viet Hung 202514168
    virtual std::string getType() const = 0;
    virtual std::string getExtraInfo() const = 0;
};

#endif