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

/*Вывести в консоль все строки из вектора*/
void viewConsoleEmployee(const std::vector<employee>& employees)
{
	for (const auto& emp : employees)
	{
		std::cout << "Имя: " << emp.name << ", Фамилия: " << emp.surname << ", Дата оплаты: " << emp.data << ", Получил: " << emp.salary << " рублей" << std::endl;
	}
}

void payrollStatement(){
	std::cout << "start" << std::endl;
	std::vector<employee> employees;
	//createEmployee("Андрей", "Наумов", "27.02.2024", 120000);
	//createEmployee("Алёна", "Наумова", "27.02.2024", 80000);

	readFileEmployee(employees);
	viewConsoleEmployee(employees);	 // todo не выводит в консоль
	std::cout << "stop" << std::endl;
}