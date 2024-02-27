//��������� �����

#include "iostream"
#include <vector>
#include "string"
#include "fstream"

struct employee
{
	std::string name;
	std::string surname;
	std::string data;
	int salary;
};

/*������ � ����*/
void saveFileEmployee(employee emp)
{
	std::ofstream file("statement.bin", std::ios::binary | std::ios::app);
	file.write(reinterpret_cast<char*>(&emp), sizeof(emp));
}

/*�������� ������ ����������*/
void createEmployee(const std::string& name,
					const std::string& surname,
					const std::string& data,
					const int& salary
					)
{
	employee emp;
	emp.name = name;
	emp.surname = surname;
	emp.data = data;
	emp.salary = salary;

	saveFileEmployee(emp);
}

/*��������� �� ����� ��� ������ (������)*/
void readFileEmployee(std::vector<employee>& employees)
{
	//todo ��������� ���� saveStatement.bin  � �������� � ������ ��� ������
}

/*������� � ������� ��� ������ �� �������*/
void viewConsoleEmployee(std::vector<employee>& employees)
{
	//todo �� ������� ������ ���� ����������� �� ����� �������
}

void payrollStatement(){
	std::vector<employee> employees;
	createEmployee();
	viewConsoleEmployee();
}