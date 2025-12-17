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
    std::cout << "\nВыберите способ заполнения строки: \n";
    std::cout << "1. Заполнение с помощью консоли; \n";
    std::cout << "2. Заполнение случайным способом; \n";
    std::cout << "3. Заполнение из файла; \n";
    std::cout << "0. Выход. \n";
    std::cout << "Ваш выбор? ";
    std::cin >> Choice;
    return Choice;
}

int ChooseRandomTask() {
    int Choice;
    std::cout << "\nВы выбрали заполнить строку случайным способом, выберите задачу: \n";
    std::cout << "1. R Задача №1 - String46; \n";
    std::cout << "2. R Задача №2 - Str18; \n";
    std::cout << "3. R Задача №3 - Str23; \n";
    std::cout << "4. R Задача №4 - Str44; \n";
    std::cout << "5. R Задача №5 - Str31; \n";
    std::cout << "6. R Задача №6 - 3; \n";
    std::cout << "7. R Задача №7 - Five6; \n";
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
        ResLine.clear();
        Choice1 = ChooseMethod();
        switch (Choice1) {
            case 1: {
                FillKeyboard(ResLine);
                bool continueTasks = true;
                while (continueTasks) {
                    Choice2 = ChooseTask();
                    if (Choice2 == 0) { std::cout << "Возврат к выбору метода заполнения... \n"; break; }
                    switch (Choice2) {
                        case 1: { TaskString46(ResLine); break; }
                        case 2: { TaskStr18(ResLine); break; }
                        case 3: { TaskStr23(ResLine); break; }
                        case 4: { TaskStr44(ResLine); break; }
                        case 5: { TaskStr31(ResLine); break; }
                        case 6: { Task6Morse3(ResLine); break; }
                        case 7: { TaskFive6(ResLine); break; }
                        default: { std::cout << "Ошибка! Вы неверно ввели данные!\n"; break; }
                    }
                }
                break;
            } 
            case 2: {
                Choice2 = ChooseRandomTask();
                if (Choice2 == 0) { std::cout << "Возврат к выбору метода заполнения... \n"; break; }
                int Length;
                switch (Choice2) {
                    case 1: { FillRandomTaskString46(ResLine); TaskString46(ResLine); break; }
                    case 2: { FillRandomTaskStr18(ResLine); TaskStr18(ResLine); break; }
                    case 3: { FillRandomTaskStr23(ResLine); TaskStr23(ResLine); break; }
                    case 4: { 
                        std::cout << "Введите размер строки: ";
                        std::cin >> Length;
                        FillRandomTaskStr44(ResLine, Length); 
                        TaskStr44(ResLine);
                        break;  
                    }
                    case 5: { FillRandomTaskStr31(ResLine); TaskStr31(ResLine); break; } 
                    case 6: { FillRandomTask3(ResLine); Task6Morse3(ResLine); break; }
                    case 7: { FillRandomTaskFive6(ResLine); TaskFive6(ResLine); break; }
                    default: { std::cout << "Ошибка! Вы неверно ввели данные!\n"; break; }
                }
                break;
            } 
            case 3: {
                FillOutTFiles(ResLine);
                bool continueTasks = true;
                while (continueTasks) {
                    Choice2 = ChooseTask();
                    if (Choice2 == 0) {  std::cout << "Возврат к выбору метода заполнения... \n"; break; }
                    switch (Choice2) {
                        case 1: { TaskString46(ResLine); break; }
                        case 2: { TaskStr18(ResLine); break; }
                        case 3: { TaskStr23(ResLine); break; }
                        case 4: { TaskStr44(ResLine); break; }
                        case 5: { TaskStr31(ResLine); break; }
                        case 6: { Task6Morse3(ResLine); break; }
                        case 7: { TaskFive6(ResLine); break; }
                        default: { std::cout << "Неверный выбор! \n"; break; }
                    }
                }
                break;
            } 
            case 0: { std::cout << "Завершение работы...\nРабота завершена.\n"; return 0; } 
            default: { std::cout << "Ошибка! Вы неверно ввели данные!\n"; break; }
        }
    } while (true);
    return 0;
}