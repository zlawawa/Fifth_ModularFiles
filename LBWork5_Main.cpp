#ifdef _WIN64
#include <windows.h>
#endif

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <string>
#include "LBWork5.h"

using namespace std;

int ChooseMethod() {
    int Choice;
    std::cout << "Выберите способ заполнения строки: \n";
    std::cout << "1. С клавиатуры; \n";
    std::cout << "2. Случайным способом; \n";
    std::cout << "3. Из файла; \n";
    std::cout << "0. Выход. \n";
    std::cout << "Ваш выбор? ";
    std::cin >> Choice;
    std::cout << "\n";
    return Choice;
}

int ChooseTask() {
    int Choice;
    std::cout << "\nВыберите задачу: \n";
    std::cout << "1. Задача №1 - String46; \n";
    std::cout << "2. Задача №2 - Str18; \n";
    std::cout << "3. Задача №3 - Str23; \n";
    std::cout << "4. Задача №4 - Str44; \n";
    std::cout << "5. Задача №5 - Str31; \n";
    std::cout << "6. Задача №6 - 3; \n";
    std::cout << "7. Задача №7 - Five6; \n";
    std::cout << "0. Изменить строку. \n";
    std::cout << "Ваш выбор? ";
    std::cin >> Choice;
    std::cout << "\n";
    return Choice;
}

int main() {
    #ifdef _WIN64
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    #endif

    std::string ResLine; 
    int Choice1, Choice2;
    do {
        int Length;
        Choice1 = ChooseMethod();
        switch (Choice1) {
            case 1: {
                FillKeyboard(ResLine);
                break;
            } case 2: {
                FillRandomAll(ResLine, Length);
                break;
            } case 3: {
                FillOutTFiles(ResLine);
                break;
            } case 0: {
                std::cout << "Завершение программы... \n";
                std::cout << "Работа завершена. \n";
                return 0;
            } default: {
                std::cout << "Вы неверно ввели данные! \n";
                return 1;
            }
        }

        while (true) {
            Choice2 = ChooseTask();
            if (Choice2 == 0) { std::cout << "Завершение программы... \n"; std::cout << "Работа завершена. \n"; break; }
            switch (Choice2) {
                case 1: {
                    TaskString46(ResLine);
                    break;
                } case 2: {
                    if (Choice1 != 2) { TaskStr18(ResLine); break; }
                    else { std::cout << "Error!!"; return -1; }
                } case 3: {
                    TaskStr23(ResLine);
                    break;
                } case 4: {
                    TaskStr44(ResLine);
                    break;
                } case 5: {
                    TaskStr31(ResLine);
                    break;
                } case 6: {
                    Task6Morse3(ResLine);
                    break;
                } case 7: {
                    TaskFive6(ResLine);
                    break;
                } default: {
                    std::cout << "Вы неверное ввели данные! \n";
                    return 1;
                }
            }
        }
    } while (true);
    return 0;
}