#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string pathF1 = "../F1.txt";
    std::string pathF2 = "../F2.txt";

    std::string input;
    std::string output;

    std::string str1;
    std::string str2;

    int n1{}, n2{}, counter{};

    std::cout << "Скопировать из файла F1 в файл F2 все строки, начинающиеся 'А' и заканчивающиеся на 'С', расположенные между строками N1 и N2.\nОпределить количество слов в первой строке файла F2.\n\n";

    std::ofstream inputF1(pathF1);

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
    else std::cout << "Открыть файл F1.txt для записи не получается!";

    std::ifstream outputF1(pathF1);

    std::cout << "\nИщем файл по пути '" << pathF1 << "'";

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
            counter++;
        }
    }
    else std::cout << "Невозможно открыть файл F1.txt для чтения";

    std::cout << "\nВведите диапазон строк (N1, N2) для оперирования (Всего строк - " << counter << "):\n";

    while (n1 == NULL || n2 == NULL)
    {
        std::cin >> str1 >> str2;
        try
        {
            n1 = std::stoi(str1);
            n2 = std::stoi(str2);

            if (n1 > n2 || n1 <= 0 || n1 > counter || n2 <= 0 || n2 > counter)
            {
                std::cout << "\nВведен неверный диапазон данных! Попробуйте еще раз\n";
                n1 = NULL;
            }
        }
        catch (const std::exception&)
        {
            std::cout << "\nВведен неверный тип данных! Попробуйте еще раз\n";
        }
    }

    counter = 1;
    outputF1.clear();
    outputF1.seekg(0, std::ios::beg);

    std::ofstream inputF2(pathF2);

    std::cout << "Подготавливаем файл для обработанных данных";

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
        std::cout << "Файл открыт!\n";

        if (inputF2.is_open())
        {
            while (std::getline(outputF1, output))
            {
                if (counter < n1)
                {
                    std::cout << "\nСтрока " << counter << " находится вне диапазона (N1;N2), переходим к следующей строке\n";
                    counter++;
                }
                else
                {
                    if (output[0] == 'А' && output[output.length() - 1] == 'С')
                    {
                        std::cout << "\nПервая строка в диапазоне, попадающая под условия - " << counter << "\n\n" << output << '\n';
                        inputF2 << "Первая строка в диапазоне, попадающая под условия - " << counter << std::endl << output << std::endl  << "Количество пробелов в этой строке - " << std::count(output.begin(), output.end(), ' ') << std::endl << std::endl;
                        counter++;
                        while (counter <= n2 && std::getline(outputF1, output))
                        {
                            if (output[0] == 'А' && output[output.length() - 1] == 'С')
                            {
                                std::cout << "\nСтрока " << counter << " соответсвует условию, была только что записана в файл:\n\n" << output << '\n';
                                inputF2 << output << std::endl;
                            }
                            else std::cout << "\nСтрока " << counter << " не содержит необходимые символы в начале и конце строки\n";
                            counter++;
                        }
                        std::cout << "\nВне диапазона!\n";

                        std::cout << "\nЗакрытие потоков!\n";

                        outputF1.close();
                        inputF2.close();
                    }
                    else
                    {
                        std::cout << "\nСтрока " << counter << " не содержит необходимые символы в начале и конце строки\n";
                        counter++;
                    }
                }

            }
        }
        else std::cout << "Невозможно открыть файл F2.txt для записи";

        if (outputF1.is_open()) { outputF1.close(); std::cout << "\nКонтрольное закрытие потока F1! (Где-то ошибка)\n"; }

        if (inputF2.is_open()) { inputF2.close(); std::cout << "\nКонтрольное закрытие потока F2! (Где-то ошибка)\n"; }
    }
    else std::cout << "Файл F1.txt закрыт для чтения";


}

