//ЗАВДАННЯ 1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "audiere.h"

using namespace audiere;
using namespace std;

struct Data {
    int day;
    string month;
    int year;
};

struct Man {
    string surname;
    string name;
    int age;
    Data birth;
};

void zapis(vector<Man>& arr) {
    cout << "\nІнформація про людей:\n";
    for (Man lines : arr) {
        cout << "Прізвище: " << lines.surname<<endl;
        cout << "Ім'я: " << lines.name<<endl;
        cout << "Вік: " << lines.age<<endl;
        cout << "Дата народження: " << lines.birth.day << " " << lines.birth.month << " " << lines.birth.year<<endl;
        cout << endl;
    }
}

void Diyi(vector<Man>& dt) {
    cout << "-----Дата меню-----\n\n[1] Редагування\n[2] Видалення\n[3] Додавання\n\n";
    int choice = 0;
    cin >> choice;
    switch (choice) {
    case 1: {
        cout << "Номер запису\n> ";
        int nomer = 0;
        cin >> nomer;
        nomer--;
        if (nomer<0 || nomer>dt.size()) {
            cout << "Такого запису немає!";
        }
        else {
            Man i;
            cout << "\nВведіть нові данні для редагування\n";
            cout << "\nПрізвище: ";
            cin >> i.surname;
            cout << "\nІм'я: ";
            cin >> i.name;
            cout << "Вік: ";
            cin >> i.age;
            cout << "Дата народження: ";
            cin >> i.birth.day >> i.birth.month >> i.birth.year;
            dt[nomer] = i;
        }
        cout << "\033[H\033[2J";
        cout << "\nДані успішно замінені!\n";
        break;
    }
    case 2: {
        cout << "Номер запису\n> ";
        int nomer1 = 0;
        cin >> nomer1;
        nomer1--;
        if (nomer1<0 || nomer1>dt.size()) {
            cout << "Такого запису немає!";
        }
        else {
            dt.erase(dt.begin() + nomer1);
            cout << "\nЗапис успішно видален\n";
        }
        break;
    }
    case 3: {
        Man i;
        cout << "\nВведіть данні для додавання\n";
        cout << "\nПрізвище: ";
        cin >> i.surname;
        cout << "\nІм'я: ";
        cin >> i.name;
        cout << "Вік: ";
        cin >> i.age;
        cout << "Дата народження: ";
        cin >> i.birth.day >> i.birth.month >> i.birth.year;
        dt.push_back(i);

        cout << "\033[H\033[2J";
        cout << "\nДані збережені!\n";
        break;
    }
    
    }
}

bool sortS(Man& s1, Man& s2) {
    return s1.surname<s2.surname;
}

bool sortN(Man& s1, Man& s2) {
    return s1.name < s2.name;
}

void sortR(vector<Man>& arr) {
    int choice;
    cout << "\nСортування\n[1] Прізвище\n[2] Ім'я\n> ";
    cin >> choice;
    switch (choice) {
    case 1:
        sort(arr.begin(), arr.end(), sortS);
        cout << "Сортування за прізвищем відбулося. Перевірити пункт [1].";
        break;
    case 2:
        sort(arr.begin(), arr.end(), sortN);
        cout << "Сортування за ім'ям відбулося. Перевірити пункт [1].";
        break;
    }
}

void poshuk(vector <Man>& arr) {
    cout << "\nПошук\nЗа прізвищем\n";
    bool found = false;
    string surN;
    cout << "Введіть прізвище: ";
    cin >> surN;
    int roz = arr.size();
    for (int i = 0; i < roz; i++) {
        if (arr[i].surname == surN) {
            cout << "\n--- Знайдено запис ---\n";
            cout << "Прізвище: " << arr[i].surname << endl;
            cout << "Ім'я: " << arr[i].name << endl;
            cout << "Вік: " << arr[i].age << endl;
            cout << "Дата народження: "
                << arr[i].birth.day << " "<< arr[i].birth.month <<" " << arr[i].birth.year << endl;
            found = true;
        }
    }
    if (!found) cout << "Не знайдено з таким прізвищем!\n";
}


