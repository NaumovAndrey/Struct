#include "iostream"
#include "cstdlib"
#include "string"
#include "fstream"

struct character
{
	//char* name;
	std::string name = "unknown";
	int health = 0;
	int armor = 0;
};	

void save_character(std::ofstream file, character& person)
{
	//int len = std::strlen(person.name);	// узнали длину имени и записали в переменную	(для  поля //char* name;)
	int len = person.name.length();

	file.write((char*)&len, sizeof(len));  //записали эту переменную счётчик в поток
	//file.write(person.name, len);  //записали строку массив 
	file.write(person.name.c_str(), len);  //записали строку массив, переведя строку в массив чаров  (.c_str())
	file.write((char*)&person.health, sizeof(person.health));  //передали указатели на поля преводя их к чар и длина соответствующего элемента в байтах
	file.write((char*)&person.armor, sizeof(person.armor));
}

void load_character(std::ifstream& file, character& person)
{
	int len;
	file.read((char*)&len, sizeof(len)); //загрузим длину имени
	person.name.resize(len);  //буфер для символов строки длиной лен
	file.read((char*)person.name.c_str(), len);
	file.read((char*)&person.health, sizeof(person.health));
	file.read((char*)&person.armor, sizeof(person.armor));
}

void take_damage(character* person, int damage)
{
	std::cout << person->name << " получил урон: " << damage << std::endl;
	person->armor -= damage; //если указатель, то тогда обращаемся через стрелочку иначе через точку
	if (person->armor < 0)
	{
		person->health += person->armor;
		person->armor = 0;
	}
}



void game()
{
	//character person = {"Andrey", 100, 20};
	//character person = {"Andrey", 100}; // или (если позволяет компилятор) - charapter person = {".name=Andrey", health=100, armor=20 };
	//person.armor = 20; //если указатель, то тогда обращаемся через стрелочку иначе через точку

	//character* person_ptr = &person; //метод принимает указатель
	//take_damage(person_ptr, 30);

	//или тоже самое 
	//take_damage(&person, 30);
	//std::cout << "Здоровье: " << person.health << " Броня: " << person.armor << std::endl;

	/*объявляем массив из 10 игроков*/
	character people[10]; //можно инициализировать как двумерный массив
	for (size_t i = 0; i < 10; i++)
	{
		people[i].name = "Character #" + std::to_string(i);
		people[i].health = (std::rand() % 100) + 100;
		people[i].armor = (std::rand() % 40) + 10;
	}

	for (size_t i = 0; i < 10; i++)
	{
		take_damage(&people[i], 30);
	}

	std::ofstream file("save.bin", std::ios::binary);
	file.write((char*)people, sizeof(people));


	for (size_t i = 0; i < 10; i++)
	{
		//save_character(file, people[i]);
	}
}