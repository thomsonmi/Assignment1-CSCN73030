//Assignment 1 - CSCN73030
//Michael Thomson
//9039322

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


struct STUDENT_DATA {
	string firstName;
	string lastName;
};




int main() {

	vector<STUDENT_DATA> students;

	ifstream inputFile("StudentData.txt");
	if (!inputFile.is_open()) {
		cerr << "Error opening file." << endl;
		return 1;
	}

	string line;
	while (getline(inputFile, line)) {
		size_t commaPos = line.find(',');
		if (commaPos != string::npos) {
			STUDENT_DATA student;
			student.lastName = line.substr(0, commaPos);
			student.firstName = line.substr(commaPos + 1);
			students.push_back(student);
		}
	}

#ifdef _DEBUG
	for (const auto& student : students) {
		cout << student.firstName << " " << student.lastName << endl;
	}
#endif

	inputFile.close();
	return 1;
}