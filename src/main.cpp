#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

int count_lines_in_file(string filename)
{
    ifstream file(filename);
    int num_lines = 0;
    string line;

    while (getline(file, line))
    {
        num_lines++;
    }
    file.close();

    return num_lines;
}

string get_random_line(string filename)
{
    int num_lines = count_lines_in_file(filename);
    int rand_num = rand() % num_lines + 1;

    ifstream infile(filename);
    string line;
    for (int i = 1; getline(infile, line) && i <= rand_num; i++)
    {
        if (i == rand_num)
        {
            return line;
        }
    }
    infile.close();

    return "";
}

int main()
{
    setlocale(LC_ALL, "rus");

    string nmale_eng, nfemale_eng, lastname_eng, nmale_rus, nfemale_rus, lastname_rus;
    bool is_female, is_russian;

    srand(time(NULL));

    char repeat;
    do {
        system("cls");

        cout << "*=============* [NAME CHARACTER GENERATOR] *=============*" << endl;
        cout << endl;
        cout << "[X] НАСТРОЙКИ:" << endl;

        cout << "[*] Выберите пол, кому генерируете имя и фамилию. MALE/FEMALE. (m/f): " << endl;
        char gender;
        cin >> gender;

        cout << "[*] Выберите язык генерируемого имени и фамилии. ENG/RUS. (e/r): " << endl;
        char lang;
        cin >> lang;

        is_russian = (lang == 'r' || lang == 'R');
        is_female = (gender == 'f' || gender == 'F');

        if (gender == 'm' || gender == 'M')
        {
            cout << "! Выбран MALE!" << endl;
        }
        else if (gender == 'f' || gender == 'F')
        {
            cout << "! Выбрана FEMALE!" << endl;
        }
        else
        {
            cout << "! Выбираем MALE по умолчанию!" << endl;
        }

        if (lang == 'r' || lang == 'R')
        {
            cout << "! Выбрано RUS!" << endl;
        }
        else if(lang == 'e' || lang == 'E')
        {
            cout << "! Выбрано ENG!" << endl;
        }
        else
        {
            cout << "! Выбираем ENG по умолчанию!" << endl;
        }
        cout << endl;

        do {
            if (is_russian)
            {
                if (is_female)
                {
                    nmale_rus = get_random_line("data\\rus_name_female.txt");
                    lastname_rus = get_random_line("data\\rus_lastname.txt");
                    cout << ": " << nmale_rus << " " << lastname_rus << endl;
                }
                else
                {
                    nmale_rus = get_random_line("data\\rus_name_male.txt");
                    lastname_rus = get_random_line("data\\rus_lastname.txt");
                    cout << ": " << nmale_rus << " " << lastname_rus << endl;
                }
            }
            else
            {
                if (is_female)
                {
                    nmale_eng = get_random_line("data\\eng_name_female.txt");
                    lastname_eng = get_random_line("data\\eng_lastname.txt");
                    cout << ": " << nmale_eng << " " << lastname_eng << endl;
                }
                else
                {
                    nmale_eng = get_random_line("data\\eng_name_male.txt");
                    lastname_eng = get_random_line("data\\eng_lastname.txt");
                    cout << ": " << nmale_eng << " " << lastname_eng << endl;
                }
            }

            cout << endl;
            cout << "Перегенерировать? (y/n/restart): " << endl;
            cin >> repeat;

            if (repeat == 'restart')
            {
                break;
            }
            else if (repeat == 'n' || repeat == 'N')
            {
                cout << "Aborting..." << endl;
                return 0;
            }

        } while (repeat == 'y' || repeat == 'Y');

    } while (repeat != 'n' && repeat != 'N');
}
