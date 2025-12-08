#include <iostream>
#include "LBWork5.h"
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
// #include <set>
// #include <cctype>

using namespace std;

void FillKeyboard(std::string &Line) {
    std::cin.ignore();
    std::cout << "Введите строку! ";
    getline(std::cin, Line);
    std::cout << "Строка успешно создана! ";
    std::cout << "\n";
}

void FillRandomTaskString46(std::string &Line) {
    std::vector<std::string> Words = {"кот", "собака", "олень", "лев", "обезьяна", "курицца", "котёнок", "птица", "медведь", "щенок", "фламинго", "тигр", "кролик"};
    int WordsSize = Words.size();
    srand(time(0));
    int NW = 2 + (std::rand() % 3);
    Line = " ";    
    for (int i = 0; i < NW; i++) {
        int RandI = rand() % WordsSize;
        Line += Words[RandI];

        if (i < NW - 1) {
            Line += " ";
        }
   }
   std::cout << "Строка успешно создана! ";
   std::cout << "\n";
}

void FillRandomAll(std::string &Line, int Length) {
    srand(time(0));
    string set;
    for (int i = 224; i <= 255; i++) {
        set += char(i);
    } for (int i = 192; i <= 223; i++) {
        set += char(i);
    } for (char c = 'a'; c <= 'z'; c++) {
        set += c;
    } for (char c = 'A'; c <= 'Z'; c++) {
        set += c;
    } for (char c = '0'; c <= '9'; c++) {
        set += c;
    }
    set += "!@#$%^&*()_+-=[]{}|;:,.<>?~` ";
    for (int i = 0; i < Length; i++) {
        Line += set[rand() % set.size()];
    }
}

//мб добавить тоже диапазон в рандом
void FillOutTFiles(std::string &Line) {
    ifstream f1("LBWork5.txt", ios::in);
    if (f1.is_open()) {
        std::string One;
        std::string Line1;
        while (getline(f1, Line1)) { Line += Line1; }
        std::cout << "Строка успешно создана! ";
        std::cout << "\n";
        f1.close();
    } else {
        std::cout << "Error!\n";
        return;
    }
}

//String46
void TaskString46(std::string Line) {
    ofstream f2("LBW5Answers.txt", ios::out);
    std::cout << "=== Задача №1 - String46 === \n";
    int MaxLenWord = 0;
    int StartWord = -1;

    for (int i = 0; i <= Line.length(); i++) {
        if (i < Line.length() && Line[i] != ' ') {
            if (StartWord == -1) {
                StartWord = i;
            }
        } else {
            if (StartWord != -1) {
                int LenWord = i - StartWord;
                if (LenWord > MaxLenWord) {
                    MaxLenWord = LenWord;
                }
                StartWord = -1;
            }
        }
    }
    f2 << "Ваша строка: " << Line << "\n";
    f2 << "Максимальная длина слова из строки: " << MaxLenWord << "\n";
    std::cout << "Ваша строка: " << Line << "\n";
    std::cout << "Максимальная длина слова из строки: " << MaxLenWord << "\n";
    std::cout << "Ответы на задачу записаны в файл 'LBW5Answers.txt'. \n";
    std::cout << "======= Конец задачи ======= \n";
    f2.close();
}

//Str18
// C:\Users\Username\Documents\project\file.txt
void TaskStr18(std::string Line) {
    ofstream f2("LBW5Answers.txt", ios::out);
    std::cout << "=== Задача №2 - Str18 === \n";
    std::cout << "Исходный путь: " << Line << "\n";
    f2 << "Исходный путь: " << Line << "\n";
    for (int i = 0; i <= Line.length(); i++) {
        if (Line[i] == '\\') {
            Line[i] = '/';
        }
    }
    f2 << "Преобразованный путь: " << Line << "\n";
    std::cout << "Преобразованный путь: " << Line << "\n";
    std::cout << "Ответы на задачу записаны в файл 'LBW5Answers.txt'. \n";
    std::cout << "====== Конец задачи ====== \n";
    f2.close();
}

//Str23
void TaskStr23(std::string Line) {
    ofstream f2("LBW5Answers.txt", ios::out);
    std::cout << "=== Задача №3 - Str23 === \n";
    int Gamma;
    std::cout << "Введите значение гаммы от 127 до 255! ";
    std::cin >> Gamma;
    if (Gamma < 127 || Gamma > 255) { std::cout << "Ошибка диапазона Гаммы!"; return; }
    else {
        std::cout << "Ваша строка: " << Line << "\n";
        f2 << "Ваша строка: " << Line << "\n";
        std::string Line2 = Line;
        for (int i = 0; i < Line.length(); i++) {
            Line2[i] = Line[i] ^ Gamma;
        }
        std::cout << "Зашифрованная строка: " << Line2 << "\n";
        f2 << "Зашифрованная строка: " << Line2 << "\n";
        std::string Check = Line2;
        for (int i = 0; i < Line2.length(); i++) {
            Check[i] = Line2[i] ^ Gamma;
        }
        std::cout << "Расшифрованная строка: " << Check << "\n";
        f2 << "Расшифрованная строка: " << Check << "\n";
    }
    std::cout << "Ответы на задачу записаны в файл 'LBW5Answers.txt'. \n";
    std::cout << "====== Конец задачи ====== \n";
    f2.close();
}

