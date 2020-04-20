#include <iostream>
#include <clocale>
#include <string>
#include "ModulesMoroz.h"
#include <windows.h>
#include <math.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ukr");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("chcp 1251");


    test_task2_1();


	return 0;
}
