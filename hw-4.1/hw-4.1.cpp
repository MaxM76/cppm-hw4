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

    Address(std::string aTown, std::string aStreet, int aBuilding, int aFlat) {
        town = aTown;
        street = aStreet;
        building = aBuilding;
        flat = aFlat;
    }

    ~Address() {

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
    int aBuilding;
    int aFlat;

    std::ifstream fin("in.txt");
    if (fin.is_open()) {
        fin >> addressesCount;
        if (addressesCount > 0) {
            Address* addressesArray = (Address*)operator new(sizeof(Address) * addressesCount);
            for (int i = 0; i < addressesCount; i++) {
                fin >> aTown;
                fin >> aStreet;
                fin >> aBuilding;
                fin >> aFlat;
                new(&addressesArray[i]) Address(aTown, aStreet, aBuilding, aFlat);
            }
            fin.close();

            std::ofstream fout("out.txt");
            fout << addressesCount;
            for (int i = addressesCount - 1; i > -1; i--) {
                fout << "\n"
                    << addressesArray[i].getTown() << ", "
                    << addressesArray[i].getStreet() << ", "
                    << addressesArray[i].getBuilding() << ", "
                    << addressesArray[i].getFlat();
            }
            fout.close();
            for (int i = 0; i < addressesCount; i++) {
                addressesArray[i].~Address();
            }
            operator delete(addressesArray);
        }
    }
}