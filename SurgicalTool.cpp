#include "../include/SurgicalTool.h"
#include <iostream>
#include <iomanip>

SurgicalTool::SurgicalTool(std::string id, std::string name, int year, std::string mat, int count)
    : Device(id, name, year), material(mat), usageCount(count) {}

void SurgicalTool::showStatus() const {
    std::cout << std::left << std::setw(10) << id 
              << std::setw(25) << name 
              << std::setw(10) << importYear 
              << std::setw(15) << "Surgical" 
              << "Mat: " << material << ", Used: " << usageCount << " times" << std::endl;
}

void SurgicalTool::performMaintenance() const {
    std::cout << "[MAINTENANCE] Tool " << name << ": Sterilizing at 120 degrees Celsius... Sharpening edges... DONE." << std::endl;
}
// made by Vu Viet Hung 202514168
std::string SurgicalTool::getType() const { return "TOOL"; }

std::string SurgicalTool::getExtraInfo() const { return material + "|" + std::to_string(usageCount); }