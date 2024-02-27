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
	std::ifstream file("saveStatement.bin", std::ios::binary);
	if (file.is_open())
	{
		employee emp;
		while (file.read(reinterpret_cast<char*>(&emp), sizeof(emp)))
		{
			employees.push_back(emp);
		}
		file.close();
	}
}

/*������� � ������� ��� ������ �� �������*/
void viewConsoleEmployee(const std::vector<employee>& employees)
{
	for (const auto& emp : employees)
	{
		std::cout << "���: " << emp.name << ", �������: " << emp.surname << ", ���� ������: " << emp.data << ", �������: " << emp.salary << " ������" << std::endl;
	}
}

void payrollStatement(){
	std::cout << "start" << std::endl;
	std::vector<employee> employees;
	//createEmployee("������", "������", "27.02.2024", 120000);
	//createEmployee("����", "�������", "27.02.2024", 80000);

	readFileEmployee(employees);
	viewConsoleEmployee(employees);	 // todo �� ������� � �������
	std::cout << "stop" << std::endl;
}