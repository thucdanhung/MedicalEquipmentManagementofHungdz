#include "../include/Management.h"
#include "../include/ImagingDevice.h"
#include "../include/SurgicalTool.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

Management::Management() {}

Management::~Management() {
    for (Device* dev : list) {
        delete dev;
    }
    list.clear();
}

vector<string> Management::split(string s, string delimiter) {
    // ani copy Vu Viet Hung 202514168
    vector<string> tokens;
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);
    return tokens;
}

void Management::addDevice() {
    int choice;
    string id, name, res, date, mat;
    int year, usage;

    cout << "\n--- THEM THIET BI MOI ---" << endl;
    cout << "1. May Chan Doan Hinh Anh (Imaging Device)" << endl;
    cout << "2. Dung Cu Phau Thuat (Surgical Tool)" << endl;
    cout << "Chon loai: "; cin >> choice;

    cout << "Nhap ID: "; cin >> id;
    for(auto dev : list) {
        if(dev->getId() == id) {
            cout << "Loi: ID da ton tai!" << endl;
            return;
        }
    }

    cin.ignore();
    cout << "Nhap Ten: "; getline(cin, name);
    cout << "Nhap Nam Nhap Khau: "; cin >> year;

    if (choice == 1) {
        cin.ignore();
        cout << "Nhap Do Phan Giai (VD: 4K): "; getline(cin, res);
        cout << "Nhap Ngay Cap Nhat (dd/mm/yyyy): "; getline(cin, date);
        list.push_back(new ImagingDevice(id, name, year, res, date));
    } else if (choice == 2) {
        cin.ignore();
        cout << "Nhap Chat Lieu: "; getline(cin, mat);
        cout << "Nhap So Lan Su Dung: "; cin >> usage;
        list.push_back(new SurgicalTool(id, name, year, mat, usage));
    } else {
        cout << "Lua chon khong hop le!" << endl;
    }
    cout << "Them thanh cong!" << endl;
}

void Management::displayAll() {
    if (list.empty()) {
        cout << "\nDanh sach trong!" << endl;
        return;
    }
    cout << "\n--- DANH SACH THIET BI ---" << endl;// made by Vu Viet Hung 202514168
    cout << left << setw(10) << "ID" << setw(25) << "TEN THIET BI" << setw(10) << "NAM" << setw(15) << "LOAI" << "THONG TIN KHAC" << endl;
    cout << string(90, '-') << endl;
    for (const auto& dev : list) {
        dev->showStatus();
    }
}

void Management::searchById() {
    string id;
    cout << "Nhap ID can tim: "; cin >> id;
    bool found = false;
    for (const auto& dev : list) {
        if (dev->getId() == id) {
            cout << "\nKET QUA TIM KIEM:" << endl;
            dev->showStatus();
            found = true;
            break;
        }
    }
    if (!found) cout << "Khong tim thay thiet bi co ID: " << id << endl;
}

void Management::deleteById() {
    string id;
    cout << "Nhap ID can xoa: "; cin >> id;
    for (auto it = list.begin(); it != list.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            list.erase(it);
            cout << "Da xoa thiet bi " << id << " thanh cong." << endl;
            return;
        }
    }
    cout << "Khong tim thay ID!" << endl;
}

void Management::sortByYear() {
    sort(list.begin(), list.end(), [](Device* a, Device* b) {
        return a->getYear() > b->getYear();
    });
    cout << "Da sap xep danh sach theo nam nhap khau (Moi -> Cu)." << endl;
    displayAll();
}

void Management::maintenanceAll() {
    cout << "\n--- BAT DAU BAO TRI HE THONG ---" << endl;
    for (const auto& dev : list) {
        dev->performMaintenance();
    }
}

void Management::saveToFile(string filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Loi: Khong the tao file!" << endl;
        return;
    }
    for (const auto& dev : list) {
        outFile << dev->getType() << "|" 
                << dev->getId() << "|" 
                << dev->getName() << "|" 
                << dev->getYear() << "|" 
                << dev->getExtraInfo() << endl;
    }
    outFile.close();
    cout << "Da luu du lieu vao file " << filename << endl;
}

void Management::loadFromFile(string filename) {
    ifstream inFile(filename);
    if (!inFile) {
        return; 
    }

    for (Device* dev : list) delete dev;
    list.clear();

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        vector<string> data = split(line, "|");
        
        if (data.size() < 5) continue; 

        string type = data[0];
        string id = data[1];
        string name = data[2];
        int year = stoi(data[3]);

        if (type == "IMG") {
            string res = data[4];
            string date = (data.size() > 5) ? data[5] : "N/A";
            list.push_back(new ImagingDevice(id, name, year, res, date));
        } else if (type == "TOOL") {
            string mat = data[4];
            int usage = (data.size() > 5) ? stoi(data[5]) : 0;
            list.push_back(new SurgicalTool(id, name, year, mat, usage));
        }
    }
    inFile.close();
    cout << "Da tai du lieu tu file thanh cong (" << list.size() << " ban ghi)." << endl;
}