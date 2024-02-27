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

/*
	file.write((char*)&person.health, sizeof(person.health));  //�������� ��������� �� ���� ������� �� � ��� � ����� ���������������� �������� � ������
	
} */

/*������ � ����*/
void saveFileEmployee(employee& emp)
{
	std::ofstream file("statement.bin", std::ios::binary | std::ios::app);
	//file.write(reinterpret_cast<char*>(&emp), sizeof(emp));

	int lenName = emp.name.length();
	file.write((char*)&lenName, sizeof(lenName));
	file.write(emp.name.c_str(), lenName);

	int lenSurname = emp.surname.length();
	file.write((char*)&lenSurname, sizeof(lenSurname));
	file.write(emp.surname.c_str(), lenSurname);

	int lenData = emp.data.length();
	file.write((char*)&emp.data, sizeof(lenData));
	file.write(emp.data.c_str(), lenData);

	file.write((char*)&emp.salary, sizeof(emp.salary));
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
	} else
	{
		std::cerr << "������ ��� ������ �� �����." << std::endl;
	}
}

/*������� � ������� ��� ������ �� �������*/
void viewConsoleEmployee(const std::vector<employee>& employees)
{
	std::cout << "Number of employees: " << employees.size() << std::endl;
	for (const auto& emp : employees)
	{
		std::cout << "���: " << emp.name << ", �������: " << emp.surname << ", ���� ������: " << emp.data << ", �������: " << emp.salary << " ������" << std::endl;
	}
}

void payrollStatement(){
	std::cout << "start" << std::endl;
	std::vector<employee> employees;
	createEmployee("������", "������", "27.02.2024", 120000);
	createEmployee("����", "�������", "27.02.2024", 80000);

	readFileEmployee(employees);   // todo �� ������
	viewConsoleEmployee(employees);	 // 
	std::cout << "stop" << std::endl;
}