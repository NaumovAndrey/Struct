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

/*Запись в файл*/
void saveFileEmployee(employee emp)
{
	std::ofstream file("statement.bin", std::ios::binary | std::ios::app);
	file.write(reinterpret_cast<char*>(&emp), sizeof(emp));
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
	//todo прочитать файл saveStatement.bin  и записать в вектор все строки
}

/*Вывести в консоль все строки из вектора*/
void viewConsoleEmployee(std::vector<employee>& employees)
{
	//todo из вектора выести всех сотрудников на экран консоли
}

void payrollStatement(){
	std::vector<employee> employees;
	createEmployee();
	viewConsoleEmployee();
}