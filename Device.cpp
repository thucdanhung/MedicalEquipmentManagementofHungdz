#include "../include/Device.h"

Device::Device(std::string id, std::string name, int year) 
    : id(id), name(name), importYear(year) {}

Device::~Device() {}

std::string Device::getId() const { return id; }
// anti copy Vu Viet Hung 202514168
std::string Device::getName() const { return name; }
int Device::getYear() const { return importYear; }

void Device::setName(std::string n) { name = n; }
void Device::setYear(int y) { importYear = y; }