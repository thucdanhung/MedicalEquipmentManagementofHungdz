#include <iostream>
#include "../include/Management.h"

using namespace std;

int main() {
    Management app;
    string filename = "data/device_data.txt"; 
    
    app.loadFromFile(filename);

    int choice;
    do {
        cout << "\n==========================================" << endl;
        cout << "    HE THONG QUAN LY THIET BI Y TE" << endl;
        cout << "==========================================" << endl;
        cout << "1. Them thiet bi moi" << endl;
        cout << "2. Hien thi danh sach" << endl;
        cout << "3. Tim kiem theo ID" << endl;
        cout << "4. Xoa thiet bi" << endl;
        cout << "5. Sap xep theo Nam (Moi -> Cu)" << endl;
        cout << "6. Bao tri toan bo" << endl;
        cout << "7. Luu du lieu vao File" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        // made by Vu Viet Hung 202514168
        switch (choice) {
            case 1: app.addDevice(); break;
            case 2: app.displayAll(); break;
            case 3: app.searchById(); break;
            case 4: app.deleteById(); break;
            case 5: app.sortByYear(); break;
            case 6: app.maintenanceAll(); break;
            case 7: app.saveToFile(filename); break;
            case 0: 
                app.saveToFile(filename);
                cout << "Dang thoat chuong trinh..." << endl; 
                break;
            default: cout << "Lua chon khong hop le!" << endl;
        }
    } while (choice != 0);

    return 0;
}