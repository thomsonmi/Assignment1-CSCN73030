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
	string email;
};




int main() {

	vector<STUDENT_DATA> students;

#ifdef PRE_RELEASE
	cout << "Running Pre-Release" << endl;
	ifstream inputFile("StudentData_Emails.txt");
#else
	cout << "Running Standard" << endl;
	ifstream inputFile("StudentData.txt");
#endif 



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



#ifdef PRE_RELEASE
			size_t secondComma = line.find(',', commaPos + 1);
			if (secondComma != string::npos) {
				student.firstName = line.substr(commaPos + 1, secondComma - commaPos - 1);
				student.email = line.substr(secondComma + 1);
			}
			else {
				student.firstName = line.substr(commaPos + 1);
			}
#else
			student.firstName = line.substr(commaPos + 1);
#endif 
			students.push_back(student);
		}
	}


#ifdef _DEBUG
	for (const auto& student : students) {
#ifdef PRE_RELEASE
		cout << student.firstName << " " << student.lastName << " " << student.email << endl;

#else 
		cout << student.firstName << " " << student.lastName << endl;
#endif
	}
#endif

	inputFile.close();
	return 1;
}