//Str44
// dofkkj%d7&8IJD?!!0)d&%%@3##e000###-----
void TaskStr44(std::string Line) {
    ofstream f2("LbwAnswers.txt", ios::out);
    std::cout << "=== Задача №4 - Str44 === \n";
    std::cout << "Строка: " << Line << "\n";
    f2 << "Строка: " << Line << "\n";
    int Max_Cnt = -10;
    char Max_Symbol = '\0';
    for (int i = 0; i <= Line.length(); i++) {
        char Symbol = Line[i];
        int Cnt = 0;
        for (int j = 0; j <= Line.length(); j++) {
            if (Line[j] == Symbol) { Cnt++; }
        }
        if (Cnt >= Max_Cnt) {
            Max_Cnt = Cnt;
            Max_Symbol = Symbol;
        }
    }
    std::cout << "Максимальное кол-во символов в строке: " << Max_Cnt << "\n";
    f2 << "Максимальное кол-во символов в строке: " << Max_Cnt << "\n";
    std::cout << "Символ, встречающийся макс. кол-во раз: " << Max_Symbol << "\n";
    f2 << "Символ, встречающийся макс. кол-во раз: " << Max_Symbol << "\n";
    std::cout << "Ответы на задачу записаны в файл 'LBW5Answers.txt'. \n";
    std::cout << "====== Конец задачи ====== \n";
    f2.close();
}

//Str31
void TaskStr31(std::string Line) {
    ofstream f2("LBW5Answers.txt", ios::out);
    std::cout << "=== Задача №5 - Str31 === \n";
    std::cout << "Исходное число в 10-сс: " << Line << "\n";
    f2 << "Исходное число в 10-сс: " << Line << "\n";
    std::string Line2;
    int IntLine = 0;
    if (Line == "0") { Line2 = "0"; }
    else { 
        for (char c : Line) { 
            IntLine = IntLine * 10 + (c - '0'); 
        }
    }
    int Temp = IntLine;
    while (Temp > 0) {
        int Remainder = Temp % 18;
        char Digit;
        if (Remainder < 10) {
            Digit = '0' + Remainder;
        } else {
            Digit = 'A' + (Remainder - 10);
        }
        Line2 = Digit + Line2;
        Temp /= 18;
    }

    std::cout << "Итоговое число в 18-сс: " << Line2 << "\n";
    f2 << "Итоговое число в 18-сс: " << Line2 << "\n";
    std::cout << "Ответы на задачу записаны в файл 'LBW5Answers.txt'. \n";
    std::cout << "====== Конец задачи ====== \n";
    f2.close();
}

//3
void Task6Morse3(std::string Line) {
    ofstream f2("LBW5Answers.txt", ios::out);
    char Ru[] = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    char Lat[] = "ABWGDEVZIJKLMNOPRSTUFHC?CHQ?YX???"; //"ABWGDEVZIJKLMNOPRSTUFHC?CHQ?YX???"
    char Digits[] = "0123456789";

    std::string Morse[33] = {".-", "-...", ".--", "--.", "-..", ".", "...-", "--..", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", ".-.", "...", "-", "..-", "..-.", "....", "-.-.", "---.", "----", "--.-", "--.--", "-.--", "-..-", "..-..", "..--", ".-.-"};
    std::string DigitsMorse[10] = {"-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."};

    std::cout << "=== Задача №6 - 3 === \n";
    std::cout << "Ваше сообщение: " << Line << "\n";
    std::cout << "Код Морзе: " << "\n";
    f2 << "Код Морзе: " << "\n";
    for (int i = 0; i < Line.length(); i++) {
        char c = Line[i];
        bool Found = false;
    // Ru
    //Lowercase letters
        for (int j = 0; j < 32; j++) {
            if (c == Ru[j]) {
                std::cout << Morse[j];
                f2 << Morse[j];
                Found = true;
                break;
            }
        }
    //Capital letters
        if (!Found && c >= 'а' && c <= 'я') {
            char Up = c - ('а' - 'А');
            for (int j = 0; j < 32; j++) {
                if (Up == Ru[j]) {
                    std::cout << Morse[j];
                    f2 << Morse[j];
                    Found = true;
                    break;
                }
            }
        }
    //E Yo
        if (!Found && (c == 'ё' || c == 'Ё')) {
            std::cout << ".";
            f2 << ".";
            Found = true;
        }
    // Eng
    //Lowercase letters
        if (!Found) {
            for (int j = 0; j < 32; j++) {
                if (c == Lat[j]) {
                    std::cout << Morse[j];
                    f2 << Morse[j];
                    Found = true;
                    break;
                }
            }
        }
    //Capital letters
        if (!Found && c >= 'a' && c <= 'z') {
            char Up = c - ('a' - 'A');
            for (int j = 0; j < 32; j++) {
                if (Up == Lat[j]) {
                    std::cout << Morse[j];
                    f2 << Morse[j];
                    Found = true;
                    break;
                }
            }
        }
    //Digits
        if (!Found && c >= '0' && c <= '9') {
            std::cout << DigitsMorse[c - '0'];
            f2 << DigitsMorse[c - '0'];
            Found = true;
        }
    //Space
        if (!Found && c == ' ') {
            std::cout << "/";
            Found = true;
        }
    //Error
        if (!Found) {
            std::cout << "Symbolic Error!";
        }
        if (i < Line.length() - 1 && c != ' ') {
            std::cout << " ";
            f2 << " ";
        }
        std::cout << "\n";
        f2 << "\n";
    }
    std::cout << "Ответы на задачу записаны в файл 'LBW5Answers.txt'. \n";
    std::cout << "===== Конец задачи ===== \n";
    f2.close();
}

//Five6
bool IsHexChar(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}
int HexCharToNum(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'F') {
        return 10 + (c - 'A');
    } else {
        return 10 + (c - 'a');
    }
}

