
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

struct Parts {
	int id = NULL;
	string description = "";
};

int main()
{
	int id, num, fileSize;
	string carPartDescription, misc;
	Parts newPart;
	vector<Parts> carPartVector;
	vector<int> v;
	ifstream inFile;
	ofstream outFile;
	inFile.open("file.txt");

	
	// reading in integers from file.txt
	while (inFile >> num) {
		v.push_back(num);
	}
	v.push_back(909);
	v.push_back(92);
	v.push_back(22);

	// outputting the vector v onto terminal
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	inFile.close();
	
	outFile.open("file.txt");
	for (unsigned int i = 0; i < v.size(); ++i) {
		outFile << v[i] << "\n";
	}
	outFile.close();

	cout << "\n";
	inFile.open("integers.txt");
	inFile >> fileSize;

	for (unsigned int i = 0; i < fileSize; ++i) {
		while (inFile >> id) {
			getline(inFile, misc);
			getline(inFile, carPartDescription);
			Parts newPart;
			newPart.id = id;
			newPart.description = carPartDescription;
			carPartVector.push_back(newPart);
		}
	}
	
	for (unsigned int i = 0; i < carPartVector.size(); ++i) {
		cout << carPartVector[i].id << ": " << carPartVector[i].description << "\n";
	}
	inFile.close();

	outFile.open("output.txt");
	outFile << carPartVector.size() * 2 << "\n";


	for (unsigned int i = 0; i < carPartVector.size(); ++i) {
		outFile << carPartVector[i].id << "\n" << carPartVector[i].description << "\n";
	}

	outFile.close();
		
	return 0;
}
