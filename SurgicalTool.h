#ifndef SURGICALTOOL_H
#define SURGICALTOOL_H

#include "Device.h"

class SurgicalTool : public Device {
private:
    std::string material;
    int usageCount;

public:
    SurgicalTool(std::string id, std::string name, int year, std::string mat, int count);

    void showStatus() const override;
    void performMaintenance() const override;
    std::string getType() const override;
    std::string getExtraInfo() const override;
};

#endif