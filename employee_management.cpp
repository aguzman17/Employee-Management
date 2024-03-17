#include <iostream>
#include <iomanip>
using namespace std;

class Employee
{
	private:
		int* numEmp;
		int* id;
		double* hours;
	public:
		Employee(int);
		Employee(const Employee& obj);
		void SetIdHours(int, int, double);
		void printInfo(int);
		~Employee();	
};
Employee::Employee(int emp)
{
	numEmp = new int;
	*numEmp = emp;
	id = new int[emp];
	*id = { 0 };
	hours = new double[emp];
	*hours = { 0 };
}
Employee::~Employee()
{
	delete[] hours;
	delete[] id;
	delete numEmp;

	hours = NULL;
	id = NULL;
	numEmp = NULL;
}
Employee::Employee(const Employee& emp)
{
	numEmp = new int;
	*numEmp = *emp.numEmp;

	id = new int[*numEmp];
	*id = *emp.id;

	hours = new double[*numEmp];
	*hours = *emp.hours;
}
void Employee::SetIdHours(int i, int Id, double Hours)
{
	*(id + i) = Id;
	*(hours + i) = Hours;	
}
void Employee::printInfo(int i)
{
	cout << fixed << showpoint << setprecision(1) << *(id + i) << "\t" << *(hours + i);
	if (*(hours + i) >= 40)
	{
		cout << "\nFULL TIME EMPLOYEE" << endl;
	}
	else
	{
		cout << "\nPART TIME EMPLOYEE" << endl;
	}
}

int main()
{
	int numemp = 0;
	int* id = new int;
	double* hours = new double;
	int i = 0;

	cout << "Insert the number of employee's: " << endl;
	cin >> numemp;

	Employee emp(numemp);
	Employee emp2 = emp;

	cout << "First constructor address: " << &emp << endl;
	cout << "Copy constructor address: \n" << &emp2 << endl;

	for (i = 0; i < numemp; i++)
	{
		cout << "Insert the id for employee " << i + 1 << " :" << endl;
		cin >> *id;

		cout << "Insert the hours for employee " << i + 1  << " :" << endl;
		cin >> *hours;

		emp.SetIdHours(i, *id, *hours);
	}

	for (int i = 0; i < numemp; i++)
	{
		emp.printInfo(i);
	}

	delete id;
	delete hours;
	id = NULL;
	hours = NULL;
	emp.~Employee();

	return 0;
}
