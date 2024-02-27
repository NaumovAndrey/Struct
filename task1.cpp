//Ведомость учёта

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
	file.write((char*)&person.health, sizeof(person.health));  //передали указатели на поля преводя их к чар и длина соответствующего элемента в байтах
	
} */

/*Запись в файл*/
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

/*Создание записи сотрудника*/
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

/*Прочитать из файла все записи (строки)*/
void readFileEmployee(std::vector<employee>& employees)
{
	std::ifstream file("statement.bin", std::ios::binary);
	if (file.is_open())
	{
		while (file.eof())
		{
			employee emp;
			int lenName;

			file.read((char*)&lenName, sizeof(lenName));
			emp.name.resize(lenName);
			file.read((char*)emp.name.c_str(), lenName);

			int lenSurname;
			file.read((char*)&lenSurname, sizeof(lenSurname));
			emp.surname.resize(lenSurname);

			int lenData;
			file.read((char*)&lenData, sizeof(lenData));
			emp.data.resize(lenData);

			file.read((char*)&emp.salary, sizeof(emp.salary));

			employees.push_back(emp);
}
	} 
	else
	{
		std::cerr << "Ошибка при чтении из файла." << std::endl;
	}
}

/*Вывести в консоль все строки из вектора*/
void viewConsoleEmployee(const std::vector<employee>& employees)
{
	std::cout << "Number of employees: " << employees.size() << std::endl;
	for (const auto& emp : employees)
	{
		std::cout << "Имя: " << emp.name << ", Фамилия: " << emp.surname << ", Дата оплаты: " << emp.data << ", Получил: " << emp.salary << " рублей" << std::endl;
	}
}

void payrollStatement(){
	std::cout << "start" << std::endl;
	std::vector<employee> employees;
	createEmployee("Андрей", "Наумов", "27.02.2024", 120000);
	createEmployee("Алёна", "Наумова", "27.02.2024", 80000);

	readFileEmployee(employees);   // todo не читает
	viewConsoleEmployee(employees);	 // 
	std::cout << "stop" << std::endl;
}