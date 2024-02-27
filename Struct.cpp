#include <iostream>
#include <clocale>

void game();
void payrollStatement();


int main()
{
    setlocale(LC_ALL, "rus");
    //setlocale(LC_ALL, "rus");
    //game();

    //Ведомость учёта
    payrollStatement();
}