#ifndef IMAGINGDEVICE_H
#define IMAGINGDEVICE_H

#include "Device.h"

class ImagingDevice : public Device {
private:
    std::string resolution;
    std::string lastUpdateDate;

public:
    ImagingDevice(std::string id, std::string name, int year, std::string res, std::string date);

    void showStatus() const override;
    void performMaintenance() const override;
    std::string getType() const override;
    std::string getExtraInfo() const override;
};

#endif