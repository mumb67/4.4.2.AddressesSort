#include <iostream>
#include <string>
#include <fstream>

class Addresses {
public:
	Addresses(std::string _city, std::string _street, int _houseNum, int _apartmentNum) {
		this->city = _city;
		this->street = _street;
		this->houseNum = _houseNum;
		this->apartmentNum = _apartmentNum;
	}

	Addresses() {
		city = " ";
		street = " ";
		houseNum = 0;
		apartmentNum = 0;
	}

	std::string get_output_address() {
		return city + ", " + street + ", " + std::to_string(houseNum) + ", " + std::to_string(apartmentNum);
	}

private:
	std::string city;
	std::string street;
	int houseNum;
	int apartmentNum;
};

int main()
{
	setlocale(LC_ALL, "rus");

	std::ifstream inFile("in.txt");
	std::ofstream outFile("out.txt");

	std::string tempStr;
	inFile >> tempStr;

	const int countAdd = std::stoi(tempStr);
	outFile << countAdd << std::endl;

	Addresses* addresses = new Addresses[countAdd];

	for (int i = 0; i < countAdd; i++) {
		std::string tempCity;
		std::string tempStreet;
		int tempHouse;
		int tempApart;

		inFile >> tempCity;
		inFile >> tempStreet;
		inFile >> tempHouse;
		inFile >> tempApart;
		addresses[i] = Addresses(tempCity, tempStreet, tempHouse, tempApart);
	}

	for (int i = 0; i < countAdd; i++) {
		for (int j = 0; j < countAdd; j++) {
			if (addresses[i].get_output_address() < addresses[j].get_output_address()) {
				Addresses temp = addresses[i];
				addresses[i] = addresses[j];
				addresses[j] = temp;
			}
		}
	}

	for (int i = 0; i < countAdd; i++) {
		outFile << addresses[i].get_output_address() << std::endl;
	}

	inFile.close();
	outFile.close();
	delete[]addresses;
}