int main()
{
    system("chcp 1251>null");

    AudioDevicePtr device = OpenDevice();
    OutputStreamPtr sound = OpenSound(device, "gamekost.wav", false);
    OutputStreamPtr restart = OpenSound(device, "restart.wav", false);
    OutputStreamPtr menu = OpenSound(device, "menu.wav", false);

    vector<Man> arr{
        {"Петров", "Петро", 24, {12, "вересень", 2001}},
        { "Кравчук", "Оксана", 45, {9, "березень", 1980}},
        { "Мильник", "Алекс", 21, {8, "жовтень", 2007}}
    };

    int choice;
    
    do {
        sound->play();
        cout << "\nМеню програми\n[1] Вивести інформацію\n[2] Дії з записом\n[3] Сортування записів\n[4] Пошук\n[5]Виведення іменниників\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        switch (choice) {
        case 1: zapis(arr); restart->play(); break;
        case 2: Diyi(arr); break;
        case 3: sortR(arr);  menu->play(); break;
        case 4: poshuk(arr);  break;
        case 5:break;
        default: cout << "Програму завершено"; break;
        }
    } while (choice >= 1 && choice <=5);

    return 0;
}




//ЗАВДАННЯ 2

//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <conio.h>
//#include "audiere.h"
//
//using namespace std;
//const int a = 10;
//
//void Again(char arr[a][a], int live) {
//    cout << "\033[H\033[2J";
//    for (int i = 0; i < a; i++) {
//        for (int j = 0; j < a; j++) {
//            cout << arr[i][j] << ' ';
//        }
//        cout << endl;
//    }
//    cout << "\nЖиття: " << live << endl;
//}
//
//void Move(char arr[a][a], int* x, int* y, char key, bool* gra, int* live) {
//    int x2 = *x, y2 = *y;
//    switch (key) {
//    case 'W': case 'w': x2--; break;
//    case 'S': case 's': x2++; break;
//    case 'D': case 'd': y2++; break;
//    case 'A': case 'a': y2--; break;
//    default: return;
//    }
//    if (x2 >= 0 && x2 < a && y2>=0 && y2<a && arr[x2][y2]!='#') {
//        if (arr[x2][y2] == '!') {
//            (*live)--;
//            if (*live <= 0) {
//                *gra = false;
//                return;
//            }
//        }
//        
//        if (arr[x2][y2] == 'X') {
//            arr[*x][*y] = ' ';
//            *x = x2;
//            *y = y2;
//            arr[*x][*y] = 'P';
//            *gra = false;
//            return;
//        }
//        arr[*x][*y] = ' ';
//        *x = x2;
//        *y = y2;
//        arr[*x][*y] = 'P';
//    }
//    //умова
//}
//
//void randPaskta(char arr[a][a], int pastkaCount) {
//    for (int i = 0; i < pastkaCount; i++) {
//        int x, y;
//        do {
//            x = rand() % a;
//            y = rand() % a;
//        } while (arr[x][y] != ' ');
//        arr[x][y] = '!';
//    }
//    int x1, y2;
//
//    do {
//        x1 = rand() % a;
//        y2 = rand() % a;
//    } while (arr[x1][y2] != ' ');
//    arr[x1][y2] = 'X';
//}
//
//
//int main() {
//	system("chcp 1251>null");
//
//	srand(time(0));
//
//	char arr[a][a]{
//       {'#','#','#','#','#','#','#','#','#','#'},
//       {'#','P',' ',' ','#',' ',' ',' ',' ','#'},
//       {'#',' ','#',' ','#',' ','#','#',' ','#'},
//       {'#',' ','#',' ',' ',' ',' ','#',' ','#'},
//       {'#',' ','#','#','#','#',' ','#',' ','#'},
//       {'#',' ',' ',' ',' ','#',' ','#',' ','#'},
//       {'#',' ','#','#',' ','#',' ','#',' ','#'},
//       {'#',' ','#',' ',' ',' ',' ',' ',' ','#'},
//       {'#',' ',' ',' ','#','#',' ',' ',' ','#'},
//       {'#','#','#','#','#','#','#','#','#','#'}
//	};
//
//    int x=1, y=1;
//    int live = 3;
//    bool gra = true;
//
//    randPaskta(arr, 5);
//    Again(arr, live);
//    while (gra) {
//        char key = _getch();
//        Move(arr, &x, &y, key, &gra, &live);
//        Again(arr, live);
//    }
//    if (live == 0) {
//        cout << "Ви загинули\n";
//    }
//    if (live > 0) {
//        cout << "Ви перемогли!\n";
//    }
//    cout << "GAME OVER";
//
//	return 0;
//}