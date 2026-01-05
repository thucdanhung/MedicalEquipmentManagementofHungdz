#include "../include/ImagingDevice.h"
#include <iostream>
#include <iomanip>

ImagingDevice::ImagingDevice(std::string id, std::string name, int year, std::string res, std::string date)
    : Device(id, name, year), resolution(res), lastUpdateDate(date) {}

void ImagingDevice::showStatus() const {
    std::cout << std::left << std::setw(10) << id 
              << std::setw(25) << name 
              << std::setw(10) << importYear 
              << std::setw(15) << "Imaging" 
              << "Res: " << resolution << ", Updated: " << lastUpdateDate << std::endl;
}

void ImagingDevice::performMaintenance() const {
    std::cout << "[MAINTENANCE] Device " << name << ": Updating Firmware... Calibrating Sensor... DONE." << std::endl;
}

std::string ImagingDevice::getType() const { return "IMG"; }

std::string ImagingDevice::getExtraInfo() const { return resolution + "|" + lastUpdateDate; }