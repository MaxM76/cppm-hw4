#include <iostream>
#include <fstream>
#include <Windows.h>

class Address {
private:
    std::string town;
    std::string street;
    int building;
    int flat;
public:
    Address() {
        building = 0;
        flat = 0;
    }

    Address(std::string aTown, std::string aStreet, int aBuilding, int aFlat) {
        town = aTown;
        street = aStreet;
        building = aBuilding;
        flat = aFlat;
    }

    std::string getTown() {
        return town;
    }

    std::string getStreet() {
        return street;
    }

    int getBuilding() {
        return building;
    }

    int getFlat() {
        return flat;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int addressesCount = 0;
    std::string aTown;
    std::string aStreet;
    int aBuilding = 0;
    int aFlat = 0;

    std::ifstream fin("in.txt");
    if (fin.is_open()) {
        fin >> addressesCount;
        if (addressesCount > 0) {
            Address* addressesArray = new Address[addressesCount];
            for (int i = 0; i < addressesCount; i++) {
                fin >> aTown;
                fin >> aStreet;
                fin >> aBuilding;
                fin >> aFlat;
                addressesArray[i] = Address(aTown, aStreet, aBuilding, aFlat);
            }
            fin.close();

            for (int i = 0; i < addressesCount - 1; i++) {
                for (int j = i + 1; j < addressesCount; j++) {
                    if (addressesArray[j].getTown() < addressesArray[i].getTown()) {
                        std::swap(addressesArray[i], addressesArray[j]);
                    }
                }
            }

            std::ofstream fout("out.txt");
            fout << addressesCount;
            for (int i = 0; i < addressesCount; i++) {
                fout << "\n"
                    << addressesArray[i].getTown() << ", "
                    << addressesArray[i].getStreet() << ", "
                    << addressesArray[i].getBuilding() << ", "
                    << addressesArray[i].getFlat();
            }
            fout.close();
            delete[] addressesArray;
        }
    }
}