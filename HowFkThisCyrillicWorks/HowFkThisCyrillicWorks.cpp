#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string path = "../F1.txt";

    std::string input;
    std::string output;

    std::cout << "Скопировать из файла F1 в файл F2 все строки, начинающиеся 'А' и заканчивающиеся на 'С', расположенные между строками N1 и N2.\nОпределить количество слов в первой строке файла F2.\n\n";

    std::ofstream inputF1(path);

    std::cout << "Создаем файл";

    Sleep(1000);
    std::cout << ".";
    Sleep(1000);
    std::cout << ".";
    Sleep(1000);
    std::cout << ".\n";
    Sleep(1000);
    std::cout << "\n";
    Sleep(1000);   

    if (inputF1.is_open())
    {
        std::cout << "Файл открыт!\n\n";

        std::cout << "А сейчас запишите в F1.txt данные!\nВведите '0' с новой строчки, когда данные будут записаны!\n\n";

        while (inputF1.is_open())
        {
            std::getline(std::cin, input);

            if (input == "0")
                inputF1.close();
            else inputF1 << input << std::endl;
        }
    }
    else std::cout << "Открыть файл не получается!";

    std::ifstream outputF1(path);

    std::cout << "\nИщем файл по пути '" << path << "'";

    Sleep(1000);
    std::cout << ".";
    Sleep(1000);
    std::cout << ".";
    Sleep(1000);
    std::cout << ".\n";
    Sleep(1000);
    std::cout << "\n";
    Sleep(1000);

    if (outputF1.is_open())
    {
        std::cout << "Файл открыт! Вот что в нем записано: \n\n"; 

        while (std::getline(outputF1, output))
        {
            std::cout << output << '\n';
        }
        outputF1.close();
    }

    else std::cout << "Невозможно открыть файл";
}

