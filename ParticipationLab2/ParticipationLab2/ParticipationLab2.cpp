#include <iostream>
#include "Doctor.h"

using namespace std;
int main()
{
	string specialty, patName;
	int numPatients{ 0 }, patAge{ 0 };
	double patWeight{ 0.0 };
	Doctor d;

	cout << "Enter doctor specialty: ";
	cin >> specialty;
	cout << "How many patients does this doctor have? ";
	cin >> numPatients;
	for (int i = 0; i < numPatients; ++i)
	{
		cout << "Enter Patient name: ";
		cin >> patName;
		cout << "Enter Patient age: ";
		cin >> patAge;
		cout << "Enter Patient weight: ";
		cin >> patWeight;

		d.addPatient(patName, patAge, patWeight);
	}
	d.printDoctorInfo();
	system("pause");
	return 0;
}