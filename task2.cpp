//Модель данных для посёлка

#include <vector>

enum class RoomType //тип комнаты
{
    Bedroom, //спальня
    Kitchen, //кухня
    Bathroom, //ванная
    ChildrenRoom, //детская
    LivingRoom //гостиная
};

struct Room
{
    RoomType type; 
    double area; //площадь
};

struct Floor //этаж
{
    int roomCount; //количество комнат
    double ceilingHeight; //высота потолка
    std::vector<Room> rooms;
};

struct Building //здание
{
    double area; //площадь
    int floorCount; //количество этажей
    std::vector<Floor> floors; 
    bool hasFireplace; //печь
};

struct ResidentialBuilding : Building
{
    int apartmentCount; //количество квартир
};

struct Garage : Building
{
    bool hasPit; //яма
};

struct Bathhouse : Building
{
    bool hasStove; //печка
};

struct Plot //участок
{
    int number;
    ResidentialBuilding house;
    Garage garage;
    Bathhouse bathhouse;
    double landArea;
};

struct Village //посёлок
{
    std::vector<Plot> plots;
};

int task2()
{
    Village village;

    Plot plot1;
    plot1.number = 1;

    ResidentialBuilding house1;
    house1.area = 150.0;
    house1.floorCount = 2;
    house1.hasFireplace = true;

    Floor floor1;
    floor1.roomCount = 3;
    floor1.ceilingHeight = 2.5;

    Room room1{ RoomType::Bedroom, 20.0 };
    Room room2{ RoomType::Kitchen, 15.0 };
    Room room3{ RoomType::LivingRoom, 25.0 };

    floor1.rooms.push_back(room1);
    floor1.rooms.push_back(room2);
    floor1.rooms.push_back(room3);

    house1.floors.push_back(floor1);

    plot1.house = house1;
    plot1.landArea = 500.0;

    village.plots.push_back(plot1); // Добавляем участок в посёлок
}