void TaskFive6(std::string Line) {
    ifstream f1("FN1.txt", ios::in);
    ofstream f2("FN2.txt", ios::out);
    std::cout << "=== Задача №7 - Five6 === \n";
    if (!f1.is_open() || !f2.is_open()) {
        std::cout << "Error!" << "\n";
        return;
    }

    std::string FLine;
    while (getline(f1, FLine)) {
        if (FLine.length() == 0) {
            f2 << "\n";
            continue;
        }

        std::string WithoutSpaces = "";
        for (int i = 0; i < FLine.length(); i++) {
            if (FLine[i] != ' ') {
                WithoutSpaces += FLine[i];
            }
        }

        int EqualPose = -1;
        for (int i = 0; i < WithoutSpaces.length(); i++) {
            if (WithoutSpaces[i] == '=') {
                EqualPose = i;
                break;
            }
        } 
        if (EqualPose == -1) {
            f2 << FLine << " !" << "\n";
            continue;
        }
        std::string Left = "", Right = "";
        for (int i = 0; i < EqualPose; i++) {
            Left += WithoutSpaces[i];
        }
        for (int i = EqualPose + 1; i < WithoutSpaces.length(); i++) { 
            Right += WithoutSpaces[i];
        }
        
        bool CheckRight = true;
        for (int i = 0; i < Right.length(); i++) {
            char c = Right[i];
            if (!IsHexChar(c)) {
                CheckRight = false;
                break;
            }
        }
        if (!CheckRight) {
            f2 << FLine << " !" << "\n";
            continue;
        }
        
        int PlusPose = -1, MultPose = -1;
        for (int i = 0; i < Left.length(); i++) {
            if (Left[i] == '+') { PlusPose = i; }
            if (Left[i] == '*') { MultPose = i; }
        }
        if (PlusPose == -1 && MultPose == -1) {
            f2 << FLine << " !" << "\n";
            continue;
        }

        char Op;
        int OpPose;

        if (PlusPose != -1) { Op = '+'; OpPose = PlusPose; }
        else { Op = '*'; OpPose = MultPose; }

        std::string LeftLeft = "", LeftRight = "";
        for (int i = 0; i < OpPose; i++) {
            LeftLeft += Left[i];
        }
        for (int i = OpPose + 1; i < Left.length(); i++) {
            LeftRight += Left[i];
        }

        bool CheckNumLeft = true;
        for (int i = 0; i < LeftLeft.length(); i++) {
            char c = LeftLeft[i];
            if (!IsHexChar(c)) {
                CheckNumLeft = false;
                break;
            }
        }
        bool CheckNumRight = true;
        for (int i = 0; i < LeftRight.length(); i++) {
            char c = LeftRight[i];
            if (!IsHexChar(c)) {
                CheckNumRight = false;
                break;
            }
        }

        if (!CheckNumLeft || !CheckNumRight || LeftLeft.length() == 0 || LeftRight.length() == 0) {
            f2 << FLine << " !" << "\n";
            continue;
        }

        int LNum = 0;
        for (int i = 0; i < LeftLeft.length(); i++) {
            char c = LeftLeft[i];
            int Digit = HexCharToNum(c);
            LNum = LNum * 16 + Digit;
        }
        int RNum = 0;
        for (int i = 0; i < LeftRight.length(); i++) {
            char c = LeftRight[i];
            int Digit = HexCharToNum(c);
            RNum = RNum * 16 + Digit;
        }

        int Answer = 0;
        for (int i = 0; i < Right.length(); i++) {
            char c = Right[i];
            int Digit = HexCharToNum(c);
            Answer = Answer * 16 + Digit;
        }

        int Correct;
        if (Op == '+') { Correct = LNum + RNum; }
        else { Correct = LNum * RNum; }

        if (Answer == Correct) { f2 << FLine << "\n"; }
        else { f2 << FLine << " !" << "\n"; }
    }
    f1.close();
    f2.close();

    std::cout << "Проверка решений примеров записана в файл 'FN2.txt'.\n";
    std::cout << "===== Конец задачи =====\n";
}